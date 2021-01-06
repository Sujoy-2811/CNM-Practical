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

    for (int j = 2; j <= n; j++)
    {
        int i = 1;
        for (; i <= n; i++)
        {
            arr[i][j] = arr[i][j - 1] - arr[i - 1][j - 1];
        }
        i++;
    }

    //Printing table
    printf("\nDifference table is:-");
    printf("\n\tx\tY");
    for (i = 0; i < n - 1; i++)
        printf("\tY^%dY", i + 1);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 2; j++)
        {
            printf("\t%0.3f", arr[i][j]);
        }
        printf("\n");
    }

    //Take the value of x for f(x)
    printf("\nEnter the value x for function f(x):");
    scanf("%f", &x);
    //Calculate the value of f(x) for x
    h = arr[1][0] - arr[0][0];
    h = fabs(h);
    p = (x - arr[n - 1][0]) / h;
    y = arr[n - 1][1];
    for (i = 1; i < n; i++)
    {
        px = px * (p + (i - 1));
        y += (arr[n - 1][i + 1] * px) / fact(i);
    }
    printf("\nthe value of function at x=%.3f is %.3f", x, y);
    return 0;
}
int fact(int n)
{
    int i, f = 1;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}
