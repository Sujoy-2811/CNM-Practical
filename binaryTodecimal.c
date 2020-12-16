#include <stdio.h>
#include <math.h>
#include <conio.h>

int decimal = 0;

void binarToDecimal(int n)
{
    int base = 2, place = 0, rem, current;
    while (n != 0)
    {
        rem = n % base;
        n /= 10;
        decimal += rem * pow(base, place);
        place++;
    }
}

int main()
{
    int a;
    printf("Enter binary number : ");
    scanf("%d", &a);
    binarToDecimal(a);
    printf("\nNumber in decimal : %d", decimal);
    getch();
    return 0;
}
