#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number_blocks;
    do
    {
        number_blocks = get_int("Size: ");
    }
    while (number_blocks < 1 || number_blocks > 8);

      for (int i = 0; i < number_blocks; i++)
      {
         for (int j = 0; j < number_blocks; j++)
        {
          if (j < (number_blocks - i - 1))
          {
              printf(" ");
          }
          else
          {
              printf("#");
          }
        }
      printf("\n");
      }
}
