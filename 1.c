#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int res;
int max_num=1000;
int i;

int main(){
    res = 0;
    for(i=1; i<max_num;i++){
        if(i%3 == 0 ||i%5 == 0){
            res += i;
        }
    }
    printf("res=%d\n",res);
}
