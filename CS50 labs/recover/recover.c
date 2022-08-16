#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t matchesMagicBytes(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4);
void generateFiles(FILE *f);
void printError(char *filename);
void printUsage(void);
 
int main(int argc, char *argv[])
{
    printf("Starting program\n");
    // Check that only one argument has been passed
    if (argc != 2)
    {
        printUsage();
        return 1;
    }

    // Open file
    FILE *raw_file = fopen(argv[1], "r");

    printf("Main\n");
    
    // RETURN VALUE
    //   Upon successful completion fopen(), fdopen(), and freopen() return a FILE pointer.   Otherwise,  NULL  is  re‐
    //   turned and errno is set to indicate the error.
    if (raw_file == NULL)
    {
        printError(argv[1]);
        return 1;
    }

    // Generated files should be named ###.jpg, starting with 000
    generateFiles(raw_file);

    // Clean up
    fclose(raw_file);
    
    return 0;
}

// Recover every one of the JPEGs from input file, storing each as a separate file in the current working directory. 
void generateFiles(FILE *f)
{
    printf("start generateFiles\n");

    // Allocate buffer to work with the raw file
    uint8_t *buffer = malloc(512 * sizeof(uint8_t));
    printf("allocated buffer\n");

    char *filename = malloc(10 * sizeof(char));
    printf("allocated filename\n");

    int filename_count = 0;
    sprintf(filename, "%03i.jpg", filename_count); // Print a digit with 3 numbers to represent it, 
    FILE *nf = fopen(filename, "w");

    // Start and Keep reading until EOF
    while (fread(buffer, 1, 512, f) == 512)
    {
        // printf("Reading buffer... -> %x, %x, %x, %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        for (int i = 0; i > 512)

        // Check whether a new jpg has been found
        uint8_t isMatch = matchesMagicBytes(buffer[0], buffer[1], buffer[2], buffer[3]);
        if (isMatch)
        {
            printf("Magic bytes -> %x, %x, %x, %x\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            // Close current file
            if (nf)
            {
                fclose(nf);
                filename_count++;
            }
        }

        // Create new filename and open new file
        sprintf(filename, "%03i.jpg", filename_count); // Print a digit with 3 numbers to represent it, 
        nf = fopen(filename, "w");

        // Write bytes from file <f> to new file <nf>
        // fwrite(data, size, number, outptr)
        fwrite(buffer, 1, 512, nf);
    }

    // Tidy up
    fclose(nf);
    free(filename);
    free(buffer);
}

// Helper to find JPEG's magic bytes
uint8_t matchesMagicBytes(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4)
{
    printf("Comparing buffer... -> %x, %x, %x, %x\n", byte1, byte2, byte3, byte4);

    if (byte1 == 0xff && byte2 == 0xd8 && byte3 == 0xff)
    {   
        // Using bitwise operation & 0xf0 to read only the first 4 bits
        if (byte4 & 0xf0 == 0xe0)
        {
            return 1;
        }
    }

    return 0;
}

void printError(char *fname)
{
    printf("There was an error trying to open file '%s'", fname);
}

void printUsage(void)
{
    printf("Error detected. Please, pass only one command-line argument.\nUsage:");
    printf("./recover <filename>");
}

