#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;
 
vector<int> tree[100];                              //二维数组 存放家族树(100个vector<int>)
int num[100] = {0};                                 //记录每一层的叶子数
int maxDepth = 1;                                   //记录最大深度
void dfs(int node, int depth){
    if(tree[node].size() == 0){                     //若为叶节点
        num[depth]++;
        maxDepth = max(depth, maxDepth);
        return;
    }
    for(int i = 0; i < tree[node].size(); i++){     //遍历所有子节点
        dfs(tree[node][i], depth+1);
    }
}
 
int main(){
    int n, m;                                       //n:节点总数，m：不含叶节点的节点总数
    scanf("%d%d", &n, &m);
    int id, k, id_;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &id_);
            tree[id].push_back(id_);
        }
    }
    dfs(1, 1);                                      //起始节点从01开始计数；深度起始为1
    printf("%d", num[1]);
    for(int i = 2; i <= maxDepth; i++){
        printf(" %d", num[i]);
    }
}
