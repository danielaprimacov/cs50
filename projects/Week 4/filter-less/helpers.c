#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Looping through all pixels of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Convert originial pixels in greyscale pixels by dividing by 3.0
            int greyscale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen +
                                   image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = greyscale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Looping through all pixels of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Convert original pixels into sepia pixels by specific formula
            int redSepia = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen +
                                 0.189 * image[i][j].rgbtBlue);
            int greenSepia = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen +
                                   0.168 * image[i][j].rgbtBlue);
            int blueSepia = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen +
                                  0.131 * image[i][j].rgbtBlue);
            // Check if converted pixels are not more than 255
            if (blueSepia > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = blueSepia;
            }
            if (redSepia > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = redSepia;
            }
            if (greenSepia > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = greenSepia;
            }
            // image[i][j].rgbtBlue = (blueSepia > 255) ? 255 : blueSepia;
            // image[i][j].rgbtGreen = (greenSepia > 255) ? 255 : greenSepia;
            // image[i][j].rgbtRed = (redSepia > 255) ? 255 : redSepia;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Looping through all pixels of the image
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                RGBTRIPLE buffer[height][width];
                buffer[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = buffer[i][j];
            }
        }
        else
        {
            for (int k = 0; k < (width - 1) / 2; k++)
            {
                RGBTRIPLE buffer[height][width];
                buffer[i][k] = image[i][k];
                image[i][k] = image[i][width - (k + 1)];
                image[i][width - (k + 1)] = buffer[i][k];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Creating a buffer
    RGBTRIPLE buffer[height][width];
    // Looping through all pixels of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float blue = 0, green = 0, red = 0, counter = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int m = -1; m < 2; m++)
                {
                    if (i + k < 0 || i + k > height - 1)
                    {
                        continue;
                    }
                    if (j + m < 0 || j + m > width - 1)
                    {
                        continue;
                    }
                    blue += image[i + k][j + m].rgbtBlue;
                    green += image[i + k][j + m].rgbtGreen;
                    red += image[i + k][j + m].rgbtRed;
                    counter++;
                }
            }
            buffer[i][j].rgbtBlue = round(blue / counter);
            buffer[i][j].rgbtGreen = round(green / counter);
            buffer[i][j].rgbtRed = round(red / counter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = buffer[i][j].rgbtBlue;
            image[i][j].rgbtGreen = buffer[i][j].rgbtGreen;
            image[i][j].rgbtRed = buffer[i][j].rgbtRed;
        }
    }
    return;
}
