#include<stdlib.h>
#include<stdio.h>

double win[3], draw[3], lose[3];
char result[3];

double max3(double a, double b, double c){
    if (a > b)
        if(a > c)
            return a;
        else
            return c;
    else
        if(b > c)
            return b;
        else
            return c;
}

int main(){
    double profit = 1.0, maximum = 1.0;
    for(int i = 0; i < 3; i++){
        scanf("%lf %lf %lf", &win[i], &draw[i], &lose[i]);
        maximum = max3(win[i], draw[i], lose[i]);
        if(maximum == win[i]){
            result[i] = 'W';
        }else if(maximum == draw[i]){
            result[i] = 'T';
        }else{
            result[i] = 'L';
        }
        profit *= maximum;
    }
    profit = (profit * 0.65 - 1) * 2;
    for(int i = 0; i < 3; i++)
        printf("%c ", result[i]);
    printf("%.2f", profit);
    return 0;
}