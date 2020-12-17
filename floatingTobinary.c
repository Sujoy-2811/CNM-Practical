#include <stdio.h>
#include <conio.h>
#include <math.h>

float input, fraction, i = 0;
int num, frac[8] = {0}, bits[23] = {0};

int decimalToBinary(int n)
{
    // int bits[32];

    int i = 0;
    while (n > 0)
    {

        bits[i] = n % 2;
        n = n / 2;
        i++;
    }
    int count = 0;
    for (int j = 0; j < 23 - i; j++)
        printf("0");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", bits[j]);
        count++;
        if (count == 23)
            return 0;
    }
    return 0;
}

int fractionToBinary()
{
    int mDec;
    float mFloat, mNum;
    int i = 0;
    while (fraction > 0)
    {
        fraction *= 2;
        mDec = fraction;
        frac[i] = mDec;
        i++;
        fraction -= mDec;
        if (i == 8)
            goto next;
    }

next:
    printf("");
    int remainDigit = 8 - i;
    // int count = 0;
    for (int j = 0; j < i; j++)
    {
        printf("%d", frac[j]);
        // count++;
        // if (count == 8)
        //     return 0;
    }
    // for (int j = 0; j < remainDigit; j++)
    //     printf("0");
    return 0;
}

int main()
{
    printf("Enter positive floating number : ");
    scanf("%f", &input);
    input = fabs(input);
    num = input;
    fraction = input - num;
    printf("Number in binary : ");
    decimalToBinary(num);

    printf(".");
    fractionToBinary();
    getch();
    return 0;
}
