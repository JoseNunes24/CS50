#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>


int main (int argc, string argv[])
{
    if (argc == 2)
    {
        
        int key_length = strlen(argv[1]);
         
        for (int n = 0; n < key_length; n++)
        {
            // Store argv[1][i] in a variable
            int is_alpha = isalpha(argv[1][n]);


            // if it's a number, it will return false, so it should do nothing
            if (is_alpha == 0)
            {

            }
            else
            {
                // It's not an integer
                 printf("Wrong arguments!\n");
                 return 1;
            }
        }
        
        
        
        int key = atoi(argv[1]);
        
        //We know it«s an integer, so make sure it«s bigger than 0
        
        if (key < 1)
        {
            printf("Wrong arguments!\n");
                 return 1;    
        }
        
        string plaintext = get_string("plaintext: ");
        
        int len = strlen(plaintext);
        //printf("%i", len);
        
        string ciphertext = plaintext;
        
        for (int i = 0; i < len; i++)
        {
            // If character is 0 - 9
            if (isdigit(ciphertext[i]))
            {
                ciphertext[i] = (ciphertext[i] - 48 + key) % 10 + 48;
            }
            
            // If character is uppercase
            if (isupper(ciphertext[i]))
            {
                ciphertext[i] = (ciphertext[i] - 65 + key) % 26 + 65;
            }
            
            // If character is lowercase
            if (islower(ciphertext[i]))
            {
                ciphertext[i] = (ciphertext[i] - 97 + key) % 26 + 97;
            }
        }
        
        printf("ciphertext: %s\n", ciphertext);
        
        return 0;
    }
    else if (argc == 2)
    {
        printf("./caesar key\n");
        
    }
    else
    {
        printf("Wrong arguments!\n");
        return 1;
    }
}