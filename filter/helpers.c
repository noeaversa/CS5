#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
          float avg = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.00;
          int a = round(avg);
          
          image[i][j].rgbtRed = a;
          image[i][j].rgbtGreen = a;
          image[i][j].rgbtBlue = a;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
             int sepiaRed = round(.393 * image[i][j].rgbtRed  + .769 * image[i][j].rgbtGreen  + .189 * image[i][j].rgbtBlue);
             int sepiaGreen = round (.349 * image[i][j].rgbtRed  + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
             int sepiaBlue = round(.272 * image[i][j].rgbtRed  + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
             
             image[i][j].rgbtRed = (sepiaRed > 255) ? 255: sepiaRed;
             image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255: sepiaGreen;
             image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255: sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < (width / 2); j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            
            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtBlue = blue;
            image[i][width - j - 1].rgbtGreen = green;
            
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE t[height][width];
    
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int blue = 0;
            int red = 0;
            int green = 0;
            float counter = 0;
            
            for(int k = -1; k < 2; k++)
            {
                for(int h = -1; h < 2; h++)
                {
                    if(i + k < 0 || i + k > height -1 || j + h < 0 || j + h > width -1 )
                    {
                        continue;
                    }
                    blue += image[i + k][j + h].rgbtBlue;
                    red += image[i + k][j + h].rgbtRed;
                    green += image[i + k][j + h].rgbtGreen;
                    
                    counter++;
                }
            }
            
            t[i][j].rgbtBlue = round(blue / counter);
            t[i][j].rgbtRed = round(red / counter);
            t[i][j].rgbtGreen = round(green / counter);
            
        }
    }
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = t[i][j].rgbtBlue;
            image[i][j].rgbtRed = t[i][j].rgbtRed;
            image[i][j].rgbtGreen = t[i][j].rgbtGreen;
        }
    }
    
    return;
}
