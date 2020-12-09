//----Counts lines, words and chars in the input
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "lcw.h"

int main(void) {

    int Characters,Lines,Words;
		int *CLW;
		
		CLW = charslineswords();

    Lines = CLW[0]; Words = CLW[2]; Characters = CLW[1];
			
    printf("\nC:%d W:%d L:%d\n",Characters,Words,Lines);

    return(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
