#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check for 1 command line argument
    if (argc != 2)
    {
        printf("Enter one command-line argument.\n");
        return 1;
    }

    // open memory card file with read
    FILE *inputfile = fopen(argv[1], "r");
    if (inputfile == NULL)
    {
        printf("Cound not open.\n");
        return 2;
    }

    // look for beginning of a jpeg
    BYTE buffer[512];
    int jpgsize = 0;
    char newfile[8];
    FILE *output = NULL;

    while (fread(buffer, sizeof(BYTE), 512, inputfile) == 512)
    // create jpegs
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
            }
            sprintf(newfile, "%03i.jpg", jpgsize);
            output = fopen(newfile, "w");
            if (output == NULL)
            {
                printf("Could not open file.\n");
                return 3;
            }
            fwrite(buffer, sizeof(BYTE), 512, output);
            jpgsize++;
        }
        else if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, output);
        }
    }
    fclose(inputfile);
    if (output != NULL)
    {
        fclose(output);
    }

    return 0;
}
