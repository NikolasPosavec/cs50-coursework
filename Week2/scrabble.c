#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string checkIs(string p1I, string p2I);
void toUpper(string s);

int main(void)
{
    string p1I = get_string("Player 1: ");
    string p2I = get_string("Player 2: ");
    toUpper(p1I);
    toUpper(p2I);
    printf("%s\n", checkIs(p1I, p2I));
}

string checkIs(string p1I, string p2I)
{
    int score1 = 0;
    int score2 = 0;
    for (int i = 0; p1I[i] != '\0'; i++)
    {
        if (p1I[i] == 'A' || p1I[i] == 'E' || p1I[i] == 'I' || p1I[i] == 'L' || p1I[i] == 'N' ||
            p1I[i] == 'O' || p1I[i] == 'R' || p1I[i] == 'S' || p1I[i] == 'T' || p1I[i] == 'U')
        {
            score1 += 1;
        }
        else if (p1I[i] == 'B' || p1I[i] == 'C' || p1I[i] == 'M' || p1I[i] == 'P')
        {
            score1 += 3;
        }
        else if (p1I[i] == 'D' || p1I[i] == 'G')
        {
            score1 += 2;
        }
        else if (p1I[i] == 'F' || p1I[i] == 'H' || p1I[i] == 'V' || p1I[i] == 'W' || p1I[i] == 'Y')
        {
            score1 += 4;
        }
        else if (p1I[i] == 'J' || p1I[i] == 'X')
        {
            score1 += 8;
        }
        else if (p1I[i] == 'K')
        {
            score1 += 5;
        }
        else if (p1I[i] == 'Q' || p1I[i] == 'Z')
        {
            score1 += 10;
        }
    }
    for (int i = 0; p2I[i] != '\0'; i++)
    {
        if (p2I[i] == 'A' || p2I[i] == 'E' || p2I[i] == 'I' || p2I[i] == 'L' || p2I[i] == 'N' ||
            p2I[i] == 'O' || p2I[i] == 'R' || p2I[i] == 'S' || p2I[i] == 'T' || p2I[i] == 'U')
        {
            score2 += 1;
        }
        else if (p2I[i] == 'B' || p2I[i] == 'C' || p2I[i] == 'M' || p2I[i] == 'P')
        {
            score2 += 3;
        }
        else if (p2I[i] == 'D' || p2I[i] == 'G')
        {
            score2 += 2;
        }
        else if (p2I[i] == 'F' || p2I[i] == 'H' || p2I[i] == 'V' || p2I[i] == 'W' || p2I[i] == 'Y')
        {
            score2 += 4;
        }
        else if (p2I[i] == 'J' || p2I[i] == 'X')
        {
            score2 += 8;
        }
        else if (p2I[i] == 'K')
        {
            score2 += 5;
        }
        else if (p2I[i] == 'Q' || p2I[i] == 'Z')
        {
            score2 += 10;
        }
    }
    if (score1 > score2)
    {
        return "Player 1 wins!";
    }
    else if (score2 > score1)
    {
        return "Player 2 wins!";
    }
    else
    {
        return "Tie!";
    }
}

void toUpper(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = toupper(s[i]);
    }
}
