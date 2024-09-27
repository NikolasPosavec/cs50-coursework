#include <cs50.h>
#include <stdio.h>

void LPyr(int i, int n);
void RPyr(int i);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height of pyramid (1-8): ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        LPyr(i, n);
    }
}

void LPyr(int i, int n)
{
    for (int j = 0; j < n - i; j++)
    {
        printf(" ");
    }
    for (int j = 0; j < i; j++)
    {
        printf("#");
    }

    printf("  ");

    RPyr(i);

    printf("\n");
}

void RPyr(int i)
{
    for (int j = 0; j < i; j++)
    {
        printf("#");
    }
}
