#include<stdlib.h>
#include<stdio.h>

int time2number(char time[9]){
    int hours, minutes, seconds;
    hours = (time[0] - '0') * 10 + (time[1] - '0');
    minutes = (time[3] - '0') * 10 + (time[4] - '0');
    seconds = (time[6] - '0') * 10 + (time[7] - '0');
    return hours * 3600 + minutes * 60 + seconds;
}

int main(){
    int m;
    int earliest = 24 * 3600, latest = 0;
    int earliest_flag, latest_flag;
    char ID_number[9999][16], Sign_in_time[9], Sign_out_time[9];
    int tmp;
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%s %s %s", ID_number[i], Sign_in_time, Sign_out_time);
        tmp = time2number(Sign_in_time);
        if(tmp < earliest){
            earliest = tmp;
            earliest_flag = i;
        }
        tmp = time2number(Sign_out_time);
        if(tmp > latest){
            latest = tmp;
            latest_flag = i;
        }
    }
    printf("%s", ID_number[earliest_flag]);
    printf(" ");
    printf("%s", ID_number[latest_flag]);
    return 0;
}
