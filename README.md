### About:
This is an individual project, completed as an assignment for a Year 2 Module at the University of Exeter, using ANSI-standard C. It was completed using a Linux Virtual Machine and GCC.

### The Project Description:
The project is split into 3 tasks:

#### Task 1
Write a function called printBytes that accepts a void pointer called ptr and an integer called numBytes as inputs. This function will then print out the decimal values stored in the numBytes contiguous memory locations starting at the memory address pointed to by ptr.
#### Task 2
The program must be run from the Linux command line like this: `coursework fileIn fileOut` where fileIn is the name of an existing text file to be read in, and fileOut is the name of the file
to be output to. The input file will contain one line of text of unknown length. Your program must read this in from the fileIn file and then write it out to the fileOut file in reverse order.
#### Task 3
You are going to define a new way of storing a string. This new msString data type is a pointer, which points to a memory address that stores a long int value that is the length of the string (the number of characters), followed by the characters that make up the string (with no terminating null character). The functions that support this new datatype are as follows:
- msSetString: accepts a standard C string as an input and returns a new msString.
- msGetString: accepts an msString as an input and returns a standard C string.
- msCopy: accepts two inputs, a pointer to an msString (the destination) and an msString (the source), and copies the source value to the destination.
- msConcatenate: accepts two inputs, a pointer to an msString (the destination) and an msString (the source), and concatenates the source value onto the end of the destination.
- msLength: accepts an msString as an input and returns an integer value that is the number of characters in the string.
- msCompare: accepts two msString values as inputs and returns 0 (zero) if they are identical, or 1 if they are not.
- msCompareString: accepts an msString value and a standard C string value as inputs and returns 0 (zero) if the characters making up the strings are the same, or 1 if they are not.
- msError: accepts a standard C string as input, outputs it as an error message to the user and then exits the program. This function can be called by any of the other msString functions when an error occurs.
You must write a C module that implements these functions, without changing the prototypes or definitions.

## Other:
There is also a file titled 'compile' which is essentially a Makefile, which can be run in a Linux terminal to build the project for use. This project received a 98%
