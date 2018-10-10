//Kruskal 算法

#define MAXE 495
#define MAXV 100
#define INF 65535

typedef struct {
    int edges[MAXV][MAXV];
    int num_v, num_e;
} MGraph;

typedef struct {
    int head;
    int tail;
    int weight;
} EdgeType; /* 对边集数组Edge结构的定义 */

void InsertSort(EdgeType eSet[],int num_e) {
    //对E[0..n-1]按w递增有序进行直接插入排序
    int i, j;
    EdgeType temp;
    for(i = 1; i < num_e; i++) {
        temp = eSet[i];
        j = i-1;    //从右向左在有序区E[0..i-1]中找E[i]的插入位置
        while(j>=0 && temp.weight<eSet[j].weight) {
            eSet[j+1] = eSet[j];    //将w大于E[i].w的记录后移
            j--;
        }
        eSet[j+1] = temp;           //在j+1处插入edges[i]
    }
}

int Kruskal(MGraph G) {
    int vSet[MAXV];                         //顶点连通集数组
    EdgeType eSet[MAXE];                    //边集数组
    int ms = 0;                             //边权之和
    //将邻接矩阵转化为边集数组
    int k = 0;
    for (int i = 0; i < G.num_v-1; i++)
        for (int j = i+1; j < G.num_v; j++)
            if (G.edges[i][j]!=0 && G.edges[i][j]!=INF) {
                eSet[k].head = i;
                eSet[k].tail = j;
                eSet[k].weight = G.edges[i][j];
                k++;
            }
    InsertSort(eSet, G.num_e);              //对eSet数组按递增排序
    for(int i = 0; i < G.num_v; i++)
        vSet[i] = i;                        //各顶点初始化属于各点集
    k = 1;  //k表示当前构造最小生成树的第几条边,初值为1
    int i = 0;
    while(k < G.num_v) {                    //生成边数小于num_v时循环
        int eh = eSet[i].head;
        int et = eSet[i].tail;                  //取一条边的头尾顶点
        if(vSet[eh] != vSet[et]) {              //两顶点属不同集合
            for(int j = 0; j < G.num_v; j++)    //两个集合统一编号
                if(vSet[j] == vSet[et])
                    vSet[j] = vSet[eh];         //将et所在集合归并到eh
            printf("edge (%d, %d): %d\n", eh, et, eSet[i].weight);
            ms += eSet[i].weight;
            if (k == G.num_v-1) break;
            else k++;    //生成边数增1
        }
        i++;    //扫描下一条边
    }
    if(k != G.num_v-1) return -1;
    else return ms;
}
