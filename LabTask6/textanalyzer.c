#include<stdio.h>


#define STR_LENGTH 1024

//Type Definitions
typedef char* String[STR_LENGTH];

//Function Prototypes
String *getString();


int main(void)
{

	printf("%c", getString());	

	return (EXIT_SUCCESS);
}

String *getString()
{
	String input;
	int i = 0;
	
	input[i] = getchar();

	while(*input != '\n' || input != EOF)
	{
		putchar(input);

		if(i < (STR_LENGTH - 2))
		{
		  i++;
		  input[i] = getchar();
		}
		else
		{
			input[i+1] = '\n';	
		}
	}
	
	return input; 
}




