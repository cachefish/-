#include<stdio.h>
#include<stdlib.h>
typedef int VType;
typedef int EType;
#define VSIZE 100
typedef struct AdjMGraph
{
	VType vexs[VSIZE];
	EType arc[VSIZE][VSIZE];
	int VNum;
	int ENum;
};