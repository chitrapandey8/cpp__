#include<stdio.h>
int main(){
    int a, b, c;
    c  = scanf("%d %d", &a, &b);

    if(c ==0){
        printf("wrong");
    }else{
      printf(" ok");
    }
}