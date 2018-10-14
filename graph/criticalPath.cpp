#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int VertexType;         //顶点的数据类型不同情况不一样
typedef int EdgeType;           //整数表示权值或者连通性
#define MAXV 100                //图中顶点数目的最大值
#define MAXE 4950
#define INF 65535

//邻接矩阵
typedef struct {
    VertexType vertices[MAXV];  //顶点表
    EdgeType edges[MAXV][MAXV]; //边权表
    int num_v, num_e;           //图的顶点数和弧数
} MGraph;

//邻接表
typedef struct EdgeNode {       //边表结点
    int adjvex;                 //该弧所指向的顶点的位置
    int weight;
    struct EdgeNode *next;      //指向下一条弧的指针
} EdgeNode;

typedef struct VertexNode {     //顶点表结点
    VertexType nu;              //顶点信息
    int indgree, outdegree;
    EdgeNode *firstedge;        //单链表头指针
} VertexNode, AdjList[MAXV];    //AdjList 是结构体数组类型

typedef struct {
    AdjList adjlist;            //邻接表
    int num_v, num_e;           //图的顶点数和弧数
} ALGraph;                      //ALGraph 是以邻接表存储的图类型

void GenMGraph(MGraph &G) {
    G.num_v = 10;
    G.num_e = 13;
    for (int i = 0; i < G.num_v; i++) {                 //初始化图
        G.vertices[i] = i;
        for (int j = 0; j < G.num_v; j++) {
            if(i == j)
                G.edges[i][j] = 0;                      //简单图
            else
                G.edges[i][j] = G.edges[j][i] = INF;    //两顶点不相邻接
        }
    }

    G.edges[0][1] = 3;
    G.edges[0][2] = 4;
    G.edges[1][3] = 5;
    G.edges[1][4] = 6;
    G.edges[2][3] = 8;
    G.edges[2][5] = 7;
    G.edges[3][4] = 3;
    G.edges[4][6] = 9;
    G.edges[4][7] = 4;
    G.edges[5][7] = 6;
    G.edges[6][9] = 2;
    G.edges[7][8] = 5;
    G.edges[8][9] = 3;
}

void M2ALGraph(MGraph &M, ALGraph &AL) {
    EdgeNode *p;                                        //临时边表顶点指针
    AL.num_v = M.num_v;
    AL.num_e = M.num_e;
    for(int i = 0; i < AL.num_v; i++) {                 //初始化入度和出度
        AL.adjlist[i].indgree = 0;
        AL.adjlist[i].outdegree = 0;
    }
    for(int i = 0; i < AL.num_v; i++) {                 //对每个顶点
        AL.adjlist[i].nu = M.vertices[i];               //复制其序号
        AL.adjlist[i].firstedge = NULL;                 //将其边表置空
        for(int j = 0; j < AL.num_v; j++) {             //录入其邻接点
            if(M.edges[i][j] != 0 && M.edges[i][j]!=INF) {
                p = (EdgeNode *)malloc(sizeof(EdgeNode));
                p->adjvex = j;                          //指向邻接顶点j
                (*p).weight = M.edges[i][j];            //边<i,j>的权值
                p->next = AL.adjlist[i].firstedge;      //备份指向顶点i的当前首边的指针
                AL.adjlist[i].firstedge = p;            //将当前顶点的指针指向p
                AL.adjlist[j].indgree++;
                AL.adjlist[i].outdegree++;              //跟新当前顶点的入度和出度
            }
        }
    }
    for (int i = 0; i < AL.num_v; i++) {
        printf("%2d: (id = %d, od = %d) ",
            AL.adjlist[i].nu, AL.adjlist[i].indgree, AL.adjlist[i].outdegree);
        for(EdgeNode *e = AL.adjlist[i].firstedge; e; e = e->next) {
            printf("%d", e->adjvex);
            if (e != NULL) printf(" ");
            else printf("\n");
        }
        printf("\n");
    }
}

bool topologicalSort(ALGraph AL, int *topoSq) {
    int count = 0;                                  //记录已加入拓扑序列的顶点数
    int in[AL.num_v];                               //备份各顶点的入度
    for (int i = 0; i < AL.num_v;i++)
        in[i] = AL.adjlist[i].indgree;
    int *zeroin;                                    //保存各入度为0的顶点序号的栈
    zeroin = (int *)malloc(AL.num_v*sizeof(int));   //为栈zeroin分配空间
    int top0in = -1;                                //初始化栈为空
    for(int i = 0; i < AL.num_v; i++)
        if(in[i] == 0)
            zeroin[++top0in] = i;                   //将入度为0的顶点的序号入栈

    while(top0in > -1) {                            //当栈不为空时循环
        int u = zeroin[top0in--];                    //栈顶元素（即顶点序号）出栈
        topoSq[count++] = u;                     //将该顶点加入拓扑序列中
        for(EdgeNode *e = AL.adjlist[u].firstedge; e; e = e->next) {
            int v = e->adjvex;                      //当前栈顶顶点的各邻接顶点v
            if(!(--in[v]))                          //将顶点v的入度减1
                zeroin[++top0in] = v;               //如果减1后为0，则入栈
        }
    }
    if (count == AL.num_v) {
        for(int i = 0; i < AL.num_v; i++) {
            printf("%d", topoSq[i]);
            if (i < AL.num_v-1) printf(" ");
            else printf("\n");
        }
        return true;                                //加入拓扑序列的顶点数为v，拓扑排序成功
    } else
        return false;                               //加入拓扑序列的顶点数小于v，拓扑排序失败
}

int criticalPath(ALGraph &AL, int *topoSq) {
    int etv[AL.num_v], ltv[AL.num_v];               //事件的最早发生时间和最迟发生时间
    int toptQ = -1;
    if (!topologicalSort(AL, topoSq)) 
        return -1;                                  //不是有向无环图，返回-1
    else toptQ = AL.num_v-1;                        //指向拓扑序列栈的栈顶

    for (int i = 0; i < AL.num_v; i++)
        etv[i] = 0;                                 //etv数组初始化
    for (int i = 0; i < AL.num_v; i++) {            //按拓扑次序求etv
        int u = topoSq[i];                          //栈底元素u
        for(EdgeNode *e = AL.adjlist[u].firstedge; e; e = e->next) {
            int v = e->adjvex;                      //当前顶点u的各邻接顶点v
            if (etv[u]+e->weight > etv[v])
                etv[v] = etv[u] + e->weight;        //用etv[u]来更新各etv[v]
        }
    }

    for (int i = 0; i < AL.num_v; i++)
        ltv[i] = etv[AL.num_v-1];                   //ltv数组初始化，初始值为汇点的etv值
    while (toptQ > -1) {                            //按逆拓扑次序求ltv
        int u = topoSq[toptQ--];                    //栈顶元素u
        for(EdgeNode *e = AL.adjlist[u].firstedge; e; e = e->next) {
            int v = e->adjvex;                      //当前顶点u的各邻接顶点v
            if (ltv[v]-e->weight < ltv[u])
                ltv[u] = ltv[v] - e->weight;        //用各ltv[v]来更新ltv[u]
        }
    }
    printf("\n各顶点的etv和ltv：\n");
    for (int i = 0; i < AL.num_v; i++)
        printf("%2d: etv = %2d, ltv = %2d\n", i, etv[i], ltv[i]);
    //遍历邻接表的所有边，计算活动的最早开始时间ete和最迟开始时间lte
    for (int u = 0; u < AL.num_v; u++) {
        for(EdgeNode *e = AL.adjlist[u].firstedge; e; e = e->next) {
            int v = e->adjvex;                      //当前顶点u的各邻接顶点v
            int ete = etv[u];                       //弧e的最早发生时间=弧头u的最早发生时间
            int lte = ltv[v] - e->weight;           //弧e的最晚发生时间=弧尾v的最晚发生时间-弧权
            if (ete == lte)
                printf("%2d->%2d: %2d\n", u, v, e->weight); //输出关键活动
        }
    }
    return etv[AL.num_v-1]; //返回关键路径长度
}

int main(int argc, char const *argv[]) {
    MGraph M;
    ALGraph AL;
    GenMGraph(M);
    M2ALGraph(M, AL);
    int topoSq[AL.num_v];                           //拓扑序列
    int len = criticalPath(AL, topoSq);
    cout << "\n" << len;
    return 0;
}

