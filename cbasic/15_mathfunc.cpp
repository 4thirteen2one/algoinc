#include <stdio.h>
#include <math.h>
int main() {
    printf("由于在gcc新的版本中GCC把C99中的标准库分成了libc和libm两个部分，libm中包括一些数学库<math.h>等，所以如果要使用libm则必须加上编译选项-lm(即link libm)，不然会报错。\n");

    printf("\n`fabs(double x)`\n");
    double d = -12.56;
    printf("fabs(%.2f) = %.2f\n", d, fabs(d));

    printf("\n`floor(double x), ceil(double x)`\n");
    double d1 = -5.2, d2 = 5.2;
    printf("floor(%f) = %.0f, ceil(%f) = %.0f\n", d1, floor(d1), d1, ceil(d1));
    printf("floor(%f) = %.0f, ceil(%f) = %.0f\n", d2, floor(d2), d2, ceil(d2));

    printf("\n`pow(double r, double p)`\n");
    double r = 2.0, p = 3.0;
    printf("pow(%f, %f) = %f\n", r, p, pow(r,p));

    printf("\n`sqrt(double x)`\n");
    double x = 2.0;
    printf("sqrt(%f) = %f\n", x, sqrt(x));

    printf("\n`log(double x)`\n");
    double x2 = 1.0;
    printf("log(%f) = %f\n", x2, log(x2));
    printf("对其他底数求对数，需使用换底公式，$log_a(b) = log_e(b) / log_e(a)$\n");

    printf("\n`sin(double x), cos(double x), tan(double x)`\n");
    const double pi = acos(-1.0);
    printf("acos(-1.0) = %f\n", pi);
    double sinx = sin(pi * 45 / 180);
    double cosx = cos(pi * 45 / 180);
    double tanx = tan(pi * 45 / 180);
    printf("sin(pi * 45 / 180) = %f\n", sinx);
    printf("cos(pi * 45 / 180) = %f\n", cosx);
    printf("tan(pi * 45 / 180) = %f\n", tanx);

    printf("\n`asin(double x), acos(double x), atan(double x)`\n");
    double asinx = asin(1);
    double acosx = acos(-1.0);
    double atanx = atan(0);
    printf("asin(1) = %f\n", asin(1));
    printf("acos(-1.0) = %f\n", acos(-1.0));
    printf("atan(0) = %f\n", atan(0));

    printf("\n`round(double x)`：将double类型变量x四舍五入\n");
    double d3 = 3.30, d4 = 3.40, d5 = 3.50, d6 = 3.55;
    printf("round(%f) = %f\n", d3, round(d3));
    printf("round(%f) = %f\n", d4, round(d4));
    printf("round(%f) = %f\n", d5, round(d5));
    printf("round(%f) = %f\n", d6, round(d6));
    printf("(int)%f = %d\n", round(d3), (int)round(d3));

    return 0;
}

