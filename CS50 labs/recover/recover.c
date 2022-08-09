#include <stdio.h>
#include <stdlib.h>

void generateFiles(opened file, ...?);
void printError(void);
void printUsage(void);
 
int main(int argc, char *argv[])
{
    // Check that only one argument has been passed
    // implement printUsage() to use if failed and make main return 1
    if (not 1 arg) 
    {
        printUsage();
        return 1;
    }

    // Open file

    
    // If forensic image can't be opened, inform the user and make main return 1
    if (FILE cannot open)
    {
        printError()
    }

    // Generated files should be named ###.jpg, starting with 000
    generateFiles(opened file);

    // Remember to free memory after using malloc() with free(foo)

    // Clean up
    fclose(opened file);
    // free(whatever)?
    return 0;
}

// Recover every one of the JPEGs from input file, storing each as a separate file in the current working directory. 
void generateFiles(opened file)
{

}

void printError(void)
{
    printf();
}

void printUsage(void)
{
    printf();
}

