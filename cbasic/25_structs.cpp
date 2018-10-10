#include <stdio.h>

struct studentInfo {
    int id;
    char gender;    //'F' or 'M'
    char name[20];
    char major[20];
    studentInfo* next;
    studentInfo(){}
    studentInfo(int _id){}
    studentInfo(int _id, char _gender) {
        id = _id;
        gender = _gender;
    }
};
studentInfo Alice, Bob, students[1000];
//2个结构体变量，1个结构体数组
//
//结构体内不能定义自身，但可以2定义自身类型的指针变量

studentInfo *p;

/*
Alice.id = 9527;
Alice.name = "Alice";
Alice.next = Bob;

(*p).id = 9527;
(*p).name = "Alice";
(*p).next = Bob;

p->id = 9527;
p->name = "Alice";
p->next = Bob;

int getID = Alice.id;
*/

struct Point {
    int x, y;
    Point(){}
    Point(int _x, int _y): x(_x), y(_y) {}  //init x and y
} pt[10];

int main() {
    int num = 0;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            pt[num++] = Point(i,j);
        }
    }
    for(int i = 0; i < num; i++) {
        printf("(%d,%d)\n", pt[i].x, pt[i].y);
    }
    return 0;
}

