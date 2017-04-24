#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


unsigned long long max_num,test_num;
unsigned long long i,dummy,j,count=0;
unsigned long long *array;
unsigned long long *primes;


int main(){
    //scanf("%d",&max_num);
    test_num = 600851475143;
    max_num=sqrt(test_num);
    array = (unsigned long long *)calloc(max_num,sizeof(unsigned long long)); /* 0 is used as true and 1 as false (faster this way)*/
    for(i = 2; i <= sqrt(max_num); i++){
        if(array[i] == 0){
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
    i=0;
    while(primes[i]*primes[i]<test_num){
        if(test_num % primes[i] == 0){
            printf("prime factor=%llu \n",primes[i]);
        }
        i++;
    }
    free(array);
    free(primes);
}
