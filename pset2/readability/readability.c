#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
    string text = get_string("Text: \n");

    int i = 0;
    int length = strlen(text);
    int count = 0;
    int words = 0;
    int sentences = 0;
    
    for (i = 0; i <= length; i++)
    {
        if (islower(text[i]) || isupper(text[i])) 
        {
            count += 1;
        }
        else if (isspace(text[i]) || text[i] == '\0')
        {
            words += 1;
        }
        else if ( text[i] == '.' || text[i] == '!' || text[i] == '?' )
        {
            sentences += 1;
        }
    }
    
    float avg_words = (float) count * 100 / (float) words;
    float avg_sentences = (float) sentences * 100 / (float) words;

    int index = round(0.0588 * avg_words - 0.296 * avg_sentences - 15.8);
    
    if (index > 16)
    {
        printf("Grade 16+\n");    
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");    
    }
    else {
        printf("Grade %i\n", index);    
    }
    
    
}