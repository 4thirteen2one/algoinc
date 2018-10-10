#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i;
    double db;
    char c;
    char str[100];
    cout << "Input an int number: ";
    cin >> i;
    cout << "Input a double float number: ";
    cin >> db;
    cout << "Input a char: ";
    cin >> c;
    cout << "Input a string(length less than 100)";
    cin >> str;
    //printf("%d\n%f\n%c\n%s\n", i, db, c, str);
    cout << i << endl;
    cout << db << endl;
    cout << c << endl;
    cout << str << endl;
    cout << i << " " 
        << db << " " 
        << c << " " 
        << str << endl;
    cout << i << "haha"
        << db << "heihei"
        << c << "hoho" 
        << str << endl;

    //char s[100];
    //cin.getline(s, 100);    //read a whole line
    //string ss;
    //getline(cin, ss);
    //cout >> s >> ss;
    return 0;
}

