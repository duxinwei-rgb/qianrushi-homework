#include <stdio.h>
void input(char data[]) {
    printf("请输入一些数据：");
    scanf("%s", data);
}
int main() {
    printf("Hello, World!\n");
    char string[100];
    input(string);
    printf("你输入的数据是：%s\n", string);
    return 0;
}
