#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// some declarations
int count_letters(string s);
int count_words(string s);
int count_sentences(string s);
int formula(string s);

int main(void)
{
    //input from user
    string s = get_string("Text: ");
    
    //typing in formula
    int index = formula(s);
    
    //checking for grade
    if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    
}

// for counting letters
int count_letters(string s)
{
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = toupper(s[i]);
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            sum++;    
        }
    }
    return sum;
}

//for counting words
int count_words(string s)
{
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            sum++;
        }
    }
    sum++;
    return sum;
      
      
}

//for counting sentences
int count_sentences(string s)
{
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sum++;
        }
    }
    
    return sum;
}

//final formula
int formula(string s)
{
    float L = (count_letters(s) / (float)count_words(s)) * 100;
    
    float S = (count_sentences(s) / (float)count_words(s)) * 100;
    
    float value = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(value);   
    return index;
}