#include <stdio.h>

int main() {
    double A, B, C; scanf("%lf %lf %lf", &A, &B, &C);
    double max = A * B / C > A / B * C ? A * B / C : A / B * C;
    printf("%d", (int)max);
}
