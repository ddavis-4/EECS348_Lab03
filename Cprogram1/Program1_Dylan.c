#include <stdio.h>
#include <stdlib.h>

float* readfile(char *file_name)
{
	float* monthlysales = (float*)malloc(sizeof(float) * 12);
	FILE *fp = fopen(file_name, "r");
	for(int i =0; i < 12; ++i)
	{
		fscanf(fp, "%f\n", &monthlysales[i]);
	}
	return monthlysales;
}

int salesreport(char *calendar[], float *sales)
{
	printf("Months\t\tSales\n");

	for(int i = 0; i < 12; ++i)
	{
		printf("%-8s\t$%.2f\n", calendar[i], sales[i]);
	}
	return 0;
}

int salessummary(float *sales)
{
	double total, avg, min, max;
	
	total = 0.0;
	min = sales[0];
	max = sales[0];
	for (int i = 0; i < 12; i++)
	{
		total += sales[i];

		if (sales[i] < min)
		{
			min = sales[i];
		}

		if (sales[i] > max)
		{
			max = sales[i];
		}
	}
	avg = total / 12;
	
	printf("\nSales Summary\n");
	printf("Minimum: $%.2f\n", min);
	printf("Maximum: $%.2f\n", max);
	printf("Average: $%.2f\n", avg);
	
	return 0;
}

int monthlysalesreport(char *calendar[], float *sales)
{
	printf("\nSales Report (Highest to Lowest):\nMonth\t\tSales\n");
	int max_index = 0;

	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			if(sales[j] > sales[max_index])
			{
				max_index = j;
			}
		}
		printf("%-8s\t$%.2f\n", calendar[max_index], sales[max_index]);
		sales[max_index] = 0;
	}
	return 0;
}


int movingavg(char *calendar[], float *sales)
{
	printf("\nSix-Month Moving Average Report: \n");
	int start = 0, stop = 5;
	float total = 0;
	
	while(start < 7)
	{
		printf("%-8s\t- %-8s\t\t", calendar[start], calendar[stop]);
		for(int i = start; i <= stop; i++)
		{
			total += sales[i];
		}
		float avg = total / 6;
		printf("$%.2f\n", avg);
		start++;
		stop++;
		total = 0;
	}
	return 0;
}

int main()
{
	float* sales = readfile("input.txt");
	char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	printf("Monthly Sales Report for 2022:\n");
	salesreport(month, sales);
	salessummary(sales);
	movingavg(month, sales);
	monthlysalesreport(month, sales);
	return 0;
}
