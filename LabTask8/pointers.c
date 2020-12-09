#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Constants
#define SIZE 5

//TypeDefs
typedef int * intPtr;
typedef intPtr ptrArray[SIZE];
typedef int IntArray[SIZE];

//Function prototypes
void intialize(IntArray, ptrArray);
void print_intArray(IntArray);
void print_ptrArray(ptrArray);
void print_ptrTarget(ptrArray);
void sortInts(IntArray);
void sortPtrs(ptrArray);


int main(void)
{
	IntArray array;
	ptrArray pArray;

	printf("---- Initialized array of integers ----\n");
	intialize(array,pArray);
	print_intArray(array);
	printf("---- Sorted array of pointers ----\n");
	sortPtrs(pArray);
	print_ptrTarget(pArray);
	sortInts(array);
	printf("---- Sorted array of integers ----\n");
	print_intArray(array);
	printf("---- Array of pointers ----\n");
	print_ptrArray(pArray);

	return (EXIT_SUCCESS);
}



void intialize(IntArray array, ptrArray pArray)
{
	srand(getpid());
	int i;
	for(i = 0; i < SIZE; i++)
	{
	  array[i] = rand();
	  pArray[i] = &array[i];
	}
}


void print_intArray(IntArray array)
{
	int i;	
	for(i = 0; i < SIZE; i++)
	{
	  printf("%d : %d\n", i, array[i]);
	}
}
void print_ptrArray(ptrArray pArray)
{
	int i;	
	for(i = 0; i < SIZE; i++)
	{
	  printf("%d : %d\n", i, *pArray[i]);
	}

}


void print_ptrTarget(ptrArray pArray)
{
	int i;	
	for(i = 0; i < SIZE; i++)
	{
	  printf("%d : %d\n", i, *pArray[i]);
	}

}

void sortInts(IntArray array)
{
	int swapped = 1;
	int i = 0;
	int temp;

	while(swapped)
	{
	 swapped = 0;
	
		for(i = 0; i < SIZE-1; i++)
		{
			if(*(array+i) > *(array+i+1))
			{
			  temp = *(array+i);
			  *(array+i) = *(array+i+1);
			  *(array+i+1) = temp;
			  swapped = 1;
			}
	    }	
	}
}

void sortPtrs(ptrArray pArray)
{
	
	int swapped = 1;
	int i = 0;
	int *temp;

	while(swapped)
	{
	 swapped = 0;
	
		for(i = 0; i < SIZE-1; i++)
		{
			if(*pArray[i] > *pArray[i+1])
			{
			  temp = pArray[i];
			  pArray[i] = pArray[i+1];
			  pArray[i+1] = temp;
			  swapped = 1;
			}
	    }	
	}
}
