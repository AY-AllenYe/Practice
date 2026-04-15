#include<stdlib.h>
#include<stdio.h>
#define max_radix 30000

int Letter_char2Decimal_int(char a){
    if(a >= '0' && a <= '9')
        return (a -'0');
    else if(a >= 'a' && a <= 'z')
        return (a - 'a' + 10);
}
int judge(long long com, char* n, int try_radix){
    long long base = 0;
    for(int i = 0; n[i] != '\0' ; i++)
        base = base * try_radix + Letter_char2Decimal_int(n[i]);
    //printf("%d ", base);
    if(base == com)
        return -1;
    else
        return 1;
}

int main(){
    char n1[11], n2[11];
    int tag = 0, radix;
    int length1 = 0, length2 = 0, flag;
    scanf("%s %s %d %d", n1, n2, &tag, &radix);
    long long base1 = 0, base2 = 0;
    for(int i = 0; n1[i] != '\0' ; i++)
        length1++;
    for(int i = 0; n2[i] != '\0' ; i++)
        length2++;
    if(tag == 1){
        for(int i = 0; n1[i] != '\0' ; i++)
            base1 = base1 * radix + Letter_char2Decimal_int(n1[i]);
        for(int tmp_radix = 2; tmp_radix < max_radix; tmp_radix++){
            flag = judge(base1, n2, tmp_radix);
            if(flag == -1){
                if(length2 != 1)
                    printf("%d", tmp_radix);
                else
                    printf("%d", Letter_char2Decimal_int(n2[0]) + 1);
                exit(0);
            }
        }
        printf("Impossible");
        return 0;
    }
    if(tag == 2){
        for(int i = 0; n2[i] != '\0' ; i++)
            base2 = base2 * radix + Letter_char2Decimal_int(n2[i]);
        for(int tmp_radix = 2; tmp_radix < max_radix; tmp_radix++){
            flag = judge(base2, n1, tmp_radix);
            if(flag == -1){
                if(length1 != 1)
                    printf("%d", tmp_radix);
                else
                    printf("%d", Letter_char2Decimal_int(n1[0]) + 1);
                exit(0);
            }
        }
        printf("Impossible");
        return 0;
    }
}