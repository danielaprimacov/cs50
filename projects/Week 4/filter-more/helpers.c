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
                // Reflect all pixels horizontaly
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
            // Initializing colors values and counter with 0
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
                    // Adding color values with pixels on original image
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    // Looping through all pixels of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initializing Gx and Gy values for each color
            int sumGxBlue = 0;
            int sumGxRed = 0;
            int sumGxGreen = 0;
            int sumGyBlue = 0;
            int sumGyRed = 0;
            int sumGyGreen = 0;
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

                    // Calculating the sum of Gx and Gy for each color
                    sumGxBlue += image[i + k][j + m].rgbtBlue * Gx[k + 1][m + 1];
                    sumGxGreen += image[i + k][j + m].rgbtGreen * Gx[k + 1][m + 1];
                    sumGxRed += image[i + k][j + m].rgbtRed * Gx[k + 1][m + 1];
                    sumGyBlue += image[i + k][j + m].rgbtBlue * Gy[k + 1][m + 1];
                    sumGyGreen += image[i + k][j + m].rgbtGreen * Gy[k + 1][m + 1];
                    sumGyRed += image[i + k][j + m].rgbtRed * Gy[k + 1][m + 1];
                }
            }

            // Calculating the Sobel filter final value
            int SobelBlue = round(sqrt(sumGxBlue * sumGxBlue + sumGyBlue * sumGyBlue));
            int SobelGreen = round(sqrt(sumGxGreen * sumGxGreen + sumGyGreen * sumGyGreen));
            int SobelRed = round(sqrt(sumGxRed * sumGxRed + sumGyRed * sumGyRed));

            // Check if calculated values are more than 255
            if (SobelBlue > 255)
            {
                buffer[i][j].rgbtBlue = 255;
            }
            else
            {
                buffer[i][j].rgbtBlue = SobelBlue;
            }
            if (SobelGreen > 255)
            {
                buffer[i][j].rgbtGreen = 255;
            }
            else
            {
                buffer[i][j].rgbtGreen = SobelGreen;
            }
            if (SobelRed > 255)
            {
                buffer[i][j].rgbtRed = 255;
            }
            else
            {
                buffer[i][j].rgbtRed = SobelRed;
            }
        }
    }

    // Applying the Sobel Algorithm to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = buffer[i][j].rgbtRed;
            image[i][j].rgbtGreen = buffer[i][j].rgbtGreen;
            image[i][j].rgbtBlue = buffer[i][j].rgbtBlue;
        }
    }
    return;
}
