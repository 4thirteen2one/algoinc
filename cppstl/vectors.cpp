#include <cstdio>
#include <vector>
using namespace std;

void print1dIntVector(vector<int> vi) {
    for(vector<int>::size_type i = 0; i < vi.size(); i++) {
        printf("%d", vi[i]);        //vi[i]等价于*(vi.begin()+i)
        if(i < vi.size()-1)         //vi.size()：int型向量中元素的个数（unsigned型）
            printf(" ");
        else
            printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> vi;                 //声明int型向量vi
    // vector<vector<int> vviname;  //“>>”中间要加空格
    vector<int>::iterator vit;      //声明一个int型向量迭代器vit

    for(int i = 0; i < n; i++) {
        vi.push_back(n-i);          //vi.push_back()：在vi后端添加元素，时间复杂度O(1)
    }
    vit = vi.begin();               //vi.begin()：vi首元素地址
    for(int i = 0; i < n; i++) {
        printf("%d", *(vit+i));     //打印vi[i]
        if(i < n-1) printf(" ");
        else printf("\n");
    }
    printf("vi.size() = %d\n", vi.size());

    vi.pop_back();                  //vi.pop_back()：在vi后端删除元素，时间复杂度O(1)
    //使用迭代器的自增/减操作来遍历vector中的元素
    for(vit = vi.begin(); vit != vi.end(); vit++) { //vector迭代器不支持vit < vi.end()这种写法
        printf("%d", *vit);                        //故循环条件只能用vit != vi.end()
        if(vit < vi.end()-1) printf(" ");                     
        else printf("\n");
    }
    printf("vi.size() = %d\n", vi.size()); 

    for(int i = 0; i < n; i++)
        vi.push_back(i);
    print1dIntVector(vi);
    printf("vi.size() = %d\n", vi.size()); 

    vi.insert(vi.begin(), -1);    //vi.insert(vit, x)：在指定迭代器vit处插入一个元素x，时间复杂度O(n)
    print1dIntVector(vi);
    printf("vi.size() = %d\n", vi.size()); 

    vi.erase(vi.begin()+1);         //vi.erase(vit)：删除指定位置的元素
    print1dIntVector(vi);
    printf("vi.size() = %d\n", vi.size()); 

    vi.erase(vi.begin()+2, vi.begin()+4);           //vi.erase(first, last)：删除[first, last)内的所有元素
    print1dIntVector(vi);
    printf("vi.size() = %d\n", vi.size()); 

    vi.clear();                     //vi.clear()：清空所有元素，时间复杂度O(n)
    //vi.erase(vi.begin(), vi.end());
    printf("vi.size() = %d\n", vi.size()); 
    return 0;
}
