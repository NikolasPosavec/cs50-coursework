#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int calcLs(string text);
int calcWs(string text);
int calcSs(string text);
double CLI(int letters, int words, int sents);
void readLvl(double index);

int main(void)
{
    string text = get_string("Text: ");
    int letters = calcLs(text);
    int words = calcWs(text);
    int sentences = calcSs(text);
    double index = CLI(letters, words, sentences);
    readLvl(index);
}

int calcLs(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            letters++;
        }
        if (text[i] >= 97 && text[i] <= 122)
        {
            letters++;
        }
    }
    return letters;
}
int calcWs(string text)
{
    int words = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words + 1;
}
int calcSs(string text)
{
    int sents = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sents++;
        }
    }
    return sents;
}
double CLI(int letters, int words, int sents)
{
    double Lavg = (double) letters / words;
    double L = Lavg * 100;

    double Savg = (double) sents / words;
    double S = Savg * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}
void readLvl(double index)
{
    int readLvl = round(index);
    if (readLvl < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readLvl >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", readLvl);
    }
}
