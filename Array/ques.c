#include<stdio.h>
int main(){
int a ; int b ;
int cnt = 0;
cnt = scanf("%d %d",&a, &b);


if(cnt == 2){
    printf("%d%d" , a, b); 
}else{
    printf("not a interger");
}

}