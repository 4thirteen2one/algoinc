// 并查集

int n = 10;
int elder[n];
for (int i = 0; i < n; i++)
    elder[i] = i;  //初始化每个元素都是独立的一个集合，此时该元素为该集合的根结点
    
int findElder(int *elder, int x) {
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
/* 递归实现
int findElder(int *elder, int x) {
    if(x == elder[x]) return x;         //找到根结点
    else {
        int grd = findElder(elder[x]);  //递归寻找elder[x]的根结点grd
        elder[x] = grd;                 //将根结点grd赋给elder[x]
        return grd;                     //返回根结点grd
    }
}
*/

void merge(int a, int b) {
    int sra = findElder(a);
    int srb = findElder(b);     //查找a的根结点
    if (sra != srb)
        elder[sra] = srb;
}
