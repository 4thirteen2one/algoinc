#include <stdio.h>
#define MAXV 100
#define MAXE 4950
#define INF 65535

typedef struct {
    int vertices[MAXV];         //顶点表
    int edges[MAXV][MAXV];      //边权表
    int num_v, num_e;
} MGraph;

typedef struct {
    int head, tail, weight;
} EdgeType;                         //对边集数组Edge结构的定义

typedef struct {
    EdgeType edges[MAXE];
    int vCon[MAXV];                 //顶点连通集数组
    int num_v, num_e;
} eSet;

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

void MGraph2eSet(MGraph &M, eSet &E) {      //将邻接矩阵转化为边集数组
    E.num_v = M.num_v;
    E.num_e = M.num_e;
    int k = 0;
    for (int i = 0; i < M.num_v-1; i++)
        for (int j = i+1; j < M.num_v; j++)
            if (M.edges[i][j]!=0 && M.edges[i][j]!=INF) {
                E.edges[k].head = i;
                E.edges[k].tail = j;
                E.edges[k].weight = M.edges[i][j];
                E.vCon[k] = j;
                k++;
            }
}

void InsertSort(eSet &E) {
    int i, j;
    EdgeType temp;
    for(i = 1; i < E.num_e; i++) {
        temp = E.edges[i];
        j = i-1;
        while(j>=0 && temp.weight<E.edges[j].weight) {
            E.edges[j+1] = E.edges[j];          //将w大于E[i].w的记录后移
            j--;
        }
        E.edges[j+1] = temp;                    //在j+1处插入edges[i]
    }
}

int MST_Kruskal(eSet &E) {                   
    int ms = 0;                                 //边权之和
    InsertSort(E);                              //对eSet边集数组按权递增排序
    for(int i = 0; i < E.num_v; i++)
        E.vCon[i] = i;                          //各顶点初始化属于各点集
    int k = 0;                                  //当前生成树的边数
    int i = 0;                                  //已遍历边的边数
    while(k < E.num_v) {                        //生成边数小于num_v时循环
        int eh = E.edges[i].head;
        int et = E.edges[i].tail;               //取一条边的头尾顶点
        if(E.vCon[eh] != E.vCon[et]) {          //两顶点属不同集合
            for(int j = 0; j < E.num_v; j++)    //两个集合统一编号
                if(E.vCon[j] == E.vCon[et])
                    E.vCon[j] = E.vCon[eh];
            printf("edge (%d, %d): %d\n", eh, et, E.edges[i].weight);
            ms += E.edges[i].weight;
            k++;                                //生成边数增1
            if (k == E.num_v-1) break;
        }
        i++;                                    //扫描下一条边
    }
    if(k != E.num_v-1) return -1;
    else {
        printf("Num of MST edges = %d\n", k);
        return ms;
    }
}

/*
int findElder(int elder[], int x) {
    int y = x;              //先备份x结点
    while (x != elder[x])   //若不是根结点，继续循环
        x = elder[x];       //获得自己的父辈结点
    //路径压缩
    while(elder[y] != y) {  //把路径上所有结点的elder改为根结点
        int z = y;          //备份y
        y = elder[y];       //修改y为其父辈结点
        elder[z] = x;       //将原先y的父辈结点改为根结点x
    }
    return x;               //返回元素x所在集合的根结点
}

int Kruskal(eSet &E) {                   
    int ms = 0;                             //边权之和
    InsertSort(E);                          //对eSet数组按递增排序
    for(int i = 0; i < E.num_v; i++)
        E.vCon[i] = i;                      //各顶点集初始化
    int k = 0;
    for (int i = 0; i < E.num_e; i++) {
        int vsrh = findElder(E.vCon, E.edges[i].head);
        int vsrt = findElder(E.vCon, E.edges[i].tail);
        if(vsrh != vsrt) {
            E.vCon[vsrh] = E.vCon[vsrt];
            printf("edge (%d, %d): %d\n", 
                E.edges[i].head, E.edges[i].tail, E.edges[i].weight);
            ms += E.edges[i].weight;
            k++;
            if (k == E.num_v-1) break;
        }
    }
    if (k != E.num_v-1) return -1;
    else {
        printf("Num of MST edges = %d\n", k);
        return ms;
    }
}
*/

int main(void) {
    MGraph M;
    eSet E;
    GenMGraph(M);
    MGraph2eSet(M, E);
    printf("Num of edges = %d\n", E.num_e);
    int sum = MST_Kruskal(E);
    printf("Sum of weights: %d\n", sum);
    return 0;
}