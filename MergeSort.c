/*
 ============================================================================
 Name        : MergeSort.c
 Author      : Michael Danovich
 Version     : Created during ECE2620
 Description : Utilizes a recursive sorting algorithm with O(NlogN) results
			   to order the array of students by their number and print out
			   related page references.
 ============================================================================
*/

#include "Project2Part1.h"
#include "Student.h"

void Merge(Student a1[], long first, long last, long pageSize)
{
	Student temp[(last-first+1)];
	long mid = (first + last) / 2;
	long i1 = 0;
	long i2 = first;
	long i3 = mid + 1;

	long page1, page2, page3, page4, page0, pagebase;
	pagebase = 0;
	

	FILE* result = fopen("resultsMS.txt","w");            // opens file

		page0 = (long) &a1[i1] / pageSize - pagebase;    
		page1 = (long) &a1[i2] / pageSize - pagebase;
		page2 = (long) &a1[i3] / pageSize - pagebase;
		page3 = (long) &a1[mid] / pageSize - pagebase;
		page4 = (long) &a1[last] / pageSize - pagebase;
		
		fprintf(result,"%ld\n",page0);		fprintf(result,"%ld\n",page1);		fprintf(result,"%ld\n",page2);
		fprintf(result,"%ld\n",page3);
		fprintf(result,"%ld\n",page4);
		
	while((i2 <= mid) && (i3 <= last)) //Fills a temp array 
	{
		page1 = (long) &a1[i2] / pageSize - pagebase;
		page2 = (long) &a1[i3] / pageSize - pagebase;
		page3 = (long) &a1[mid] / pageSize - pagebase;
		page4 = (long) &a1[last] / pageSize - pagebase;
		
		fprintf(result,"%ld\n",page0);
		fprintf(result,"%ld\n",page1);
		fprintf(result,"%ld\n",page2);
		fprintf(result,"%ld\n",page3);
		fprintf(result,"%ld\n",page4);
	
		if(a1[i2].number < a1[i3].number)
		{
			temp[i1++] = a1[i2++];
			//++i2;													debug

			page1 = (long) &a1[i2] / pageSize - pagebase;
			page2 = (long) &a1[i3] / pageSize - pagebase; 
			fprintf(result,"%ld\n",page0); 
			fprintf(result,"%ld\n",page1);
			fprintf(result,"%ld\n",page2);
		}
		else
		{
			temp[i1++] = a1[i3++]; 
			//i3++;
			page1 = (long) &a1[i2] / pageSize - pagebase;
			page2 = (long) &a1[i3] / pageSize - pagebase;			fprintf(result,"%ld\n",page0);                   			fprintf(result,"%ld\n",page1);			fprintf(result,"%ld\n",page2);
		}
		
		//i1++;													   debug
			
	}

	while(i2 <= mid)
	{
		temp[i1++] = a1[i2++];
		page1 = (long) &a1[i2] / pageSize - pagebase;
		page3 = (long) &a1[mid] / pageSize - pagebase;
		fprintf(result,"%ld\n",page1);
		fprintf(result,"%ld\n",page3);
	}

	while(i3 <= last)
	{
		temp[i1++] = a1[i3++];
		page2 = (long) &a1[i3] / pageSize - pagebase;     
		page4 = (long) &a1[last] / pageSize - pagebase;	  
		fprintf(result,"%ld\n",page2);				      
		fprintf(result,"%ld\n",page4);					  
	}
	
		
	for(i1 = 0; i1 < (last-first+1); i1++)
	{
		a1[first + i1] = temp[i1];
		//cout << temp[i1] << endl;			                       debug  
	}
	
	fclose(result);
}

void MergeSort(Student data[], long first, long last)
{	
	if(first < last)
	{
		long mid = (first + last) / 2;
		MergeSort(data, first, mid);
		MergeSort(data, mid+1, last);
		Merge(data, first, last, pageSize);
	}
}