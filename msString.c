#include "msString.h"
#include <errno.h>


extern msString msSetString ( char *str ){

        long int lenString = strlen(str);

        /* allocate memory space required for the msString */
        msString *newStr = (msString *)malloc( (lenString * sizeof(char)) + sizeof(long int));
        if( newStr == NULL ){
                msError("Memory Allocation Failed");
        }


        /* assign the first value for the msString to be the length of the original string */
        *((long int *)newStr) = lenString;


        /* copy the characters of the normal string into the msString */
        /* character pointer for incrementing based on sizeof(char), starting after the length of the new string */
        char *chars = (char *)newStr + sizeof(long int);

        int i;
        for ( i=0; i<lenString; i++, chars++ ){
                *chars = str[i];
        }

        return newStr;
}



extern char * msGetString ( msString str ){

        /* check that str is not null */
        if (str == NULL){
                msError("Unable to read string from NULL value");
        }

        long int lenString = msLength(str);

        /* allocate memory space required for the normal string */
        char *newStr = (char *)malloc((lenString + 1) * sizeof(char));
        if ( newStr == NULL ){
                msError("Memory Allocation Failed");
        }


        /* copy the characters of the msString into the normal string */
        /* character pointer for incrementing based on sizeof(char), starting after the length of the msString */
        char *chars = (char *)str + sizeof(long int);

        int i;
        for ( i=0; i<lenString; i++, chars++ ){
                newStr[i] = *chars;
        }

        /* ensure the normal string is terminated by the null operator */
        newStr[lenString] = '\0';
        
        return newStr;
}



extern void msCopy ( msString *destination, msString source ){

        /* ensure source is not NULL */
        if (source == NULL) {
                msError("Unable to read string from NULL value");
        }

        long int lenSource = msLength(source);

        /* reallocate memory for destination to be the size of the source string */
        *destination = realloc( *destination, sizeof(long int) + (lenSource * sizeof(char)) );
        if (*destination == NULL) {
                msError("Memory reallocation failed");
        }

        /* assign the first value for the destination msString to be the length of the source msString */
        *((long int *)*destination) = lenSource;


        /* copy the content of source into destination */
        /* character pointer for incrementing based on sizeof(char), starting after the length of the new string */
        char *charsDest = (char *)*destination + sizeof(long int);
        char *charsSource = (char *)source + sizeof(long int);

        int i;
        for ( i=0; i<lenSource; i++, charsDest++, charsSource++ ){
                *charsDest = *charsSource;
        }
}



extern void msConcatenate ( msString *destination, msString source ) {

        /* ensure source is not NULL */
        if (source == NULL) {
                msError("Unable to read string from NULL value");
        }

        /* ensure destination is not NULL */
        if (*destination == NULL) {
                msError("Unable to read string from NULL value");
        }

        long int lenSource = msLength(source);
        long int lenDest = msLength(*destination);
        long int lenNewString = lenSource + lenDest;


        /* reallocate memory for destination to accommodate the source string */
        *destination = realloc( *destination, sizeof(long int) + (lenNewString * sizeof(char)) );
        if (*destination == NULL) {
                msError("Memory reallocation failed");
        }

        /* assign the first value for the destination msString to be the combined length of the msStrings */
        *((long int *)*destination) = lenNewString;


        /* copy the content of source onto the end of destination */
        /* character pointer for incrementing based on sizeof(char), starting after the last character of the original destination msString */
        char *charsDest = (char *)*destination + sizeof(long int) + (lenDest * sizeof(char));
        char *charsSource = (char *)source + sizeof(long int);

        int i;
        for ( i=0; i<lenSource; i++, charsDest++, charsSource++ ){
                *charsDest = *charsSource;
        }
}



extern long int msLength ( msString str ){

        /* set lenString to be the long int value (first value) that str points to */
        long int lenString = *(long int*)str;

        return lenString;
}



extern int msCompare ( msString str1, msString str2 ){

        char *normStr1 = msGetString(str1);
        char *normStr2 = msGetString(str2);

        int stringCompare = strcmp(normStr1, normStr2);
        if (stringCompare == 0){
                return 0;
        }else{
                return 1;
        }
}



extern int msCompareString ( msString str1, char *normStr2 ){

        char *normStr1 = msGetString(str1);

        int stringCompare = strcmp(normStr1, normStr2);
        if (stringCompare == 0){
                return 0;
        }else{
                return 1;
        }
}



static void msError ( char *str ){
        fprintf(stderr, "Error %d: %s\n", errno, strerror(errno));
        fflush(stderr);
        fprintf(stdout, "Error: %s\n", str);
        fflush(stdout);
        exit(EXIT_FAILURE);
}