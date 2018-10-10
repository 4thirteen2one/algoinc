// 给出N个开区间(x,y)，从中选择尽可能多的两两没有交集的开区间
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;
struct Interval {
    int x, y;
} I[maxn];

bool cmp(Interval a, Interval b) {
    if(a.x != b.x)
        return a.x > b.x;   //先按左端点从大到小排序
    else
        return a.y < b.y;   //左端点相同的按右端点从小到大排序
}

int main() {
    int n;
    while(scanf("%d", &n), n != 0) {
        for(int i = 0; i < n; i++)
            scanf("%d%d", &I[i].x, &I[i].y);
        sort(I, I+n, cmp);
        int ans = 1; lastX = I[0].x;
        for(int i = 1; i < n; i++) {
            if(I[i].y <= lastX) {
                //I[i].y < lastX
                //给出N个闭区间，求最少需要确定多少个点，才能使每个闭区间中都至少存在一个点
                lastX = I[i].x;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

