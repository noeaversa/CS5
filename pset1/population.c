#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int start = 0;
    int end = 0;
  
    do
    {
         start = get_int("Start size: ");
    }
    while(start < 9);
    
    do
    {
         end = get_int("End size: ");
    }
    while(end < start);
    
    int n = start;
    int years = 0;
    
    while(end > n)
    {
     int born = n / 3;
     int dead = n / 4;
     n = n + born - dead;
     years++;
    }
     
    printf("Years: %i\n", years);
 

}
