#include<stdlib.h> 
#include<stdio.h> 
  
void merge(int numbers[], int i, int j, int k) 
{ 
    int p, q, r; 
    int n1 = j - i + 1; 
    int n2 =  k - j; 
	printf("n1 = %d\nn2 = %d\n",n1,n2);

    int L[n1], R[n2]; 
  
    for (p = 0; p < n1; p++) 
	{
        L[p] = numbers[i + p]; 
		printf("%d ", L[p]);
	}
	printf("\n");

    for (q = 0; q < n2; q++) 
	{
        R[q] = numbers[j + 1 + q]; 
		printf("%d ", R[q]);
	}

	printf("\n");
  
    p = 0; 
    q = 0;
    r = i; 
    while (p < n1 && q < n2) 
    { 
        if (L[p] <= R[q]) 
        { 
            numbers[r] = L[p]; 
            p++; 
        } 
        else
        { 
            numbers[r] = R[q]; 
            q++; 
        } 
        r++; 
    } 

    while (p < n1) 
    { 
        numbers[r] = L[p]; 
        p++; 
        r++; 
    } 

    while (q < n2) 
    { 
        numbers[r] = R[q]; 
        q++; 
        r++; 
    } 
} 
  
void mergeSort(int numbers[], int i, int k) 
{ 
    if (i < k) 
    {
        int j = i+(k-i)/2; 
  
        mergeSort(numbers, i, j); 
        mergeSort(numbers, j+1, k); 
  
        merge(numbers, i, j, k); 
    } 
} 

int main() 
{ 
    int numbers[] = {10, 2, 78, 4, 45, 32, 7, 11};
	const int NUMBERS_SIZE = 8;
	int i = 0;

	printf("UNSORTED: ");
	for (i = 0; i < NUMBERS_SIZE; ++i) {
		printf("%d ", numbers[i]);	
	}
	printf("\n");

	mergeSort(numbers, 0, NUMBERS_SIZE - 1);
  
    printf("SORTED: ");
	for (i = 0; i < NUMBERS_SIZE; ++i) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
	
	return(EXIT_SUCCESS);
}
