#include <cstdio>

struct Date{
    int year;
    int month;
    int day;
} date1, date2;

int months[12][2] = {
    {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30},
    {31, 31}, {31, 31}, {30, 30}, {10, 10}, {30, 30}, {31, 31}
};

bool isLeap(int year);
bool isLegal(Date date);

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        if(a > b) {     //保证前者日期早于后者，便于处理
            int temp = a;
            a = b;
            b = temp;
        }
        date1.year = a/10000;
        date1.month = (a%10000)/100;
        date1.day = a%100;
        date2.year = b/10000;
        date2.month = (b%10000)/100;
        date2.day = b%100;

        int ans = 1;
        if(isLegal(date1) && isLegal(date2)) {
            while(date1.year < date2.year || date1.month < date2.month || date1.day < date2.day) {
                date1.day++;
                if(date1.day == months[date1.month-1][isLeap(date1.year)] + 1) {
                    date1.month++;
                    date1.day = 1;
                }
                if(date1.month == 13) {
                    date1.year++;
                    date1.month = 1;
                }
                ans++;
            }
            printf("%d\n", ans);
        }
        else
            printf("Date illegal!\n");
    }
    return 0;
}

bool isLeap(int year) {
    return ((year%4 == 0 && year%100 != 0) || (year%400 == 0));
}

bool isLegal(Date date) {
    if((0<date.month && date.month<13) && (0<date.day && date.day<32)) {
        if(date.month == 2) {
            if(isLeap(date.year))
                return (date.day <= 29);
            else
                return(date.day <= 28);
        } else if(date.month == 4)
            return (date.day != 31);
        else if(date.month == 6)
            return (date.day != 31);
        else if(date.month == 9)
            return (date.day != 31);
        else if(date.month == 11)
            return (date.day != 31);
        else
            return true;
    }
    else
        return false;
}
