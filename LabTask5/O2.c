#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//TODO:(1) Get depth & oxygen percentage from user
//TODO:(2) Compute ambient pressure, O2 pressure, & O2 group
//TODO:(3) Check if partial pressure exceeds recommended PP and contingent PP

//Constants
#define FT_PER_ATMS 33

//Function & Variable Declarations
float calcAmbientPress(int*);
float calcPartialPress(float*,float*);
char calcO2grp(float*);


int main(void)
{
	//Variable declarations
	int depth; 
	float O2Per, ambpress, O2ParPress;
	char O2grp; 
	bool exRecPress, exConPress;
	
	//Varaible definitions
	O2grp = 'A';
	exRecPress = exConPress = false;
	O2Per = ambpress = O2ParPress = 0.0;

	printf("Enter depth and percentage O2   : ");
	scanf("%d", &depth);
	scanf("%f", &O2Per);	

	ambpress = calcAmbientPress(&depth);

	printf("Ambient pressure                : %.2f\n", ambpress);

	O2ParPress = calcPartialPress(&O2Per, &ambpress);
	printf("O2 pressure                     : %.2f\n", O2ParPress);

	O2grp = calcO2grp(&O2ParPress);
	printf("O2 group                        : %c\n", O2grp);
	
	exRecPress = (O2ParPress > 1.4) ? true : false;
	exConPress = (O2ParPress > 1.6)	? true : false;
	
	printf("Exceeds maximal O2 pressure     : %s\n", exRecPress ? "true":"false");

	printf("Exceeds contingency O2 pressure : %s\n", exConPress ? "true":"false");

	return (EXIT_SUCCESS);
}




//Function & Global Var Definitions
float calcAmbientPress(int* depth)
{
	return (*depth / FT_PER_ATMS) + 1;
}

float calcPartialPress(float* O2Per, float* ambpress)
{
	return (*O2Per / 100) * (*ambpress);
}

char calcO2grp(float* O2ParPress)
{
	return (*O2ParPress * 10) + (65);

}
