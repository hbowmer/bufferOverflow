
/* jumpShell.c   CSC348/648                                      */  
/* This program will jump to the shell code                      */  
/*                                                               */  

#include<stdio.h>  
#include"amdshellcode.h"  

int main();                                     //execute main function

void function(int a, int b, int c)  
{
	char buffer[5];                         //buffer array
	long* ret;                              //long pointer for return address
	ret = ((long *)((long)buffer + 24));    //the location of return is 24 bytes down from the start of buffer
	(*ret) = amdshellcode;                  //set the value at the address 24 bytes down from buffer to the start of amdshellcode

	/* set ret to the return address on the stack and change the  */  
	/* value to jump to shellcode                                 */  

}  

int main()
{
	int x = 0;                              //set x to 0
	function(1, 2, 3);                      //execute function method
	x = 1;                                  //function will return to the address of amdshellcode, not to here
	printf("x = %i \n", x);                 //this will be skipped
	return 0;                               //this will be skipped too
}  


