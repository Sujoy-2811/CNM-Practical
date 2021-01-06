#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int fact(int);
int main()
{
    float arr[10][11], x, h, p, y = 0, px = 1;
    int i, j, n, ch = 30;
    printf("\nEnter the number of data:");
    scanf("%d", &n);
    printf("\nEnter the data");
    for (i = 0; i < n; i++)
    {
        printf("\nX%d=", i + 1);
        scanf("%f", &arr[i][0]);
        printf("Y%d=", i + 1);
        scanf("%f", &arr[i][1]);
    }
    int nCount = 0;
    for (int j = 2; j <= n; j++)
    {
        int i = 0;
        for (; i <= n; i++)
        {
            arr[i][j] = (arr[i + 1][j - 1] - arr[i][j - 1]) / (arr[i + 1 + nCount][0] - arr[i][0]);
        }
        nCount++;
        i++;
    }

    //Printing table
    printf("\nDifference table is:-");
    printf("\n\tx\tY");
    for (i = 0; i < n - 1; i++)
        printf("\tY^%dY", i + 1);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n + 1 - i; j++)
        {
            printf("\t%.2f", arr[i][j]);
        }
        printf("\n");
    }

    //Take the value of x for f(x)
    printf("\nEnter the value x for function f(x):");
    scanf("%f", &x);
    //Calculate the value of f(x) for x
    y = arr[0][1];
    p = x - arr[0][0];

    for (i = 1; i < n; i++)
    {
        px = arr[0][i + 1] * p;
        y += px;
        p *= x - arr[i][0];
    }
    printf("\nthe value of function at x=%.3f is %.3f", x, y);
    return 0;
}
