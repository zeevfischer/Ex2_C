#include <stdio.h>
#include "my_mat.h"
#include <math.h>
#include <stdbool.h>
void print(int *p)
{
    for(int i =0; i < 10;i++)
    {
        for(int j =0; j < 10;j++)
        {
            printf("%d ",*p);
            p++;
        }
        printf("\n");
    }
    printf("\n");
}
// A
void build_mat(int *p)
{   
    int temp;
    for(int i = 0; i < 100; i++)
    {
        scanf("%d",&temp);
        *p = temp;
        p++;
    }
}
// help B
void swap(int *p1,int *p2)
{
    int temp;
    int save;
    for(int i=0; i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            save = *p2;
            temp = *p1;
            *p2 = temp;
            *p1 = save;
            p1++;
            p2++;
        }
    }

}
// help B
void copy(int *p1,int *p2)
{
    // int temp;
    for(int i=0; i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            // temp = *p1;
            // *p2 = temp;
            *p2 = *p1;
            p1++;
            p2++;
        }
    }
}
// help to B C
int calk(int *p,int i1, int j1)
{
    int calk1;
    int calk2;
    int calk3;

    int A0[10][10]={};
    int A1[10][10]={};
    copy(p,*A0);
    for(int x = 0; x < 10; x++)
    {
        for(int i = 0; i < 10 ; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(i == x || j == x)
                {
                    A1[i][j]=A0[i][j];
                }
                else if(i == j)
                {
                    A1[i][j]=0;
                }
                else
                {
                    calk1=A0[i][j];

                    calk2=A0[i][x];
                    calk3=A0[x][j];

                    if(calk3 == 0 || calk2 == 0)
                    {
                        A1[i][j]=calk1;
                    }
                    if(calk1 == 0 && calk3 !=0 && calk2 != 0)
                    {
                        A1[i][j]=calk2+calk3;
                    }
                    if(calk1 != 0 && calk3 !=0 && calk2 != 0)
                    {
                        A1[i][j]=fmin(calk1,(calk2+calk3));
                    }
                    if(calk1 == 0 && calk3 ==0 && calk2 == 0)
                    {
                        A1[i][j]=0;
                    }
                }
            }
        }
        // print(*A0);
        // print(*A1);
        swap(*A0,*A1);
        // print(*A0);
        // print(*A1);
    }
    // at the end my final one will be A0
    return A0[i1][j1];
}
// B
bool is_path(int *p,int i1, int j1)
{
    int result=calk(p,i1,j1);
    if(result != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// C
int length(int *p,int i1, int j1)
{
    int result=calk(p,i1,j1);
    if(result != 0)
    {
        return result;
    }
    else
    {
        return -1;
    }
}
