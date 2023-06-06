#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Could not open input file.\n");
        return 2;
    }

    // Declare variables
    unsigned char buffer[512];
    int image_count = 0;
    char filename[8];

    // Loop through input file
    FILE *output_file = NULL;
    while (fread(buffer, sizeof(char), 512, input_file) == 512)
    {
        // Check if buffer is start of JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous output file
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Create new output file
            sprintf(filename, "%03i.jpg", image_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                fclose(input_file);
                fprintf(stderr, "Could not create output file.\n");
                return 3;
            }

            // Increment image count
            image_count++;
        }

        // Write to output file if it exists
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    // Close input and output files
    fclose(input_file);
    if (output_file != NULL)
    {
        fclose(output_file);
    }
    return 0;
}
