#include <stdio.h>
#include <conio.h>
#include <math.h>

double function(double y, float x, int coeff[], int deg)
{
    for (int i = deg; i >= 0; i--)
    {
        y += coeff[i] * pow(x, i);
    }
    return y;
}

int main()
{
    double y[20] = {0};
    float x[20], xn, x0, h, odd = 0, even = 0;
    int i, intervals, coeff[20] = {0}, deg;

    //Modication
    printf("\n\n  Enter the Highest Order: ");
    scanf("%d", &deg);

    //take eqn
    for (i = deg; i >= 0; i--)
    {
        printf("  Enter Coeffecient of x%d: ", i);
        scanf("%d", &coeff[i]);
    }

    //print eqn
    printf("Given eqn is : ");
    for (int i = deg; i > 0; i--)
    {
        if (coeff[i] != 0)
            printf("%dX^%d + ", coeff[i], i);
    }

    printf("%d\n", coeff[0]);
    printf("\n");

    //taking n, a,b
    printf("Enter the number of intervals:");
    scanf("%d", &intervals);
    printf("Enter the value of x0:");
    scanf("%f", &x0);
    printf("Enter the value of xn:");
    scanf("%f", &xn);
    h = ((xn - x0) / intervals);
    printf("h=%f\n", h);
    x[0] = x0;
    for (i = 1; i <= intervals; i++)
    {
        x[i] = x[i - 1] + h;
    }
    //calculating values of fx
    for (int i = 0; i <= intervals; i++)
    {
        //(double y, float x, float coeff[], int deg)
        y[i] = function(y[i], x[i], coeff, deg);
    }

    //printing table
    printf("Table is:\n\n");
    printf("    X           Y\n");
    for (i = 0; i <= intervals; i++)
    {
        printf("%f     %f\n", x[i], y[i]);
    }
    h = h / 3;
    for (i = 1; i < intervals; i++)
    {
        if (i % 2 != 0)
        {
            even += y[i] * 2;
        }
        else
        {
            odd += y[i] * 4;
        }
    }
    printf("\n\nAnswer is: %f", (h * (y[0] + y[intervals] + odd + even)));
    getch();
    return 0;
}
