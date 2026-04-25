#include<stdlib.h>
#include<stdio.h>

int main(){
    int n, m;
    int id, ID[100];
    int k[100], count = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= 100; i++){
        k[i] = 0;
        ID[i] = 0;
    }
    if(n <= 0){
        exit(0);
    }else if(n == 1){
        printf("1");
    }else{
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &id, &k[i]);
            for(int j = 1; j <= k[i]; j++){
                scanf("%d", &ID[j]);
            }
        }
        printf("0");
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= k[i]; j++){
                if(k[j] != 0){
                    count++;
                }else{
                    continue;
                }
            }
            printf(" %d", count);
            count = 0;
        }
    }
    return 0;
}