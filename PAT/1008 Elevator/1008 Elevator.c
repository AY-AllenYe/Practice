#include<stdlib.h>
#include<stdio.h>

int MoveUp_time = 6;
int MoveDown_time = 4;
int Stay_time = 5;

int main(){
    int n, floor[101];
    for(int i = 0; i < 101; i++){
        floor[i] = 0;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &floor[i]);
    }
    int current_floor = 0, total_time = 0, tmp;
    for(int i = 0; i < n; i++){
        tmp = floor[i] - current_floor;
        if(tmp > 0){
            total_time += tmp * MoveUp_time;
        }else{
            total_time -= tmp * MoveDown_time;
        }
        total_time += Stay_time;
        current_floor = floor[i];
    }
    printf("%d", total_time);
    return 0;
}
