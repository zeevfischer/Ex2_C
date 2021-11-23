#include <stdio.h>
#include "my_mat.h"
#include <math.h>
#include <stdbool.h>

int main()
{  
    int mat[10][10]={};
    char choise;
    int i;
    int j;
    while(choise != 'D')
    {
        scanf("%c",&choise);
        switch (choise)
        {
            case 'A':
                build_mat(*mat);
                break;
            case 'B':
                scanf("%d%d",&i,&j);
                bool ans = is_path(*mat,i,j);
                printf(ans ? "True\n" : "False\n");
                break;
            case 'C':
                scanf("%d%d",&i,&j);
                int C =length(*mat,i,j);
                printf("%d\n",C);
                break;
            case 'D':
                break;
        }
    }
}