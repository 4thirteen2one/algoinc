#include <stdio.h>
#define MAXV 100
#define MAXE 4950
#define INF 65535

typedef struct {
    int vertices[MAXV];         //顶点表
    int edges[MAXV][MAXV];      //边权表
    int num_v, num_e;
} MGraph;

void GenMGraph(MGraph &G) {
    G.num_e = 15;
    G.num_v = 9;
    for (int i = 0; i < G.num_v; i++) {                 //初始化图
        for (int j = 0; j < G.num_v; j++) {
            if(i == j)
                G.edges[i][j] = 0;                      //简单图
            else
                G.edges[i][j] = G.edges[j][i] = INF;    //两顶点不相邻接
        }
    }

    G.edges[0][1] = 10;
    G.edges[0][5] = 11;
    G.edges[1][2] = 18;
    G.edges[1][6] = 16;
    G.edges[1][8] = 12;
    G.edges[2][3] = 22;
    G.edges[2][8] = 8;
    G.edges[3][4] = 20;
    G.edges[3][6] = 24;
    G.edges[3][7] = 16;
    G.edges[3][8] = 21;
    G.edges[4][5] = 26;
    G.edges[4][7] = 7;
    G.edges[5][6] = 17;
    G.edges[6][7] = 19;

    for(int i = 0; i < G.num_v; i++)
        for(int j = i; j < G.num_v; j++)
            G.edges[j][i] = G.edges[i][j];
}

int MST_Prim(MGraph G, int s) {
    int sum = 0;                                                //MST边权之和
    int closest[G.num_v];                                       //存储MST中与各顶点距离最近的顶点序号
    int lowcost[G.num_v];                                       //记录各顶点到MST的距离
    for(int i = 0; i < G.num_v; i++) {                          //初始化closest和lowcost
        closest[i] = s;                                         //各顶点离MST最近的点
        lowcost[i] = G.edges[s][i];                             //各顶点到MST的距离
    }
    for(int i = 1; i < G.num_v; i++) {                          //MST有num_v-1条边
        int u;                                                  //u记录与MST最近顶点的序号
        int MIN = INF;
        for(int j = 0; j < G.num_v; j++)                        //在(V-U)中找出离U最近的顶点u
            if(lowcost[j]!=0 && lowcost[j]<MIN) {               //该顶点未加入MST，且到MST的距离更小
                MIN = lowcost[j];
                u = j;              
            }                       
        sum += lowcost[u];                                      //更新MST边权之和
        printf("边(%d, %d)的权为：%d\n", closest[u], u, MIN);
        lowcost[u] = 0;                                         //标记u已经加入U
        for(int v = 0; v < G.num_v; v++)                        //遍历所有顶点
            if(G.edges[u][v]!=0 && G.edges[u][v]<lowcost[v]) {  //v与顶点u关联且边权小于s到u
                closest[v] = u;                                 //MST中与顶点v距离最近的顶点变更为u
                lowcost[v] = G.edges[u][v];                     //顶点v到MST的距离变为边(u,v)的权
            }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    MGraph M;
    GenMGraph(M);
    for (int i = 0; i < M.num_v; i++) {
        int sum = MST_Prim(M, i);
        printf("边权之和：%d\n", sum);
    }
    return 0;
}
