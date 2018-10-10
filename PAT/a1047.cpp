#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 40010;     //最大学生人数
const int maxc = 2510;      //最大课程门数

char name[maxn][5];         //maxn个学生
                            //为什么存储名字的数组长度为5：
                            //name格式为3[A-Z]\d,共4个字，故要多留一个存\0

vector<int> course[maxc];

bool cmp(int a, int b) {    //比较两个名字的字典序（a<b则返回true）
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    int n, k, c, courseID;  //n为学生数量,k为课程数量
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s %d", name[i], &c); //课程数量
        for(int j = 0; j < c; j++) {
            scanf("%d", &courseID);
            course[courseID].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(),cmp);
        for(int j = 0; j < course[i].size(); j++) {
            printf("%s\n", name[course[i][j]]);
        }
    }
    return 0;
}

