#include<stdlib.h>
#include<stdio.h>
int n, m, C1, C2;
int rescue[500];
int dis[500][500], row= 0, column = 0;
int dis_min[500], count_path = 0, count_rescue;

void dfs(int cur_city, int cur_dis, int cur_rescue){
	if(cur_dis > dis_min[cur_city])
        return;
	if(cur_city == C2){ //到达目的地 
		if(cur_dis == dis_min[cur_city]){
			count_path++;
			if(cur_rescue > count_rescue){
                count_rescue = cur_rescue;
            }
		}else{
			dis_min[C2] = cur_dis;
			count_path = 1;
			count_rescue = cur_rescue;
		} //唯一最短路径，仅存在一条最短路径
	}else{ //未到达目的地 
		if(cur_dis < dis_min[cur_city]){
            dis_min[cur_city] = cur_dis;
        } //因为现在比原来小，所以要更新最短路径 
		for(int i = 0; i < n; i++){
			if(cur_city != i){
                dfs(i, cur_dis + dis[cur_city][i], cur_rescue + rescue[i]);
            }
		}
	}
}

int main(){
    scanf("%d%d%d%d", &n, &m, &C1, &C2);
    for(int i = 0; i < n; i++){
        scanf("%d", &rescue[i]);
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            dis[i][j] = 1000;
        }
        dis_min[i] = 1000;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &row, &column);
        scanf("%d", &dis[row][column]);
        dis[column][row] = dis[row][column];
    }
    dfs(C1, 0, rescue[C1]);
    printf("%d %d", count_path, count_rescue);
    return 0;
}