#include<stdlib.h>
#include<stdio.h>
const int INF = 0x3fffffff; //一个很大的数 
int n, m, k, check;
int g[1000][1000]; //邻接矩阵 
int visited[1000] = {0}; //记录某个城市是否被访问

void dfs(int u) {
    if(u == check) //check代表被删除的城市，所以直接返回 
        return;
    visited[u] = 1;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0 && g[u][i] != INF)
            dfs(i);
    }
}

int main(){
    for(int i = 0; i < 1000; i++)
        for(int j = 0; j < 1000; j++)
            g[i][j] = INF;
    scanf("%d %d %d", &n, &m, &k);
    int a, b;
    for(int i = 0; i < m; i++) { //建立图 
        scanf("%d %d", &a, &b);
        g[a][b] = 0;
        g[b][a] = 0;
    }
    for(int i = 0; i < k; i++) {
        int num = 0; //每删除一个新的城市要将num重新置零 
        for(int j = 0; j < 1000; j++)
            visited[j] = 0;
        scanf("%d", &check);
        for(int j = 1; j <= n; j++) {
            if(visited[j] == 0 && j != check) {
                dfs(j);
                num++; //统计连通图个数 
            }
        }
        printf("%d\n", num - 1);
    }
    return 0;
}