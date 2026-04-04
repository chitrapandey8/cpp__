
#include<stdio.h>>
int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 2;
    int c = 1;
    int d = 40;
    // int maxi = a>b &&  a>c ? a: b > c ? b : c;
    // int maxi = a>b ? a>c : b>c ? b:c;

    int mini = a<b && a< c && a< d ? a : b<c && b < d ? b : c < d ? c : d;
    printf("%d",mini);
    return 0;
}
