#include <stdlib.h>
#include <stdio.h>
#include "omp.h"

int main(){

int var1 = 25;
int var2 = 2;


#pragma omp parallel sections num_threads(2)
{

#pragma omp section 

printf("Sum is %d\n",var1);

#pragma omp section
printf("Sum is %d\n",var2);

}


}
