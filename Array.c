#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
#include <time.h>
#include "omp.h"

//using namespace std;

void ZeroSet(int* A[], int K, int N[], int bound)
{
	//array of pointers to other arrays
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < bound; j++)
		{
			N[j] = 0;
		}
		A[i] = N;
	}
}

void TenPercentSet(int* A[], int K, int N[], int bound)
{
	//array of pointers to other arrays
	int totalSize = K*bound;
	int TenSize = totalSize*0.1;
	//cout << totalSize << endl << TenSize << endl;
	int counter = 0;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < bound; j++)
		{
			if (counter != TenSize)
			{
				A[i][j] = 1;
				counter++;
			}
			else break;
		}
		if (counter == TenSize) break;
	}
}

void FivePercentSet(int* A[], int K, int N[], int bound)
{
	//array of pointers to other arrays
	srand(time(NULL));
	int totalSize = K*bound;
	int FiveSize = totalSize*0.05;
	int i = 0;
	int j = 0;
	for (int k = 0; k < FiveSize; k++)
	{
		i = rand() % K;
		j = rand() % bound;
                printf("Index K \t %d \n",i);
                printf("Index N \t %d \n",j);
                printf("Value \t %d \n \n" ,A[i][j]);
	}
}

int main(int argc, char **argv)
{
	int K = 2;
	int bound = 100;

	int* A[K];
	int N[bound];
#pragma omp parallel sections num_threads(2)
{

        #pragma omp section 
        {

        ZeroSet(A, K, N, bound);
	TenPercentSet(A, K, N, bound);
	FivePercentSet(A, K, N, bound);
        //printf("A[0][0] \t %d \n \n" ,*(A[0]+1));
        }

        #pragma omp section 
        {

        ZeroSet(A, K, N, bound);
	TenPercentSet(A, K, N, bound);
	FivePercentSet(A, K, N, bound);
        //printf("A[0][0] \t %d \n \n" ,*(A[0]+1));
        }

}
        
	//return 0;
}
