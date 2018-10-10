#include <cstdio>
#include <set>
using namespace std;

void printIntSet(set<int> si) {
    set<int>::iterator sit = si.begin();
    while(sit != si.end()) {
        printf("%d", *sit);
        if(++sit != si.end())
            printf(" ");
        else
            printf("\n");
    }
}

int main() {
    int piN[10] = {3,1,4,1,5,9,2,6,5,3};
    set<int> si;
    printf("\nC++ STL中的set内部用红黑树实现\n");

    printf("\n`si.insert(x)` 将x插入set 容器中，并自动递增排序和去重，时间复杂度为 O(log N)\n");
    for(int i = 0; i < 10; i++)
        si.insert(piN[i]);
    printIntSet(si);
    printf("元素个数为%d\n", si.size());

    printf("\n`si.find(x)` 返回迭代器值，如果没找到则返回end()，时间复杂度为 O(log N)\n");
    printf("%d\n", *(si.find(-1)));
    printf("%d\n", *(si.find(3)));
    printf("%d\n", *(si.find(7)));
    printf("%d\n", *(si.find(10)));

    printf("\n`si.erase(sit)`，时间复杂度为 O(1)\n");
    si.erase(si.find(1));
    printIntSet(si);
    si.erase(si.find(2));
    printIntSet(si);
    si.erase(si.find(3));
    printIntSet(si);
    
    printf("\n`si.erase(x)`，时间复杂度为 O(log N)\n");
    si.erase(4);
    printIntSet(si);
    si.erase(5);
    printIntSet(si);
    
    printf("\n`si.erase(first, last)` 删除 [first, last)，时间复杂度为 O(last-first)\n");
    si.erase(si.find(9), si.end());
    printIntSet(si);

    si.clear();
    printf("\n`si.clear()` 用于清空set中的所有元素，时间复杂度为 O(n)\n");

    printIntSet(si);
    printf("\n元素个数为%d\n", si.size());
    printf("`si.size()` 用于获取set内元素的个数，时间复杂度为 O(1)\n");
    
    return 0;
}

