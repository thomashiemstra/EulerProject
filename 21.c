#include <string.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int d(int n){
    int i,j,res=1;

    for(i=2; i<n; i++){
        if(n%i == 0)
            res += i;
    }
    return res;
}


int main(){
    int i,j;
    int res = 0;
    for(i=1; i<=10000; i++){
        if( d(d(i))== i && d(i)!= i)
            res += i;
    }
    printf("res=%d",res);
}
