#include<stdlib.h>
#include<stdio.h>
#include<limits.h>




//Function Prototypes
void MergeSort(int array[], int low, int high);
void Merge(int array[], int low, int mid, int high);

int main(void)
{

	  int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
      const int NUMBERS_SIZE = 8;
      int i;

      printf("UNSORTED: ");
      for (i = 0; i < NUMBERS_SIZE; ++i) {
          printf("%i ", numbers[i]);
          }
      printf("\n");

      MergeSort(numbers, 0, NUMBERS_SIZE - 1);

      printf("SORTED: ");
      for (i = 0; i < NUMBERS_SIZE; ++i) {
	  printf("%i ", numbers[i]);
	  }
      printf("\n");


	return(EXIT_SUCCESS);
}

void MergeSort(int array[], int low, int high)
{
	if(low < high)
	{
	  int mid = (high + low) / 2;

	  MergeSort(array, low, mid);
	  MergeSort(array, mid+1, high);

	  Merge(array, low, mid, high);
	}


}

void Merge(int array[], int low, int mid, int high)
{
	int	n1 = mid - low + 1;
	int n2 = high - mid;
	
	int p, q, r;

	int left[n1+1];
	int right[n2+1];

	for(p = 0; p < n1; p++)
		left[p] = array[low + p];

	for(q = 0; q < n2; q++)
		right[q] = array[mid + q + 1];

	left[n1] = INT_MAX;
	right[n2] = INT_MAX;

	p = 0;
	q = 0;

	for(r = low; r <= high; r++)
	{
		if(left[p] <= right[q])
		{
		  	array[r] = left[p];
			p++;
		}
		else
		{
		  array[r] = right[q];
			q++;
		}
	}
}




