#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void printStrbyC(string str) {
    for(auto i = 0; i < str.length(); i++) {
        printf("%c", str[i]);
        if(i < str.length()-1)
            printf(" ");
        else
            printf("\n");
    }
}

int main() {
    string str("Hello world.");

    printStrbyC(str);
    
    cout << str << endl;
    
    printf("%s\n", str.c_str());

    return 0;
}

