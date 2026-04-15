#include<stdlib.h>
#include<stdio.h>
#include<math.h>

long long number2radix_reversed(int number, int radix){
    long long result_radix = 0;
    do{
        result_radix = result_radix * 10 + number % radix;
        number = number / radix;
    }while(number != 0);
    return result_radix;
}

int radix2decimal(long long number, int radix){
    long long reserved = 0;
    while(number != 0){
        reserved = reserved * 10 + number % 10;
        number = number / 10;
    }
    int result_decimal = 0;
    do{
        result_decimal = result_decimal * radix + reserved % 10;
        reserved = reserved / 10;
    }while(reserved != 0);
    return result_decimal;
}

int judge(int decimal){
    if(decimal <= 1)
        return -1;
    for(int i = 2; i <= sqrt(decimal); i++){
        if(decimal % i == 0){
            return -1;
        }
    }
    return 1;
}

int main(){
    int n, d, result[1000] = {0};
    int j = 0;
    while(1){
        scanf("%d", &n);
        if(n < 0){
            for(int i = 0; result[i] != 0; i++)
                if(result[i] == 1)
                    printf("Yes\n");
                else
                    printf("No\n");
            exit(0);
        }
        scanf("%d", &d);
        if(judge(n) == 1 && judge(radix2decimal(number2radix_reversed(n, d), d)) == 1)
            result[j++] = 1;
        else
            result[j++] = -1;
    }
    return 0;
}