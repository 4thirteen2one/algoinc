#include <cstdio>
#include <cstring>
//#include <vector>
//using namespace std;

const int MAXN = 100001;
int sumscores[MAXN] = {0};  //初始化全为0

int main() {
    int N, schID, score;    //参赛人数，学校ID，分数
    while((scanf("%d", &N) != EOF) && (0<=N && N<MAXN)) {
        //确保参数人数不超过100000
        memset(sumscores, 0, sizeof(sumscores));
        for(int i = 1; i <= N; i++) {
            scanf("%d%d", &schID, &score);
            sumscores[schID] += score;
        }
        int k = 1, temp = -1;
        for(int i = 1; i <= N; i++) {
            if(sumscores[i] > temp) {
                temp = sumscores[i];
                k = i;
            }
        }
        printf("%d %d\n", k, temp);
    }
}


