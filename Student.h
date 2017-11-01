/* Harvey Haddix
 * CSC 1600
 * Project2Part1.h
 *
 *  Created on: Sep 28, 2017
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct student {
	long number;
	char name[24];
	char password[12];
} Student;

void BubbleSort(Student a[], long array_size, long pageSize);

#endif /* STUDENT_H_ */
