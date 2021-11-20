#include <stdio.h>
#include "my_mat.h"
#include <math.h>

int main()
{
    int mat[3][3]="";
    char choise='-1';
    switch (choise)
    {
    case 'A':
        build_mat(*mat);
        break;
    
    case 'B':
        break;
    case 'C':
        break;
    case 'D':
        break;
    }


    return 0;
}