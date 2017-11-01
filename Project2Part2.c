/*
 ============================================================================
 Name        : Project3.c -- Page Replacement
 Author      : Prof. McGeary
 Version     :
 Copyright   : Copyright 2015
 Description : Hello World in C, Ansi-style
 ============================================================================


#include <stdio.h>
#include <stdlib.h>

void quickLRU(long numberOfFrames);

int main(void) {
	setbuf(stdout,NULL);
	long frames = 6;
	while(frames>0)
	{
		printf("Number of frames: ");
		scanf("%ld",&frames);
		quickLRU(frames);
	}
}
*/