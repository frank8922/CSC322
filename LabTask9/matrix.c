#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
double* input_matrix(int* rows, int* cols, char* matrix_name);
void output_matrix(double* matrix, int rows, int cols);
int matrix_multiply(double* matrix1, int rows1, int cols1, double* matrix2, int rows2, int cols2, double* result_matrix);


int main(void)
{
	double *m1,*m2,*m3;
		int m1_rows,m1_columns,m2_rows,m2_columns;

		if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix A")) != NULL) &&
	((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix B")) != NULL) &&
	((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) {
			printf("Matrix A\n");
			output_matrix(m1,m1_rows,m1_columns);
			printf("Matrix B\n");
			output_matrix(m2,m2_rows,m2_columns);
			if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3)) {
				printf("Product C\n");
				output_matrix(m3,m1_rows,m2_columns);
				free(m1);
				free(m2);
				free(m3);
				return(0);
			} else {
				printf("Error in dimensions\n");
				free(m1);
				free(m2);
				free(m3);
				return(-1);
			}
		} else {
			free(m1);
			free(m2);
			free(m3);
			printf("Error allocating memory\n");
			return(-2);
		}

}


double* input_matrix(int* rows, int* cols, char* matrix_name)
{
	printf("Enter number of rows: ");
	scanf("%d",rows);
	printf("Enter number of cols: ");
	scanf("%d", cols);

	double* matrix = (double*)malloc(*rows * *cols * sizeof(double));

	printf("Enter the values of the %s : \n", matrix_name);
	for(int i = 0; i < *rows; i++)	
		for(int j = 0; j < *cols; j++)
			scanf("%lf",(matrix + i* *cols + j));

	return matrix;
}


void output_matrix(double* matrix, int rows, int cols)
{
	for(int i = 0; i < rows; i++)	
	{
		for(int j = 0; j < cols; j++)
		  printf(" [%d][%d] = %.0lf", (i+1), (j+1), *(matrix + i * cols + j));

		printf("\n");
	}
	

}


int matrix_multiply(double* matrix1, int rows1, int cols1, double* matrix2, int rows2, int cols2, double* result_matrix)
{
	double sum = 0;

	if(cols1 == rows2)
	{
		double a,b;
		
		for(int i = 0; i < rows1; i++) //loops through A's rows 12 times b4 ++
		{
			for(int j = 0; j < cols2; j++)//loops through B rows 3 rimes b4 ++
			{
			  sum = 0;
			                   //rows2
			  for(int k = 0; k < cols1; k++) 
			  {
				  a = *(matrix1 + (i * cols1) + k);
				  b = *(matrix2 + (k * cols2) + j);
				  sum += (a * b);
			  }

			  *(result_matrix + (i * cols2) + j) = sum;
			}
		}

	}
	else
	{
	  return 0;
	}

	return 1;
}
