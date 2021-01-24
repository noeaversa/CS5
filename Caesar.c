#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key = 0;
     if(argc != 2)// si no es un digito de dos 
     {
         printf("Usage: ./caesar key \n");
         return (1);
     }
     else 
     {
         int length = strlen(argv[1]);
         for(int i = 0; i < length; i++)
         {
             if((argv[1][i]) < '0' || (argv[1][i]) > '9')
             {
                 key = 1;
             }
         }
     }
     if(key == 0)
     {
         int k = atoi(argv[1]);
         
         string plaintext = get_string ("plaintext: ");
         printf("ciphertext: ");
         
         for(int a = 0; a < strlen(plaintext); a++)
         {
             if(islower(plaintext[a]))
             {
                printf("%c", ((((plaintext[a] - 'a') + k) % 26) + 'a'));
             }
             else if(isupper(plaintext[a]))
             {
                   printf("%c", ((((plaintext[a] - 'A') + k) % 26) + 'A'));
             }
             else 
             {
                  printf("%c", plaintext[a]);
             }
         }
         printf("\n");
     }
     else
     {
         printf("Usage: ./caesar key \n");
     }
     return(0);
}
