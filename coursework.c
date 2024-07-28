#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "msString.h"

/* Function Prototypes */
void printBytes( void *ptr, int numBytes );


int main ( int argc, char **argv ) {

        /* Task 1 */
                printf("Beginning Task 1\n");

                /* sample data */
                int fourNumbers[]  = {10, 20, 30, 145};
                void *a = fourNumbers;

                int tenNumbers[]  = {10, 20, 30, 145, 25, 3457, 161, 3885, 1, 27};
                void *b = tenNumbers;

                int twentyNumbers[]  = {83, 247, 2578, 10, 17, 3, 1, 20, 123, 742, 899, 30, 784, 1578, 145, 6783, 8, 145, 12, 752};
                void *c = twentyNumbers;

                /* sample function calls */
                printBytes(a, 4);
                printBytes(b, 6);
                printBytes(c, 12);
                printBytes(c, 5);
                printBytes(c, 20);

                printf("Task 1 Complete!\n");



        /* Task 2 */
                printf("\nBeginning Task 2\n");

                /* ensure that the arguments provided are correct */
                if ( argc != 3 ) {
                        printf("Invalid Number of Arguments\n");
                        return -1;
                }


                /* using pointers to the file names for readability */
                char *inputFileName = argv[1];
                char *outputFileName = argv[2];


                /* attempting to open the input file and checking that it is successful */
                FILE *inputFile;
                if ( ( inputFile = fopen( inputFileName, "r" ) )  == NULL ){
                        printf("Unable to read the input file: %d: %s\n", errno, strerror(errno));
                        return -1;
                }


                /* confirmation of successful args */
                printf("Writing %s backwards into %s\n", inputFileName, outputFileName);


                /* allocating memory for reading from the file, assuming that the line is no longer than 100 characters */
                char lineInFile[100];
                char *lineContents;


                /* if a line exists in the input file, it will be read and written to lineInFile */
                if( fgets (lineInFile, sizeof(lineInFile), inputFile) != NULL ){

                        /* allocates memory for the line */
                        if(!(lineContents = malloc(strlen(lineInFile) + 1))){
                                printf("Memory Allocation Failed\n");
                                free(lineContents);
                                return -1;
                        }
                        strcpy(lineContents, lineInFile);
                        fclose(inputFile);

                }else{
                        printf("File is empty");
                        return -1;
                }


                /* attempting to open output file and checking it was successful */
                FILE *outputFile;
                if ( ( outputFile = fopen( outputFileName, "w" ) ) == NULL ){
                        printf("Unable to open the ouput file: %d: %s\n", errno, strerror(errno));
                        return -1;
                }


                /* initialising a pointer to the last character in the line from the file */
                char *ptr = lineContents + strlen(lineContents) - 2;

                /* iterating over the chars backwards and appending them to the output file */
                while ( ( ptr >= (char *)lineContents ) ){
                        if( ferror(outputFile) ){
                                printf("An error occurred while writing to the output file\n");
                                break;
                        }
                        fputc(*ptr, outputFile);
                        ptr--;
                }

                free(lineContents);
                fclose(outputFile);

                printf("Task 2 Complete!\n");



        /* Task 3 */
                printf("\nBeginning Task 3\n");

                msString        ms      = msSetString("Hello");
                msString        ms2     = msSetString(" World!");
                msString        mscopy  = NULL;

                printf("String |%s| is %d characters long (%p).\n", msGetString(ms), msLength(ms), ms);
                msCopy(&mscopy, ms);
                printf("Copied string |%s| is %d characters long (%p).\n", msGetString(mscopy), msLength(mscopy), mscopy);

                printf("Compare ms with mscopy: %d\n", msCompare(ms, mscopy));
                printf("Compare ms with ms2:    %d\n", msCompare(ms, ms2));
                printf("Compare ms with Hello:  %d\n", msCompareString(ms, "Hello"));
                printf("Compare ms with HelloX: %d\n", msCompareString(ms, "HelloX"));
                printf("Compare ms with Hella:  %d\n", msCompareString(ms, "Hella"));

                msConcatenate(&mscopy, ms2);
                printf("Concatenated string |%s| is %d characters long (%p).\n", msGetString(mscopy), msLength(mscopy), mscopy);

                /* Memory Leak Prevention, we must free the dynamically allocated data since it is no longer used */
                free(ms);
                free(ms2);
                free(mscopy);
                printf("Memory Freed\n");

                printf("Task 3 Complete!\n");



        printf("\nAll Tasks Complete!\n");
        return 0;
}


void printBytes( void *ptr, int numBytes ) {
        /* casting pointer before iteration so that increments occur based on decimal values */
        int *pointer = (int *)ptr;

        printf("Starting at memory address %p:\n", pointer);
        printf("Printing %d bytes\n", numBytes);

        int i;
        for ( i=1; i<=numBytes; i++ ){
                printf("00%d:   %d\n", i, *pointer);
                pointer++;
        }
        printf("-----------------------------------------------------\n");

}
