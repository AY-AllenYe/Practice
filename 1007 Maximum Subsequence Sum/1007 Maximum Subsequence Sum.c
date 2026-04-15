#include<stdlib.h>
#include<stdio.h>

int main(){
    int k, n[10000];
    int start = 0;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &n[i]);
    }
    int sum = 0, sum_max = 0;
    int count = 0, count_max = 0, count_neg = 0, count_zero = 0;
    for(int i = 0; i < k; i++){
        for(int j = i; j < k; j++){
            if(n[j] < 0 && count == 0){
                count_neg++;
                break;
            }
            if(n[j] == 0 && count == 0){
                count_zero++;
                break;
            }
            sum += n[j];
            count++;
            if(sum_max < sum){
                sum_max = sum;
                start = i;
                count_max = count;
            }
        }
        if(count_neg == k){
            printf("%d %d %d", sum_max, n[0], n[k - 1]);
            return 0;
        }
        if(count_neg + count_zero == k){
            printf("%d %d %d", sum_max, 0, 0);
            return 0;
        }
        count = 0;
        sum = 0;
    }
    printf("%d %d %d", sum_max, n[start], n[start + count_max - 1]);
    return 0;
}
