#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int valueOfGray;
    
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            valueOfGray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            
            image[i][j].rgbtBlue = valueOfGray;
            image[i][j].rgbtGreen = valueOfGray;
            image[i][j].rgbtRed = valueOfGray;
        }
    }
    return;
}

int limit (int value)
{
    if (value > 255)
    {
        value = 255;
    }

    return value;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            sepiaRed = limit(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            sepiaBlue = limit(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));
            
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width / 2; j++)
        {
            temp[0] = image[i][j].rgbtBlue;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtRed;
            
            // -1 because its an array, it starts at zero!
            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed;
            
            image[i][width-1-j].rgbtBlue = temp[0];
            image[i][width-1-j].rgbtGreen = temp[1];
            image[i][width-1-j].rgbtRed = temp[2];
            
            
        }
    }
    
    return;
}

// Blur image
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // sums values of pixels and 8 near ones, skips if outside the edges
            // w is for the width nearby and h for height
            //Start 1 to the left, then center and 1 to the right. Same for height, reason for -1
            for (int w = -1; w < 2; w++)
            {
                if (j + w < 0 || j + w > width - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > height - 1)
                    {
                        continue;
                    }

                    sumBlue += image[j + w][i + h].rgbtBlue;
                    sumGreen += image[j + w][i + h].rgbtGreen;
                    sumRed += image[j + w][i + h].rgbtRed;
                    counter++;
                }
            }

            // averages the sum to make picture look blurrier
            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
    
    return;
}
