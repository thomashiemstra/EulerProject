#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned long long *array;
unsigned long long *primes;
unsigned long long i,dummy,j,count=0;
unsigned long long max_num;

int getPrimes(int max_num){
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
    return count;
}

int main(){
    int i,j,k,l,nprimes;
    int primeres,sumres=0;
    nprimes = getPrimes(1000000);

    for(i=0; i<nprimes; i++){
        for(j=0; j<i; j++){
            int sum = 0;
            k=0;
            while(sum < primes[i]){
                sum += primes[j+k];
                k++;
                if(sum==primes[i]){
                    if(k>sumres){
                        primeres=primes[i];
                        sumres=k;
                    }
                    //printf("%d is a sum of %d consecutive primes \n",primes[i],k);
                }

            }
        }
    }

    printf("primes=%d sumlength=%d \n",primeres,sumres);
    free(primes);
    free(array);

}
