#include<stdlib.h>
#include<stdio.h>

int main(){
    int a, b, sum, sum1, sum2, sum3;
    scanf("%d %d", &a, &b);
    sum = a + b;
    sum3 = sum / 1000000;
    sum2 = sum / 1000 - sum3 * 1000;
    sum1 = sum - sum3 * 1000000 - sum2 * 1000;
    /*
    if(sum3 != 0) printf("%d,%d,%d", sum3, abs(sum2), abs(sum1));
    if(sum3 == 0 && sum2 != 0) printf("%d,%d", sum2, abs(sum1));
    if(sum3 == 0 && sum2 == 0) printf("%d", sum1);
    */
    if(sum3 != 0){
        printf("%d,", sum3);
        if(sum2 == 0){
            printf("000,");
            if(sum1 == 0){
                printf("000");
            }else if(abs(sum1) < 10 && abs(sum1) > 0){
                printf("00%d", abs(sum1));
            }else if(abs(sum1) < 100 && abs(sum1) > 10){
                printf("0%d", abs(sum1));
            }else
                printf("%d", abs(sum1));
        }else if(abs(sum2) < 10 && abs(sum2) > 0){
            printf("00%d,", abs(sum2));
            if(sum1 == 0){
                printf("000");
            }else if(abs(sum1) < 10 && abs(sum1) > 0){
                printf("00%d", abs(sum1));
            }else if(abs(sum1) < 100 && abs(sum1) > 10){
                printf("0%d", abs(sum1));
            }else
                printf("%d", abs(sum1));
        }else if(abs(sum2) < 100 && abs(sum2) > 10){
            printf("0%d,", abs(sum2));
            if(sum1 == 0){
                printf("000");
            }else if(abs(sum1) < 10 && abs(sum1) > 0){
                printf("00%d", abs(sum1));
            }else if(abs(sum1) < 100 && abs(sum1) > 10){
                printf("0%d", abs(sum1));
            }else
                printf("%d", abs(sum1));
        }else{
            printf("%d,", sum2);
            if(sum1 == 0){
                printf("000");
            }else if(abs(sum1) < 10 && abs(sum1) > 0){
                printf("00%d", abs(sum1));
            }else if(abs(sum1) < 100 && abs(sum1) > 10){
                printf("0%d", abs(sum1));
            }else
                printf("%d", abs(sum1));
        }
    }
    else if(sum3 == 0 && sum2 != 0){
        printf("%d,", sum2);
        if(sum1 == 0){
                printf("000");
            }else if(abs(sum1) < 10 && abs(sum1) > 0){
                printf("00%d", abs(sum1));
            }else if(abs(sum1) < 100 && abs(sum1) > 10){
                printf("0%d", abs(sum1));
            }else
                printf("%d", abs(sum1));
    }
    else if(sum3 == 0 && sum2 == 0)
        printf("%d", sum1);
    return 0;
}