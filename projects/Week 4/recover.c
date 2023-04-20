#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Store a byte of date
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for valid usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open forensic image
    FILE *file = fopen(argv[1], "r");
    // Check if file is fail to open
    if (file == NULL)
    {
        printf("Could not open %s file\n", argv[1]);
        return 2;
    }

    int count = 0; // for counting images

    // Initializing file pointer for output data with NULL
    FILE *output = NULL;

    // Allocating memory for file
    char *filename = malloc(8 * sizeof(char));
    if (filename == NULL)
    {
        printf("Error in memory allocation!\n");
        return 3;
    }

    BYTE buffer[512]; // store 512 elements

    // Read 512 bytes from file and store in buffer
    while (fread(buffer, sizeof(BYTE) * 512, 1, file) == 1)
    {
        // Check if filename is starting with JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close output file if image was found before and written
            if (output != NULL)
            {
                fclose(output);
            }
            // File should be named ###.jpg -> ### is a 3-digit decimal number
            sprintf(filename, "%03d.jpg", count++);

            // Open output file for writing
            output = fopen(filename, "w");
        }
        // Check output if was used for valid input
        if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, output);
        }
    }

    // Free memory used and close all files
    free(filename);
    fclose(output);
    fclose(file);

    return 0;
}