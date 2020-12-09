#ifndef LCW_H
#define LCW_H
//
#ifndef stdlib_h
#include <stdlib.h>
#endif

#ifndef stdio_h
#include <stdio.h>
#endif
//----Counts lines, words and chars in the input
//-----------------------------------------------------------------------------
#define YES 1
#define NO 0
//-----------------------------------------------------------------------------


int* charslineswords()
{
	int Characters, Lines, Words, InWord;
		Characters = Lines = Words = InWord = 0;

		int *l_c_w = (int *)malloc(3 * sizeof(int));
		char C1;

    while ((C1 = getchar()) != EOF) {
        ++Characters;
        if (C1 == '\n') {
            ++Lines;
        }
        if (C1 == ' ' || C1 == '\n' || C1 == '\t') {
            InWord = NO;
        } 
				else {
				if (!InWord) {
						InWord = YES;
						++Words;
					}
				}
				
				}
				l_c_w[0] = Lines;
				l_c_w[1] = Characters;
				l_c_w[2] = Words;

		return l_c_w;
}
//-----------------------------------------------------------------------------
#endif
