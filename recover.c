#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

#define BUFFER_SIZE 512
 
int main(int argc, char *argv[])
{
     FILE* infile = fopen("card.raw", "r");
     
    if(argc != 2)
    {
        printf("Usage: /recover image\n");
        return 1;
    }
    
    if(infile == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    
    unsigned char buffer[BUFFER_SIZE];
    int counter = 0;
    
    FILE* jpeg = NULL;
    
    int jpeg_found = 0;
    
    while(fread(buffer, BUFFER_SIZE, 1, infile) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if(jpeg_found == 1)
            {
                fclose(jpeg);
            }
            else
            {
                jpeg_found = 1;
            }
            
            char file_name[8];
            sprintf(file_name, "%03d.jpg", counter);
            jpeg = fopen(file_name, "a");
            counter++;
        }
        
        if(jpeg_found == 1)
        {
            fwrite(&buffer, BUFFER_SIZE, 1, jpeg);
        }
    }
   
   fclose(infile);
   fclose(jpeg);
   
}
