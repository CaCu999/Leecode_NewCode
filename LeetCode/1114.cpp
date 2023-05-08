#include <stdio.h>

int main(int argc, char** argv)
{   
    // int num(1);
    // int max_num(10);
    // int step(1);
    // int result(0);

    int num = 1;
    int max_num = 10;
    int step = 1;
    int result = 0;
    
    while (num <= max_num)
    {
        result = num * num;
        printf("%d ^ 2 = %d\n", num, result);
        num = num + step;
    }

    return 0;
}

