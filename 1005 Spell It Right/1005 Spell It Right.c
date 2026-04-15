#include<stdlib.h>
#include<stdio.h>

void output(int i){
    switch(i){
    case 0:
        printf("zero");
        break;
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
    }
}

int main(){
    char n[101];
    int sum = 0;
    int n1, n2, n3;
    gets(n); // 编译器会报错warning，但不影响结果
    for(int i = 0; i < 101; i++){
        if(n[i] != '\0'){
            sum += n[i] - '0';
        }else{
            break;
        }
    }
    n1 = sum / 100;
    n2 = (sum / 10) % 10;
    n3 = sum % 10;
    if(n1 != 0){
        output(n1);
        printf(" ");
        output(n2);
        printf(" ");
        output(n3);
    }else if(n1 == 0 && n2 !=0){
        output(n2);
        printf(" ");
        output(n3);
    }else{
        output(n3);
    }
    return 0;
}
