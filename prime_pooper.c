#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


unsigned long long max_num;
unsigned long long i,dummy,j,count=0;
unsigned long long *array;
unsigned long long *primes;

void getPrimes(int max_num){
    array = (unsigned long long *)calloc(max_num,sizeof(unsigned long long)); /* 0 is used as true and 1 as false (faster this way)*/

    for(i = 2; i*i <= max_num; i++){
        if(array[i] == 0){ /* if prime*/
            for(j = i*i; j < max_num; j += i){
                array[j] = 1 ; /*cross off all non primes */
            }
        }
    }
	for(i=2; i<max_num; i++){
        if(array[i]==0){
            count++;
        }
    }
    primes = (unsigned long long *)calloc(count,sizeof(unsigned long long));
    j=0;
    for(i=2; i<max_num;i++){
        if(array[i] == 0){
            primes[j] = i;
            j++;
        }
    }
}

int main(){
    scanf("%d",&max_num);
	getPrimes(max_num);
    free(array);
    free(primes);
}
