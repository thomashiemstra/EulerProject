#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int steps;
unsigned long long i;
unsigned long long res;
unsigned long long max_num;
int dick_length;        //chain length
int biggest_dick = 1;   //longest chain length
int dick_number;        //number which produces the longest chain

unsigned long long itterate(unsigned long long n){
    if (n%2 == 0){
            n = n/2;
        }
        else{
            n = 3*n+1;
        }
    return n;
}

int main(){
    printf("max num=");
    scanf("%d",&max_num);
    for(i = 1; i<=max_num; i++){
        res = i;
        dick_length = 0;
        while(res != 1 ){
            res = itterate(res);
            dick_length++;
        }
        if (dick_length > biggest_dick){
            biggest_dick = dick_length;
            dick_number = i;
        }
    }
    printf("numer with longest chain=%d\n",dick_number);
    printf("chain length=%d",biggest_dick);
}
