#include <stdio.h>
#include <stdlib.h>

void generateFiles(opened file, ...?);
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
    FILE *file = fopen(argv[1], "r");
    
    // RETURN VALUE
    //   Upon successful completion fopen(), fdopen(), and freopen() return a FILE pointer.   Otherwise,  NULL  is  re‐
    //   turned and errno is set to indicate the error.
    if (file == NULL)
    {
        printError(argv[1]);
        return 1;
    }

    // Generated files should be named ###.jpg, starting with 000
    generateFiles(file);

    // Remember to free memory after using malloc() with free(foo)
    // Clean up
    cleanUp();
    return 0;
}

// Recover every one of the JPEGs from input file, storing each as a separate file in the current working directory. 
void generateFiles(opened file)
{

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
