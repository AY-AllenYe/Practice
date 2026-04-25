#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int price_per_hour[24];
int lasting_every_hour[24];
int record_numbers;
int count_valid = 0;

struct record{
    char name[21];
    char time[12];
    char status[9];
}customer_records[1002], customer_records_sorted[1002];

struct record_output{
    char name[21];
    char month[3];
    char begin[1001][9];
    char end[1001][9];
    int count;
    int minute_sum[1001];
    double price[1001];
}customer_records_output[1001];

int char2integer(char n1, char n2){
    int tmp_int;
    tmp_int = (n1 - '0') * 10 + (n2 - '0');
    return tmp_int;
}

void cleararray(int* lasting_every_hour){
    for(int i = 0; i < 24; i++){
        lasting_every_hour[i] = 0;
    }
}

int* last_time(char* begin_time, char* end_time){
    int day, hour, minute;
    int day_begin = char2integer(begin_time[0], begin_time[1]), day_end = char2integer(end_time[0], end_time[1]);
    int hour_begin = char2integer(begin_time[3], begin_time[4]), hour_end = char2integer(end_time[3], end_time[4]);
    int minute_begin = char2integer(begin_time[6], begin_time[7]), minute_end = char2integer(end_time[6], end_time[7]);
    day = day_end - day_begin;
    hour = hour_end - hour_begin;
    minute = minute_end - minute_begin;
    if(day == 0){
        if(hour == 0){
            lasting_every_hour[hour_begin] = minute;
        }else{
            lasting_every_hour[hour_begin] = 60 - minute_begin;
            for(int i = hour_begin + 1; i < hour_end; i++){
                lasting_every_hour[i] = 60;
            }
            lasting_every_hour[hour_end] = minute_end - 0;
        }
    }else{
        if(hour < 0){
            lasting_every_hour[hour_begin] = 60 * day - minute_begin;
            for(int i = hour_begin + 1; i < 24; i++){
                lasting_every_hour[i] = 60 * day;
            }
            lasting_every_hour[hour_end] = 60 * (day - 1) + minute_end - 0;
        }else if(hour == 0){
            for(int i = 0; i < 24; i++){
                lasting_every_hour[i] = 60 * day;
            }
            lasting_every_hour[hour_begin] = lasting_every_hour[hour_begin] + minute;
        }else{
            for(int i = 0; i < 24; i++){
                lasting_every_hour[i] = 60 * day;
            }
            lasting_every_hour[hour_begin] = lasting_every_hour[hour_begin] + 60 - minute_begin;
            for(int i = hour_begin + 1; i < hour_end; i++){
                lasting_every_hour[i] = lasting_every_hour[i] + 60;
            }
            lasting_every_hour[hour_end] = lasting_every_hour[hour_end] + minute_end - 0;
        }
    }
    return lasting_every_hour;
}

int minute_sum(int* lasting_every_hour){
    int minute = 0;
    for(int i = 0; i < 24; i++){
        minute = minute + lasting_every_hour[i];
    }
    return minute;
}

double price_calculate(int* lasting_every_hour, int* price_per_hour){
    double price = 0.0;
    for(int i = 0; i < 24; i++){
        price = price + lasting_every_hour[i] * price_per_hour[i] / 100.0;
    }
    return price;
}

/*
char* integer2char(int n){
    static char tmp_char[2];
    if(0 <= n && n <= 9){
        tmp_char[0] = '0';
        tmp_char[1] = n + '0';
    }else{
        tmp_char[0] = (n / 10) % 10 + '0';
        tmp_char[1] = n % 10 + '0';
    }
    return tmp_char;
}
*/

int main(){
    for(int i = 0; i < 24; i++)
        scanf("%d", &price_per_hour[i]);
    scanf("%d", &record_numbers);
    for(int i = 0; i < record_numbers; i++){
        scanf("%s %s %s", customer_records[i].name, customer_records[i].time, customer_records[i].status);
    }

    for(int i = 0; i < record_numbers - 1; i++){
        for(int j = 0; j < record_numbers - i - 1; j++){
            if(strcmp(customer_records[j].status, customer_records[j + 1].status) < 0){
                customer_records[1001] = customer_records[j];
                customer_records[j] = customer_records[j + 1];
                customer_records[j + 1] = customer_records[1001];
            }
        }
    }
    for(int i = 0; i < record_numbers - 1; i++){
        for(int j = 0; j < record_numbers - i - 1; j++){
            if(strcmp(customer_records[j].time, customer_records[j + 1].time) > 0){
                customer_records[1001] = customer_records[j];
                customer_records[j] = customer_records[j + 1];
                customer_records[j + 1] = customer_records[1001];
            }
        }
    }
    for(int i = 0; i < record_numbers - 1; i++){
        for(int j = 0; j < record_numbers - i - 1; j++){
            if(strcmp(customer_records[j].name, customer_records[j + 1].name) > 0){
                customer_records[1001] = customer_records[j];
                customer_records[j] = customer_records[j + 1];
                customer_records[j + 1] = customer_records[1001];
            }
        }
    }

    for(int i = 1; i < record_numbers; i++){
        if(strcmp(customer_records[i].name, customer_records[i - 1].name) == 0){
            if(strcmp(customer_records[i - 1].status, "on-line") == 0 && strcmp(customer_records[i].status, "off-line") == 0){
                customer_records_sorted[count_valid++] = customer_records[i - 1];
            }else if(strcmp(customer_records[i - 1].status, "on-line") == 0 && strcmp(customer_records[i].status, "on-line") == 0){
                continue;
            }else if(strcmp(customer_records[i - 1].status, "off-line") == 0 && strcmp(customer_records[i].status, "on-line") == 0){
                if(strcmp(customer_records_sorted[count_valid - 1].status, "on-line") == 0){
                    customer_records_sorted[count_valid++] = customer_records[i - 1];
                }else{
                    continue;
                }
            }else if(strcmp(customer_records[i - 1].status, "off-line") == 0 && strcmp(customer_records[i].status, "off-line") == 0){
                i = i + 1;
                continue;
            }
        }else{
            customer_records_sorted[count_valid++] = customer_records[i - 1];
        }
    }
    if(strcmp(customer_records[record_numbers - 1].status, "off-line") == 0){
        customer_records_sorted[count_valid++] = customer_records[record_numbers - 1];
    }
    
    int user_index = 0;
    cleararray(lasting_every_hour);
    strcpy(customer_records_output[0].name, customer_records_sorted[0].name);
    strncpy(customer_records_output[0].month, customer_records_sorted[0].time, 2);
    for(int i = 0; i < count_valid; i = i + 2){
        char tmp1[3], tmp2[3];
        cleararray(lasting_every_hour);
        strcpy(customer_records_output[user_index].name, customer_records_sorted[i].name);
        strncpy(customer_records_output[user_index].month, customer_records_sorted[i].time, 2);
        strncpy(tmp1, customer_records_sorted[i].time, 2);
        strncpy(tmp2, customer_records_sorted[i + 2].time, 2);
        tmp1[2] = '\0';
        tmp2[2] = '\0';
        while(strcmp(customer_records_sorted[i].name, customer_records_sorted[i + 2].name) == 0 && strcmp(tmp1, tmp2) == 0){
            strncpy(customer_records_output[user_index].begin[customer_records_output[user_index].count], customer_records_sorted[i].time + 3, 8);
            strncpy(customer_records_output[user_index].end[customer_records_output[user_index].count], customer_records_sorted[i + 1].time + 3, 8);
            
            customer_records_output[user_index].minute_sum[customer_records_output[user_index].count] = minute_sum(
                    last_time(customer_records_output[user_index].begin[customer_records_output[user_index].count], customer_records_output[user_index].end[customer_records_output[user_index].count]));
            customer_records_output[user_index].price[customer_records_output[user_index].count] = price_calculate(
                    last_time(customer_records_output[user_index].begin[customer_records_output[user_index].count], customer_records_output[user_index].end[customer_records_output[user_index].count]), price_per_hour);
            
                    cleararray(lasting_every_hour);
            customer_records_output[user_index].count++;
            i = i + 2;
            strncpy(tmp1, customer_records_sorted[i].time, 2);
            strncpy(tmp2, customer_records_sorted[i + 2].time, 2);
        }
        strncpy(customer_records_output[user_index].begin[customer_records_output[user_index].count], customer_records_sorted[i].time + 3, 8);
        strncpy(customer_records_output[user_index].end[customer_records_output[user_index].count], customer_records_sorted[i + 1].time + 3, 8);
        
        customer_records_output[user_index].minute_sum[customer_records_output[user_index].count] = minute_sum(
                last_time(customer_records_output[user_index].begin[customer_records_output[user_index].count], customer_records_output[user_index].end[customer_records_output[user_index].count]));
        customer_records_output[user_index].price[customer_records_output[user_index].count] = price_calculate(
                last_time(customer_records_output[user_index].begin[customer_records_output[user_index].count], customer_records_output[user_index].end[customer_records_output[user_index].count]), price_per_hour);
        
        // for(int i = 0; i<24;i++){
        //     printf("%d ", lasting_every_hour[i]);
        // }
        // printf("\n");
        cleararray(lasting_every_hour);
        customer_records_output[user_index].count++;
        user_index++;
    }

    /*
    int j = 0;
    strcpy(customer_records_output[0].name, customer_records_sorted[0].name);
    strncpy(customer_records_output[0].month, customer_records_sorted[0].time, 2);
    for(int i = 0; i < count_valid - 2; i = i + 2){
        char tmp1[3];
        char tmp2[3];
        strncpy(customer_records_output[(i - j) / 2].time[j], customer_records_sorted[i].time + 3, 8);
        strncpy(customer_records_output[(i - j) / 2].time[j + 1], customer_records_sorted[i + 1].time + 3, 8);
        if(strcmp(customer_records_sorted[i].name, customer_records_sorted[i + 2].name) == 0){
            strncpy(tmp1, customer_records_sorted[i].time, 2);
            strncpy(tmp2, customer_records_sorted[i + 2].time, 2);
            if(strcmp(tmp1, tmp2) == 0){
                j = j + 2;
            }else{
                customer_records_output[i - j].count = (j + 2) / 2;
                strncpy(customer_records_output[(i - j) / 2].time[j], customer_records_sorted[i].time + 3, 8);
                strncpy(customer_records_output[(i - j) / 2].time[j + 1], customer_records_sorted[i + 1].time + 3, 8);
                j = 0;
                strcpy(customer_records_output[(i + 2) / 2].name, customer_records_sorted[i + 2].name);
                strncpy(customer_records_output[(i + 2) / 2].month, customer_records_sorted[i + 2].time, 2);
            }
        }else{
            customer_records_output[i].count = (j + 2) / 2;
            j = 0;
            strcpy(customer_records_output[(i + 2) / 2].name, customer_records_sorted[i + 2].name);
            strncpy(customer_records_output[(i + 2) / 2].month, customer_records_sorted[i + 2].time, 2);
        }
        
    }
    strncpy(customer_records_output[count_valid / 2].time[j], customer_records_sorted[count_valid - 2].time + 3, 8);
    strncpy(customer_records_output[count_valid / 2].time[j + 1], customer_records_sorted[count_valid - 1].time + 3, 8);
    */

    //printf("总共%d条有效记录\n", count_valid);
    for(int i = 0; i < user_index; i++){
        if(customer_records_output[i].minute_sum[0] == 0 && customer_records_output[i].count == 1){
            customer_records_output[i].count--;
            continue;
        }
        printf("%s %s\n", customer_records_output[i].name, customer_records_output[i].month);
        // printf("***%d\n",customer_records_output[i].count);
        double price_sum = 0;
        for(int j = 0; j < customer_records_output[i].count; j++){
            if(customer_records_output[i].minute_sum[0] == 0 && customer_records_output[i].count == 1){
                customer_records_output[i].count--;
                continue;
            }
            printf("%s %s %d $%.2f\n", customer_records_output[i].begin[j], customer_records_output[i].end[j], customer_records_output[i].minute_sum[j], customer_records_output[i].price[j]);
            price_sum = price_sum + customer_records_output[i].price[j];
        }
        printf("Total amount: $%.2f\n", price_sum);
    }
    // printf("%d\n", minute_sum(lasting_every_hour));
    // printf("%.2f\n", price_calculate(lasting_every_hour, price_per_hour));
    return 0;
}