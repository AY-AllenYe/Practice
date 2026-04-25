#include<stdlib.h>
#include<stdio.h>

int main(){
    int k, count = 0, tmp_int, flag[1001];
    double a[1001], tmp_float;
    for(int i = 0; i < 1001; i++){
        a[i] = 0.0;
        flag[i] = 0;
    }
    for(int j = 0; j < 2; j++){
        scanf("%d", &k);
        for(int i = 0; i < k; i++){
            scanf("%d%lf", &tmp_int, &tmp_float);
            if(flag[tmp_int] == 0){
                a[tmp_int] = tmp_float;
                count++;
                flag[tmp_int] = 1;
            }
            else{
                a[tmp_int] = a[tmp_int] + tmp_float;
                if(a[tmp_int] == 0.0){
                    flag[tmp_int] = 0;
                    count--;
                }
            }
        }
    }
    printf("%d", count);
    for(int i = 1000; i >= 0; i--)
        if(flag[i] == 1)
            printf(" %d %.1f", i, a[i]);
    return 0;
}