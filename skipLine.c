
/* skipLine.c   CSC348/648                                       */  
/*                                                               */  

#include<stdio.h>  

int main();                             //execute main function

void function(int a, int b, int c)  
{
	char buffer[5];                //buffer array
	long* ret;                     //long pointer for return address
	ret = (long *)(buffer + 24);   //location of return value is 24 bytes down from buffer
	(*ret) += 7;                   //increase the value of return by 7 to skip x=1;

	/* set ret to the return address on the stack and change the  */  
	/* value to skip over "x = 1;"                                */  

}  

int main()
{
	int x = 0;                //set x to 0
	function(1, 2, 3);        //execute function method
	x = 1;                    //this line will be skipped since return was increased 7
	printf("x = %i \n", x);   //this line will execute, as it was the addressed returned from function method    
	return 0;
}  


