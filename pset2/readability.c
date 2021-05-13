#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main (void)
{
 int letters = 0;
 int words = 1;
 int sentences = 0;
 int i = 0;

     string text = get_string("Text: "); //pide texto, para saber las letras, palabras y oraciones

 for (i = 0; i < strlen(text); i++)
 {
     	 if(isalpha(text[i])) //solo caracteres aceptados para sumar letters
  		{
  			letters++; //suma nro de letras
  		}
  		else if(isspace(text[i])) // suma caracteres separados por espacios
  		{
  		 words++;
  		}
  		else if(text[i] == '.' || text[i] == '!' || text[i] == '?') //suma caractares que tengan . ! o ?
  		{
  		 sentences++;
  		}
 }

float l = ((float) letters * 100 / (float) words);
float s = ((float) sentences * 100 / (float) words);
float index = 0.0588 * l - 0.296 * s - 15.8; //calculo para saber grado

int total = round(index);

 if(total > 1 && total < 16)
 {
   printf("Grade %i\n", total);
 }

 else if(total <= 1)
 {
   printf("Before Grade 1\n");
 }

 else if(total >= 16)
 {
  printf("Grade 16+\n");
 }
}
