#include<cstdio>
const int maxn = 201;
int a[maxn];    //存放 n 个数
int main(){
    int n, x;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        scanf("%d", &x);    //输入欲查询的数
        int k;              //下标
        for(k = 0; k < n; k++){ //遍历数组
            if(a[k] == x){      //若找到了 x
                printf("%d\n", k);
                break;          //退出查找 
            } 
        }
        if(k == n){         //若没有找到
            printf("-1\n"); //输出 -1 
        }
    }
    return 0;
}
