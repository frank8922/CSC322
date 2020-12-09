#include<stdio.h>
#include<stdlib.h>

//Function declaraions
void setSideLength(float *sideL);
void setRoadLength(float *roadL);
void setNumKangaroos(int *numOfRoos);
float expKangKills(float sideL, float roadL, int numOfKangs);

int main()
{	
	//variables
	float sideL, roadL;
	int numOfRoos;
	
	//initalize variables
	numOfRoos = sideL = roadL = 0.0;
	
	printf("Enter the side of square in km: \n");
	setSideLength(&sideL);	
	//printf("%.2f\n",sideL);

	printf("Enter roads length in km: \n");
	setRoadLength(&roadL);
	//printf("%.2f\n",roadL);

	
	printf("Enter number of \'roos:\n");
	setNumKangaroos(&numOfRoos);
	//printf("%d\n",numOfRoos);

	printf("Expected number of kills is: \n%.2f\n", expKangKills(sideL, roadL, numOfRoos));
	


return (EXIT_SUCCESS);
}


//Function definitions

//sets the length of the side of square of land
//param: var holding the length of side
void setSideLength(float *sideL)
{
	scanf("%f", sideL);	
}

//sets the length of the road per square
//param: var holding the road length
void setRoadLength(float *roadL)
{
	scanf("%f", roadL);	
}

//sets the number of kangaroos per square
//param: var holding number of kangroos
void setNumKangaroos(int *numOfRoos)
{
	scanf("%d", numOfRoos);	
}
float expKangKills(float sideL, float roadL, int numOfKangs)
{
	return (numOfKangs/(sideL*sideL))*(roadL*0.01)*(1.47);
}
