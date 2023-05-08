#include <stdio.h>
int main() {
    int n;
    float i;
    float sum = 0;
    printf("请输入整数\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        sum += 1 / i;
    }
    printf("sum = %f", sum);
    return 0;
}