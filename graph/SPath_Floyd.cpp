/**
* Floyd算法：解决全源最短路径问题
**/
#include <cstdio>

const int INF = 1000000000;
const int MAXV = 100; //最大顶点数

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

void SPath_Floyd(MGraph G, int pathM[][MAXV], int distM[][MAXV]) {
    for (int i = 0; i < G.num_v; i++)
        for (int j = 0; j < G.num_v; j++) {
            distM[i][j] = G.edges[i][j];
            pathM[i][j] = j;
        }
    for (int k = 0; k < G.num_v; k++)
        for (int i = 0; i < G.num_v; i++)
            for (int j = 0; j < G.num_v; j++)
                if (distM[i][k] + distM[k][j] < distM[i][j]) {
                    distM[i][j] = distM[i][k] + distM[k][j];
                    pathM[i][j] = pathM[i][k];
                }
}

int main() {
    MGraph G;
    GenMGraph(G);
    int distM[MAXV][MAXV];
    int pathM[MAXV][MAXV];
    SPath_Floyd(G, pathM, distM);
    printf("距离矩阵：\n");
    for (int i = 0; i < G.num_v; i++) {
        for (int j = 0; j < G.num_v; j++) {
            printf("%2d ", distM[i][j]);
        }
        printf("\n");
    }
    printf("前驱矩阵：\n");
    for (int i = 0; i < G.num_v; i++) {
        for (int j = 0; j < G.num_v; j++) {
            printf("%2d ", pathM[i][j]);
        }
        printf("\n");
    }
    return 0;
}
