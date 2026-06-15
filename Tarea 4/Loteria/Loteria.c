#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    int cantidad_jugadas = 0;
    int numeros[40];
    float apuesta[40];
    int numero_premiado;
    int hubo_ganador;
    int semilla = 25;
    int i;

    do
    {
        semilla = semilla + 5;

        printf("\n===== LOTERIA =====\n");
        printf("1. Jugar\n");
        printf("2. Elegir cantidad de jugadas\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                if(cantidad_jugadas > 0)
                {
                    printf("\n--- INGRESO DE JUGADAS ---\n");

                    for(i = 0; i < cantidad_jugadas; i++)
                    {
                        printf("\nJugada %d\n", i + 1);

                        do
                        {
                            printf("Ingrese un numero (1-40): ");
                            scanf("%d", &numeros[i]);

                            if(numeros[i] < 1 || numeros[i] > 40)
                            {
                                printf("Numero invalido.\n");
                            }

                        }
                        while(numeros[i] < 1 || numeros[i] > 40);

                        do
                        {
                            printf("Cantidad apostada: ");
                            scanf("%f", &apuesta[i]);

                            if(apuesta[i] <= 0)
                            {
                                printf("La apuesta debe ser mayor que cero.\n");
                            }

                        }
                        while(apuesta[i] <= 0);

                        semilla = semilla + numeros[i];
                    }

                    numero_premiado = (semilla % 40) + 1;

                    printf("\n========================");
                    printf("\nNumero ganador: %d", numero_premiado);
                    printf("\n========================\n");

                    hubo_ganador = 0;

                    for(i = 0; i < cantidad_jugadas; i++)
                    {
                        if(numeros[i] == numero_premiado)
                        {
                            printf("\nFelicidades.\n");
                            printf("Jugada ganadora: %d\n", i + 1);
                            printf("Numero jugado: %d\n", numeros[i]);
                            printf("Dinero apostado: %.2f\n", apuesta[i]);
                            printf("Premio ganado: %.2f\n", apuesta[i] * 1000);

                            hubo_ganador = 1;
                        }
                    }

                    if(hubo_ganador == 0)
                    {
                        printf("\nNo hubo jugadas ganadoras.\n");
                    }
                }
                else
                {
                    printf("\nPrimero debe elegir la cantidad de jugadas.\n");
                }

                break;

            case 2:

                do
                {
                    printf("\nCantidad de jugadas (1-40): ");
                    scanf("%d", &cantidad_jugadas);

                    if(cantidad_jugadas < 1 || cantidad_jugadas > 40)
                    {
                        printf("Cantidad no permitida.\n");
                    }

                }
                while(cantidad_jugadas < 1 || cantidad_jugadas > 40);

                printf("Se registraron %d jugadas.\n", cantidad_jugadas);

                break;

            case 3:

                printf("\nGracias por jugar.\n");

                break;

            default:

                printf("\nOpcion incorrecta.\n");
        }

    }
    while(opcion != 3);

    return 0;
}