#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Note to TA & Prof: to compile use gcc -Wall -o wall wall.c -lm
//for some reason the "ceil()" function won't be recognized without "-lm"

//Function declarations
void setHeight(float *height);
void setWidth(float *width);
float calcPaintNeeded(float area);
int calcCansNeeded(double paintNeeded);

int main(void)
{
	//Variables
	float height, width, area;
	double gallons;

	gallons = height = width = area = 0.0;

	printf("Enter height of the wall in feet  :\n");
	setHeight(&height);	

	printf("Enter width of the wall in feet  :\n");
	setWidth(&width);	

	printf("Wall area :\n");
	area = height * width;
	printf("%.2f square feet\n", area);	

	printf("Paint needed :\n");
	gallons = calcPaintNeeded(area);
	printf("%.2f gallons\n", gallons);
	
	printf("Cans needed :\n");
	printf("%d can(s)\n",calcCansNeeded(gallons));

	return(EXIT_SUCCESS);
}

//Function definitions
void setHeight(float *height)
{
	scanf("%f",height);
}

void setWidth(float *width)
{
	scanf("%f",width);
}

float calcPaintNeeded(float area)
{
	return area/350;
}

int calcCansNeeded(double paintNeeded)
{

	return (int) ceil(paintNeeded);
}
