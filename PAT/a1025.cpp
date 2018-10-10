#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Testee {
    char id[15];
    int score;
    int test_location;
    int local_rank;
    //int r;
} testees[30010];

bool cmp(Testee a, Testee b) {
    if(a.score != b.score)
        return (a.score > b.score);             //先按分数从高到低排序
    else
        return strcmp(a.id, b.id) < 0;          //分数相同按准考证号从小到大排序
}

int main() {
    int n, k, num = 0;                          //num表示考生总数，1<=num<=30000
    scanf("%d", &n);                            //n表示考点数，1<=n<=100
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);                        //k表示考点人数，1<=k<=300
        for(int j = 0; j < k; j++) {
            scanf("%s %d", testees[num].id, &testees[num].score);
            testees[num].test_location = i;     //存储考点编号，所以i必须从1开始
            num++;
        }
        sort(testees+num-k, testees+num, cmp);  //将该考点考生按成绩排序
        testees[num-k].local_rank = 1;          //记考点第一名的local_rank为1
        for(int j = num-k + 1; j < num; j++) {  //对该考点剩余考生
            if(testees[j].score == testees[j-1].score) {    //如果与前一位考生同分
                testees[j].local_rank = testees[j-1].local_rank;
                //local_rank也相同
            } else {                            //local_rank为排在该考生前的人数
                testees[j].local_rank = j + 1 - (num-k);
            }
        }
    }
    printf("%d\n", num);                        //输出考生总人数
    sort(testees, testees+num, cmp);            //将所有考生按成绩排序
    int r = 1;                                  //当前考生排名
    for(int i = 0; i < num; i++) {
        if(i>0 && testees[i].score != testees[i-1].score)
            r = i + 1;                          //如果当前考生不是第一个考生
                                                //且分数与上一个不同时，r+1
        printf("%s ", testees[i].id);
        printf("%d %d %d\n", r, testees[i].test_location, testees[i].local_rank);
    }
    /*
    testees[0].r = 1;
    for(int i = 1; i < n; i++) {
        if(testees[i].score == testees[i-1].score)
            testees[i].r = testees[i-1].r;
        else
            testees[i].r = 1 + 1;
    }
    */
    return 0;
}

