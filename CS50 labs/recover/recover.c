#include <stdio.h>
#include <stdlib.h>

int matchesMagicBytes(BYTE byte1, BYTE byte2, BYTE byte3, BYTE byte4);
void generateFiles(FILE *f);
void printError(char *filename);
void printUsage(void);

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    // Check that only one argument has been passed
    if (argc != 2)
    {
        printUsage();
        return 1;
    }

    // Open file
    FILE *raw_file = fopen(argv[1], "r");
    
    // RETURN VALUE
    //   Upon successful completion fopen(), fdopen(), and freopen() return a FILE pointer.   Otherwise,  NULL  is  re‐
    //   turned and errno is set to indicate the error.
    if (file == NULL)
    {
        printError(argv[1]);
        return 1;
    }

    // Generated files should be named ###.jpg, starting with 000
    generateFiles(raw_file);

    // Remember to free memory after using malloc() with free(foo)
    // Clean up
    cleanUp();
    return 0;
}

// Recover every one of the JPEGs from input file, storing each as a separate file in the current working directory. 
void generateFiles(FILE *f)
{
    BYTE buffer[512];
    // fread()
    // if fread reads a jpg magic bytes header, (buffer[0] == 0xff, buffer[1] == 0xd8, buffer[2] == 0xff, buffer[3] & 0xf0 == 0xe0]), 
        // open new file and write to it
    // if fread reads a new one, close previous and write to new 
    // if fread == 0, close everything and end

    // Keep reading until EOF
    while (fread(buffer, 1, 512, f) == 512)
    {
        int isMatch = matchesMagicBytes(buffer[0], buffer[1], buffer[2], buffer[3]);
        if (isMatch)
        {

        }
        else
        {

        }
    }
}

int matchesMagicBytes(BYTE byte1, BYTE byte2, BYTE byte3, BYTE byte4)
{
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

void printError(char *filename)
{
    printf("There was an error trying to open file '%s'", &filename);
}

void printUsage(void)
{
    printf("Error detected. Please, pass only one command-line argument.\nUsage:");
    printf("./recover <filename>");
}

void cleanUp(void)
{
    fclose(file);
    // free(whatever)?
    // free(whatever)?
    // free(whatever)?
}
