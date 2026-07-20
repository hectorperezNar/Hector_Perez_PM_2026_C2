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
    fp = fopen("alumnos.json", "r");

    if(fp == NULL)
    {
        printf("Error al abrir alumnos.json\n");
        return 1;
    }

    char buffer[5000] = "";
    size_t bytesLeidos = fread(buffer, 1, sizeof(buffer)-1, fp);
    buffer[bytesLeidos] = '\0';
    fclose(fp);

    int cantidad = 0;
    char *ptr = buffer;

    while((ptr = strstr(ptr, "\"Nombre\"")) != NULL)
    {
        cantidad++;
        ptr += strlen("\"Nombre\"");
    }

    printf("Cantidad de alumnos: %d\n", cantidad);
    Alumno *alumnos = malloc(cantidad * sizeof(Alumno));

    if(alumnos == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    ptr = buffer;

    for(int i = 0; i < cantidad; i++)
    {
        char *inicio;
        char *fin;
        char temp[50];

        ptr = strstr(ptr, "\"Nombre\"");
        if(ptr == NULL)
            break;

        inicio = strchr(ptr, ':') + 3;
        fin = strchr(inicio, '"');
        strncpy(alumnos[i].nombre, inicio, fin - inicio);
        alumnos[i].nombre[fin - inicio] = '\0';

        ptr = strstr(fin, "\"Apellido\"");
        inicio = strchr(ptr, ':') + 3;
        fin = strchr(inicio, '"');
        strncpy(alumnos[i].apellido, inicio, fin - inicio);
        alumnos[i].apellido[fin - inicio] = '\0';

        ptr = strstr(fin, "\"Promedio\"");
        inicio = strchr(ptr, ':') + 2;
        fin = strchr(inicio, ',');
        if(fin == NULL)
            fin = strchr(inicio, '\n');

        strncpy(temp, inicio, fin - inicio);
        temp[fin - inicio] = '\0';
        alumnos[i].promedio = atof(temp);

        ptr = strstr(fin, "\"Materia\"");
        inicio = strchr(ptr, ':') + 3;
        fin = strchr(inicio, '"');
        strncpy(alumnos[i].materia, inicio, fin - inicio);
        alumnos[i].materia[fin - inicio] = '\0';

        ptr = fin;
    }

    printf("\n----- DATOS CARGADOS (JSON) -----\n");

    for(int i = 0; i < cantidad; i++)
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