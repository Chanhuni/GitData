#include <stdio.h>
#include <string.h>

char* reverseStr(char* str);

int main()
{
    char str[30];
    printf("输入一个字符串: ");
    scanf("%s", str);
    printf("翻转之前的字符串为:%s\n",str);
    printf("翻转之后的字符串为:%s",reverseStr(str));
    return 0;
}

char* reverseStr(char* str)
{
    int i=0;
    int j=strlen(str)-1;
    char temp;
    while (i<j)
    {
        temp=*(str+i);
        *(str+i)=*(str+j);
        *(str+j)=temp;
        i++;
        j--;
    }
    return str;
}
