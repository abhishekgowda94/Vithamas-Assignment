#include <stdio.h>

void int_To_Roman(int num)
{
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            printf("%s", symbols[i]);
            num -= values[i];
        }
    }
    printf("\n");
}

int main()
{
    int num;
    printf("Enter any integer number: ");
    scanf("%d", &num);

    if (num > 0 && num <= 3999)
    {
        printf("Roman number is: ");
        int_To_Roman(num);
    }
    else
    {
        printf("Invalid number! Please enter a number between 1 and 3999.\n");
    }

    return 0;
}
