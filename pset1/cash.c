#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
int coin = 0;
  float cash;

  do
    {
        cash = get_float ("Change owed: ");
    }

    while (cash < 0);

 int cents = round(cash * 100);

 while(cents >= 25)
 {
     cents = cents - 25;
     coin++;
 }
 
  while(cents >= 10)
 {
     cents = cents - 10;
     coin++;
 }
 
   while(cents >= 5)
 {
     cents = cents - 5;
     coin++;
 }
 
   while(cents >= 1)
 {
     cents = cents - 1;
     coin++; 
 }
 printf("Change: %i \n", coin);

}
