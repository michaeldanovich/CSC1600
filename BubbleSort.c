/* Harvey Haddix
 * CSC 1600
 * BubbleSort.c
 *
 *  Created on: Sep 28, 2017
 */

#include "Student.h"

void BubbleSort(Student a[], long array_size, long pageSize)
{
	long i, j;
	Student temp;
	long page1, page2, page0, pagebase;

	pagebase = 0;
	page0 = (long) &temp / pageSize - pagebase;

	FILE* result = fopen("results.txt","w");
	for (i = 0; i < (array_size - 1); ++i)
	{
		for (j = 0; j < array_size - 1 - i; ++j )
		{
			page1 = (long) &a[j] / pageSize - pagebase;
			page2 = (long) &a[j+1] / pageSize - pagebase;
			fprintf(result,"%ld\n",page0);
			fprintf(result,"%ld\n",page1);
			fprintf(result,"%ld\n",page2);

			if (a[j].number > a[j+1].number)
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	long expect = (array_size - 1)*(array_size)*3/2;
	printf(" Expect %ld lines in results file.\n",expect);
	fclose(result);
}

