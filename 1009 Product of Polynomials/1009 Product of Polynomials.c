#include<stdlib.h>
#include<stdio.h>

int main(){
    int k1, k2, count = 0, tmp_int;
    double a[1001] = {0.0}, b[2001] = {0.0}, tmp_float;
    
    scanf("%d", &k1);
    for(int i = 0; i < k1; i++){
        scanf("%d%lf", &tmp_int, &tmp_float);
        a[tmp_int] = tmp_float;
    }
    scanf("%d", &k2);
    for(int i = 0; i < k2; i++){
        scanf("%d%lf", &tmp_int, &tmp_float);
        for(int j = 0; j < 1001; j++){
            b[tmp_int + j] += a[j] * tmp_float; 
        }
    }
    for(int i = 2000; i >= 0; i--)
        if(b[i] != 0.0)
            count++;
    printf("%d", count);
    for(int i = 2000; i >= 0; i--)
        if(b[i] != 0.0)
            printf(" %d %.1f", i, b[i]);
    return 0;
}