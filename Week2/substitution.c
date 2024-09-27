#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int checkKey(string key);
void cipherText(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("More than one command-line argument\n");
        return 1;
    }
    string key = argv[1];
    if (checkKey(key))
    {
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    cipherText(plaintext, key);
    return 0;
}
int checkKey(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must be 26 characters\n");
        return 1;
    }

    int used[26];
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetical\n");
            return 1;
        }
        char c = tolower(key[i]);
        if (used[c - 'a'])
        {
            printf("Repeated characters are not allowed\n");
            return 1;
        }
        used[c - 'a'] = 1;
    }
    return 0;
}

void cipherText(string plaintext, string key)
{
    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            char Case = isupper(c) ? 'A' : 'a';
            int index = tolower(c) - 'a';
            char processed = isupper(c) ? toupper(key[index]) : tolower(key[index]);
            printf("%c", processed);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
