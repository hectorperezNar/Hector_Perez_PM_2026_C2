#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    char apellido[50];
    float promedio;
    char materia[50];
} Alumno;

int main()
{
    FILE *fp;
    fp = fopen("alumnos.csv", "r");

    if(fp == NULL)
    {
        printf("Error al abrir alumnos.csv\n");
        return 1;
    }

    char buffer[5000] = "";
    size_t bytesLeidos = fread(buffer, 1, sizeof(buffer)-1, fp);
    buffer[bytesLeidos] = '\0';
    fclose(fp);

    int cantidad = 0;
    char *ptr = buffer;

    while((ptr = strchr(ptr, '\n')) != NULL)
    {
        cantidad++;
        ptr++;
    }

    printf("Cantidad de alumnos: %d\n", cantidad);
    Alumno *alumnos = malloc(cantidad * sizeof(Alumno));

    if(alumnos == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    ptr = buffer;
    ptr = strchr(ptr, '\n') + 1; 

    for(int i = 0; i < cantidad - 1; i++)
    {
        char *inicio;
        char *fin;
        char temp[50];
        if(ptr == NULL || *ptr == '\0') break;

        inicio = ptr;
        fin = strchr(inicio, ',');
        strncpy(alumnos[i].nombre, inicio, fin - inicio);
        alumnos[i].nombre[fin - inicio] = '\0';

        inicio = fin + 1;
        fin = strchr(inicio, ',');
        strncpy(alumnos[i].apellido, inicio, fin - inicio);
        alumnos[i].apellido[fin - inicio] = '\0';

        inicio = fin + 1;
        fin = strchr(inicio, ',');
        strncpy(temp, inicio, fin - inicio);
        temp[fin - inicio] = '\0';
        alumnos[i].promedio = atof(temp);

        inicio = fin + 1;
        fin = strchr(inicio, '\n');
        if(fin == NULL) fin = inicio + strlen(inicio); 

        strncpy(alumnos[i].materia, inicio, fin - inicio);
        alumnos[i].materia[fin - inicio] = '\0';

        char *retorno = strchr(alumnos[i].materia, '\r');
        if(retorno != NULL) *retorno = '\0';
        ptr = fin + 1;
    }

    printf("\n----- DATOS CARGADOS (CSV) -----\n");

    for(int i = 0; i < cantidad - 1; i++)
    {
        printf("Alumno %d\n", i + 1);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Apellido: %s\n", alumnos[i].apellido);
        printf("Promedio: %.2f\n", alumnos[i].promedio);
        printf("Materia: %s\n\n", alumnos[i].materia);
    }

    free(alumnos);

    return 0;
}