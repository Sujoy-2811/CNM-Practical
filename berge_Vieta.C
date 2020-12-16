#include <stdio.h>
#include <conio.h>

void iteration(double x[], double p, int k, char ch)
{
    int j = 0;
    printf("\n\n\t   p0");
    for (j = 0; j <= k; j++)
        printf("\t\t   %c%d ", ch, j);
    printf("\n\t%lf", p);
    for (j = k; j >= 0; j--)
        printf("\t%lf", x[j]);
}
void iteration1(double x[], double xy[], double y[], double p, int k)
{
    int j = 0;
    printf("\n\t\t\t\t");
    for (j = k - 1; j >= 0; j--)
    {
        xy[j] = y[j + 1] * (p);
        printf("\t%lf", xy[j]);
        y[j] = xy[j] + x[j];
    }
}

int main()
{
    void iteration(double *, double, int, char), iteration1(double *, double *, double *, double, int);
    char chr;
    int deg, itr = 0, maxitr, i;
    double a[10], ab[10], b[10], bc[10], c[10], p0, p1;
    {
        printf("\n----------------------------------------------------------  Berge Vieta  -----------------------------------------------------------");
        printf("\n\n  Enter the Highest Order: ");
        scanf("%d", &deg);
        printf("\n");

        for (i = deg; i >= 0; i--)
        {
            printf("  Enter Coeffecient of x%d: ", i);
            scanf("%lf", &a[i]);
        }
        printf("\n  Enter p0: ");
        scanf("%lf", &p0);
        printf("\n  Enter the Maximum No. of Iterations: ");
        scanf("%d", &maxitr);
    }
    //Input
    {
        b[deg] = a[deg];
        c[deg] = a[deg];
        for (i = 0; i < maxitr; i++)
        {
            itr++;
            printf("\n\n   %d SYNTHETIC ITERATION", itr);
            chr = 'a';
            iteration(a, p0, deg, chr);
            iteration1(a, ab, b, p0, deg);
            chr = 'b';
            iteration(b, p0, deg, chr);
            iteration1(b, bc, c, p0, deg);
            chr = 'c';
            iteration(c, p0, deg, chr);

            p1 = p0 - (b[0] / c[1]);
            printf("\n\n\tp%d=%lf ", itr, p1);

            if (p1 == p0)
                break;
            p0 = p1;
        }
    }
    //Berge Vieta

    printf("\n\n  Root Calculated is %lf in %d iterations.", p1, itr);
    printf("\n\n\n");
    return 0;
}