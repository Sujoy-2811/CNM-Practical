#include <stdio.h>
#include <conio.h>

void decimalToBinary(int n)
{
    int bits[32];

    int i = 0;
    while (n > 0)
    {

        bits[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%d", bits[j]);
}

int main()
{
    int a;
    printf("Enter any number : ");
    scanf("%d", &a);
    printf("\nNumber in binary : ");
    decimalToBinary(a);
    getch();
    return 0;
}