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
    fp = fopen("alumnos.xml","r");

    if(fp==NULL)
    {
        printf("\nError al abrir alumnos.xml\n");
        return 1;
    }

    char buffer[5000] = "";
    size_t bytesLeidos = fread(buffer,1,sizeof(buffer)-1,fp);
    buffer[bytesLeidos]='\0';
    fclose(fp);

    int cantidad=0;
    char *ptr=buffer;

    while ((ptr = strstr(ptr, "<Alumno>")) !=NULL)
    {
        cantidad++;
        ptr += strlen("<Alumno>");
    }

    printf("Cantidad de alumnos: %d\n", cantidad);

    Alumno *alumnos = malloc(cantidad * sizeof(Alumno));
    if (alumnos == NULL)
    {
        printf("\nError al asignar memoria.\n");
    return 1;
    }
ptr = buffer;
for (int i = 0; i < cantidad; i++)
{
    ptr = strstr(ptr, "<Alumno>");
    if (ptr == NULL) break;

    char *inicio;
    char *fin;
    char temp[50];

    inicio = strstr(ptr, "<Nombre>") + 8;
    fin = strstr(inicio, "</Nombre>");
    strncpy(alumnos[i].nombre, inicio, fin - inicio);
    alumnos[i].nombre[fin - inicio] = '\0';

    inicio = strstr(ptr, "<Apellido>") + 10;
    fin = strstr(inicio, "</Apellido>");
    strncpy(alumnos[i].apellido, inicio, fin - inicio);
    alumnos[i].apellido[fin - inicio] = '\0';

    inicio = strstr(ptr, "<Promedio>") + 10;
    fin = strstr(inicio, "</Promedio>");
    strncpy(temp, inicio, fin - inicio);
    temp[fin - inicio] = '\0';
    alumnos[i].promedio = atof(temp);

    inicio = strstr(ptr, "<Materia>") + 9;
    fin = strstr(inicio, "</Materia>");
    strncpy(alumnos[i].materia, inicio, fin - inicio);
    alumnos[i].materia[fin - inicio] = '\0';

    ptr = fin;
}

printf("\n--- DATOS CARGADOS EN MEMORIA (XML) ---\n");
for (int i = 0; i < cantidad; i++)
{
    printf("Alumno %d: %s %s | Promedio: %.2f | Materia: %s\n", i + 1, alumnos[i].nombre, alumnos[i].apellido, alumnos[i].promedio, alumnos[i].materia);
}

free(alumnos);
return 0;
}