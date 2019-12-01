#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define LIN 9
#define COL 9

int main()
{

    int **mat ;
    int i, j ;

    int dado;
    FILE *fp;

    fp = fopen ("tabela.txt", "r+");
    mat = ( int ** ) malloc (LIN * sizeof (int*)) ;
    for (i=0; i < LIN; i++)
    mat[i] = ( int * ) malloc (COL * sizeof (int)) ;
    for (i=0; i < LIN; i++)
    {
        for (j=0; j < COL; j++)
        {
        dado = fgetc(fp);        
        mat[i][j] = dado ;
        }
    }

    printf("\nMatriz:\n");
    for(i=0;i<LIN;i++)
    {
        
       for(j=0;j<COL;j++)
       {
           if ( mat[i][j] == 10 )
           {
               printf("\n");
           }
           else
           {
               /* code */
               printf("%3d\t", mat[i][j]-48);
           }
       }
    }

    // libera a memória da matriz
    for (i=0; i < LIN; i++)
       free (mat[i]) ;
    free (mat) ;

}
 