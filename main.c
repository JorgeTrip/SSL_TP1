#include <stdio.h>
#include <stdlib.h>

#define CANTIDADDETERMINALES 24
#define CANTIDADDEESTADOS 7

int getPosicion(char *elementos, int cantidadDeElementos, char elemento)
{
    int posicion = -1;
    for (int i = 0; i < cantidadDeElementos; i++)
    {
        if (elementos[i] == elemento)
            return i;
    }
    return -1;
}

int main(void)
{

    // Defino vector auxiliar de terminales
    char terminales[CANTIDADDETERMINALES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'x', 'X', 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};

    // Cargo la tabla de transición
    int tabla[CANTIDADDEESTADOS][CANTIDADDETERMINALES];

    FILE *file;
    file = fopen("tablaDeTransicion.txt", "r");

    for (int i = 0; i < CANTIDADDEESTADOS && !feof(file); i++)
        for (int j = 0; j < CANTIDADDETERMINALES && !feof(file); j++)
            fscanf(file, "%d", &tabla[i][j]);

    fclose(file);


    return 0;
}