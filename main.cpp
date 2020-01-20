#include <iostream>
#include <stdio.h>
//#include <conio.h>
#include <curses.h>

int main() {
    int n, i, j, k;
    int magico[20] [20]= {0};
    printf("Cuadro magico de orden: \n");
    scanf("%d", &n);
    for (i = 0; i<=n-1; i++) {
        printf("\n");
        for ( j= 0;  j<=n-1; j++)
            printf("%3d", magico [i][j]);
    }
    getch();
    //Aplicamos algoritmo
    j=(n-1)/2; //Columna central
    i=n-1; //Ultimo renglon
    for (k= 1; k<=n * n; k++) //Sembramos valor por valor
    {
        magico[i][j] = k;
        i++;
        j++;
        if (i == n)
            i = 0; //si desborda en renglon, se coloca en el primer renglon
        if (j == n)
            j = 0; //si desborda en renglon, se coloca en la primea columna
        if (magico[i][j] > 0) //si esta ocupada la casilla
        { //se disminuye renglon en 2 y columna en uno
            i -= 2;
            j --;
        }
        if (i < 0) //caso especial cuando se vuelven indices negativos
        {
            i=n-2;
            j=n-1;

        }
    }
    printf("\n Cuadro Magico \n");
    for (i=0; i<=n-1; i ++) {
        printf(".\n");
        for(j=0; j<=n-1; j ++)
            printf("%3d", magico[i][j]);
    }
    getch();
    return 0;
}