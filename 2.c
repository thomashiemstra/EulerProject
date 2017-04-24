#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double res=0;
unsigned long long current,previous,next,max_num=4000000;


int main(){
    current=1;
    previous=1;

    while(1){
        next = current + previous;
        previous = current;
        current = next;
        if(current >=max_num){
            break;
        }
        if(current%2==0){
            res += current;
        }
    }

    printf("sum=%lf \n",res);
}
