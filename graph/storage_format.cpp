#define MAXV 100                //顶点数目的最大值
typedef char VertexType;        //顶点的数据类型不同情况不一样
typedef int EdgeType;           //整数表示权值或者连通性
typedef struct {
    VertexType vertices[MAXV];  //顶点表
    EdgeType edges[MAXV][MAXV]; //邻接矩阵（二维数组）边表
    int num_v, num_e;           //图的顶点数和弧数
} MGraph;

//邻接表

#define MAXV 100                //图中顶点数目的最大值 
typedef struct EdgeNode {       //边表结点
    int adjvex;                 //该弧所指向的顶点的位置
    //InfoType info;
    struct EdgeNode *next;      //指向下一条弧的指针
} EdgeNode;

typedef struct VertexNode {     //顶点表结点
    VertexType data;            //顶点信息
    EdgeNode *firstedge;        //单链表头指针
} VertexNode, AdjList[MAXV];    //AdjList 是结构体数组类型

typedef struct {
    AdjList adjlist;    //邻接表
    int num_v, num_e;   //图的顶点数和弧数
} ALGraph;              //ALGraph 是以邻接表存储的图类型

//十字链表

#define MAXV 100                    //图中顶点数目的最大值
typedef struct EdgeNode {           //边表结点
    int tailvex, headvex;           //该弧的头尾结点
    struct EdgeNode *hlink, *tlink; //分别指向弧头相同和弧尾相同的结点
    //InfoType info;                //相关信息
} EdgeNode;

typedef struct VertexNode {         //顶点表结点
    VertexType data;                //顶点信息
    EdgeNode *firstin, *firstout;   //指向第一条入弧和出弧
} VertexNode;

typedef struct {
    VertexNode xlist[MAXV];         //邻接表
    int num_v, num_e;               //图的顶点数和弧数
} GLGraph;                          //GLGraph 是以十字邻接存储的图类型 

//邻接多重表

#define MAXV 100                    //图中顶点数目的最大值
typedef struct EdgeNode {           //边表结点
    bool mark;                      //访问标记
    int ivex, jvex;                 //分别指向该弧的两个结点
    struct EdgeNode *ilink, *jlink; //分别指向两个顶点的下一条边
    //InfoType info;                //相关信息指针
} EdgeNode;

typedef struct VertexNode {         //顶点表结点
    VertexType data;                //顶点信息
    EdgeNode *firstedge;            //指向第一条依附该顶点的边
} VertexNode;

typedef struct {
    VertexNode adjmulist[MAXV];     //邻接表
    int num_v, num_e;               //图的顶点数和弧数
} AMLGraph;             //AMLGraph 是以邻接多重表存储的图类型


