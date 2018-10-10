//Prim 算法

#define INF 65535
int Prim(MGraph G, int v) {
    int lowcost[MAXV], closest[MAXV];
    int ms=0, min, i, j, k;
    for(i = 0; i < G.num_v; i++) {
        lowcost[i] = G.edges[v][i];
        closest[i] = v;
    }
    for(i = 1; i < G.num_v; i++) {  //找出n-1个顶点
        min = INF;
        for(j = 0; j < G.num_v; j++) {
            if(lowcost[j]!=0 && lowcost[j]<min) {
                min = lowcost[j];
                k = j;              //k记录最近顶点的编号
            }
        }                           //在(V-U)中找出离U最近的顶点k
        ms += lowcost[k];
        printf("边(%d, %d)的权为：%d\n", closest[k], k, min);
        lowcost[k] = 0;             //标记k已经加入U
        for(j = 0; j < G.num_v; j++) {
            if(G.edges[k][j]!=0 && G.edges[k][j]<lowcost[j]) {
                lowcost[j] = G.edges[k][j];
                closest[j] = k;
            }
        }
    }
    return ms;
}
