#include<stdlib.h>
#include<stdio.h>
#include<string.h>
// 0C 1M 2E 3A
struct student{
    char id[7];
    int Subject[4];
    int Rank[4];
    int Best_Rank;
    char Best_Subject;
}stu[2001];

int min4(int a, int b, int c, int d){
    int tmp = a;
    if(tmp > b)
        tmp = b;
    if(tmp > c)
        tmp = c;
    if(tmp > d)
        tmp = d;
    return tmp;
}

void rank(int total_number, struct student *stu){
    for(int subject = 0; subject < 4; subject++){
        for(int i = 0; i < total_number; i++){
            for(int j = 0; j < total_number; j++){
                if(stu[i].Subject[subject] < stu[j].Subject[subject])
                    stu[i].Rank[subject]++;
            }
        }
    }
    for(int i = 0; i < total_number; i++){
        stu[i].Best_Rank = min4(stu[i].Rank[0], stu[i].Rank[1], stu[i].Rank[2], stu[i].Rank[3]);
        if(stu[i].Rank[3] == stu[i].Best_Rank)
            stu[i].Best_Subject = 'A';
        else if(stu[i].Rank[0] == stu[i].Best_Rank)
            stu[i].Best_Subject = 'C';
        else if(stu[i].Rank[1] == stu[i].Best_Rank)
            stu[i].Best_Subject = 'M';
        else if(stu[i].Rank[2] == stu[i].Best_Rank)
            stu[i].Best_Subject = 'E';
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s %d %d %d", stu[i].id, &stu[i].Subject[0], &stu[i].Subject[1], &stu[i].Subject[2]);
        stu[i].Subject[3] = (stu[i].Subject[0] + stu[i].Subject[1] + stu[i].Subject[2]) / 3;
        for(int subject = 0; subject < 4; subject++)
            stu[i].Rank[subject] = 1;
    }
    rank(n, stu);
    char check[2001][7];
    int count = 0;
    for(int i = 0; i < m; i++)
        scanf("%s", check[i]);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(strcmp(check[i], stu[j].id) == 0){
                printf("%d %c\n", stu[j].Best_Rank, stu[j].Best_Subject);
                break;
            }
            count++;
        }
        if(count == n)
            printf("N/A\n");
        count = 0;
    }         
}