#include <stdio.h>
int input() {
    char data[100];
    printf("请输入一些数据：");
    scanf("%s", data);
    return 0;
}
int main() {
    printf("Hello, World!\n");
    int a=input();
    printf("你输入的数据是：%s\n", data);
    return 0;
}