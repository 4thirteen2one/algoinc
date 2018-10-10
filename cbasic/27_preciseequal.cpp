#include <stdio.h>
#include <math.h>
#include "mylib.h"

int main()
{
    double db1 = 4 * asin(sqrt(2.0) / 2);
    double db2 = 3 * asin(sqrt(3.0) / 2);
    if(EQUAL_X(db1, db2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
