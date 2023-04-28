#include <stdio.h>
#include <math.h>

int main(void){

    double A, B, C;
    double delta, x1, x2;
    scanf("%lf%lf%lf", &A, &B, &C);

    delta = (B*B)-(4*A*C);
    x1 = (-B + sqrt(delta))/2*A;
    x2 = (-B - sqrt(delta))/2*A;

    printf("%.4lf %.4lf\n", x1, x2);

    return 0;
}