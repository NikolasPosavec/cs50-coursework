#include <stdio.h>
#include <cs50.h>
#include <string.h>

char* card_type(long num);
bool luhns(long num);

int main(void)
{
    long Number = get_long("Number: ");
    char str[20];
    sprintf(str, "%ld", Number);

    bool checker = luhns(Number);
    if (checker == true)
    {
        char* type = card_type(Number);
        printf("%s\n", type);
    }
    else
    {
        printf("INVALID\n");
    }
}

char* card_type(long num)
{
    char str[20];
    sprintf(str, "%ld", num);

    if (str[0] == '4')
    {
        if (strlen(str) == 13 || strlen(str) == 16)
            return "VISA";
    }
    else if (str[0] == '3' && (str[1] == '4' || str[1] == '7'))
    {
        if (strlen(str) == 15)
            return "AMEX";
    }
    else if (str[0] == '5' && (str[1] >= '1' && str[1] <= '5'))
    {
        if (strlen(str) == 16)
            return "MASTERCARD";
    }

    return "INVALID";
}

bool luhns(long num)
{
    char str[20];
    sprintf(str, "%ld", num);
    int length = strlen(str);
    int sum = 0;

    for (int i = length - 2; i >= 0; i -= 2)
    {
        int digit = (str[i] - '0') * 2;
        if (digit > 9)
        {
            sum += digit / 10 + digit % 10;
        }
        else
        {
            sum += digit;
        }
    }

    for (int i = length - 1; i >= 0; i -= 2)
    {
        sum += str[i] - '0';
    }

    return (sum % 10 == 0);
}
