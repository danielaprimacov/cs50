#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Cannot open file %s.\n", argv[1]);
        return 2;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(header), 1, input_file);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) != 0)
    {
        printf("Input is not a WAV file.\n");
        return 3;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Cannot open output file\n");
        return 4;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(header), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int size_block = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    fseek(input_file, size_block, SEEK_END);

    while (ftell(input_file) - size_block > sizeof(header))
    {
        fseek(input_file, -2 * size_block, SEEK_CUR);
        printf("%li, ", ftell(input_file));
        BYTE byte[size_block];
        fread(&byte, size_block, 1, input_file);
        fwrite(&byte, size_block, 1, output);
        printf("%li\n", ftell(input_file));
    }

    // Close opened files
    fclose(input_file);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' &&
        header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size_block = header.numChannels * (header.bitsPerSample / 8);
    return size_block;
}
