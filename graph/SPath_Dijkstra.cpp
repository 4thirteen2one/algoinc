#include <stdio.h>
#include <stdbool.h>
#define MAXV 100
#define MAXE 4950
#define INF 65535

typedef struct {
    int vertices[MAXV];         //顶点表
    int edges[MAXV][MAXV];      //边权表
    int num_v, num_e;
} MGraph;

void GenMGraph(MGraph &G) {
    G.num_v = 9;
    G.num_e = 16;
    for (int i = 0; i < G.num_v; i++) {                 //初始化图
        for (int j = 0; j < G.num_v; j++) {
            if(i == j)
                G.edges[i][j] = 0;                      //简单图
            else
                G.edges[i][j] = G.edges[j][i] = INF;    //两顶点不相邻接
        }
    }

    G.edges[0][1]=1;
    G.edges[0][2]=5; 
    G.edges[1][2]=3; 
    G.edges[1][3]=7; 
    G.edges[1][4]=5; 

    G.edges[2][4]=1; 
    G.edges[2][5]=7; 
    G.edges[3][4]=2; 
    G.edges[3][6]=3; 
    G.edges[4][5]=3;

    G.edges[4][6]=6;
    G.edges[4][7]=9; 
    G.edges[5][7]=5; 
    G.edges[6][7]=2; 
    G.edges[6][8]=7;

    G.edges[7][8]=4;

    for(int i = 0; i < G.num_v; i++)
        for(int j = i; j < G.num_v; j++)
            G.edges[j][i] = G.edges[i][j];
}

void DFS(int s, int v, int *pre) {          //s为源点，v为终点（从终点开始递归）
    if(v==s) {                              //若当前已经到达源点s，则输出源点并返回
        printf("%d ", s);
        return;
    }
    DFS(s, pre[v], pre);                    //递归访问v的前驱顶点pre[v]
    printf("%d ", v);                       //从最深处return，输出每一层的顶点
}

void SPath_Dijkstra(MGraph G, int s) {
    int dist[G.num_v];                      //从源点s到各顶点i的最短路径长度
    int pre[G.num_v];                       //从源点s到顶点i的最短路径上i的前一个顶点
    bool flag[G.num_v];                     //标记数组，flag[i]==true表示已访问
    for (int i = 0; i < G.num_v; i++) {
        flag[i] = false;
        dist[i] = G.edges[s][i];            //距离初始化
        if(G.edges[s][i] < INF)
            pre[i] = s;                     //源点s与顶点i邻接时，设i的前驱顶点为s
        else
            pre[i] = -1;                    //源点s不与顶点i邻接时，i的前驱顶点未知
    }
    flag[s] = true;                         //标记s已访问
    for (int i = 0; i < G.num_v; i++) {
        int u = 0, MIN = INF;               //u是干嘛的？
        for (int j = 0; j < G.num_v; j++)   //挑选未访问且当前与s点距离最短的顶点u
            if (flag[j]==false && dist[j]<MIN) {
                MIN = dist[j];
                u = j;
            }
        flag[u] = true;                     //标记u已访问
        for (int v = 0; v < G.num_v; v++)   //以u为中介点优化d[v]
            if (!flag[v] && G.edges[u][v]<INF && dist[u]+G.edges[u][v]<dist[v]) {
                dist[v] = dist[u] + G.edges[u][v];
                pre[v] = u;
            }
    }
    for (int i = 0; i < G.num_v; i++) {
        printf("%d -> ... -> %d -> %d: DISTANCE %2d, PATH ", s, pre[i], i, dist[i]);
        DFS(s, i, pre);
        printf("\n");
    }
}

int main(void) {
    MGraph M;
    GenMGraph(M);
    for (int i = 0; i < M.num_v; i++) {
        SPath_Dijkstra(M, i);  
        printf("\n");
    }
    return 0;
}