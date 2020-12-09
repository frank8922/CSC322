#include<stdlib.h>
#include<stdio.h>

//Macros
#define ABS(x) (x < 0) ? (-x) : (x)

//Function declarations
double computeTaxableIncome(double income, double deduction);
char computeTaxGroup(double taxableInc);
double computeTax(char taxGroup, double taxableInc);
void computeInputDeduction(void);
void printTaxInfo(void);
void init(void);

//Global variables declaration
double deduction, income, taxableInc, tax;
char taxGroup;

int main(void)
{
	computeInputDeduction();	
	taxableInc = computeTaxableIncome(income,deduction);	
	taxGroup = computeTaxGroup(taxableInc);
	tax = computeTax(taxGroup,taxableInc);
	printTaxInfo();

	return(EXIT_SUCCESS);
}

void init(void)
{
	deduction = income = taxableInc = tax = 0.0;
}

void printTaxInfo(void)
{
	
	printf("Income         = $%.2lf\n", income);
	printf("Deductions     = $%.2lf\n", deduction);
	printf("Taxable Income = $%.2lf\n", taxableInc);
	printf("Tax group      = %c\n", taxGroup);
	printf("Tax owed       = $%.2lf\n", tax);
}

void computeInputDeduction(void)
{
	
	//Variable definitions
	double uInput = 0.0;

	do 
	{
		printf("Enter next amount : ");	
		scanf("%lf", &uInput);

		if(uInput < 0)
		{ 
			 deduction += ABS(uInput); 
		}
		else
		{
			income += ABS(uInput);
		}

	}	
	while(uInput != 0);

}

double computeTaxableIncome(double income, double deduction)
{
	return (income >= deduction) ? (income - deduction) : (0.0);
}

char computeTaxGroup(double taxableInc)
{
	if(taxableInc >= 500000)
	{
		return 'S';
	}
	else if(taxableInc >= 200000)
	{
		return 'Q';
	}
	else if(taxableInc >= 100000)
	{
		return 'M';
	}
	else if(taxableInc >= 50000)
	{
		return 'A';
	}
	else if(taxableInc >= 20000)
	{
		return 'R';	
	}
	else
	{
		return 'P';	
	}	
}

double computeTax(char taxGroup, double taxableInc)
{
	double tax;

	if(taxGroup == 'S' || taxGroup == 'Q')
	{
		tax = (taxableInc * 0.25);
	}
	
	if(taxGroup == 'M')
	{
		tax = (taxableInc * 0.10);	
	}
	
	if(taxGroup == 'A' || taxGroup == 'R')
	{
		tax = (taxableInc * 0.03);
	}
	
	if (taxGroup == 'P')
	{
		tax = 0.0;	
	}
	
	return (tax > 50000) ? 50000 : tax;
}
