#include <stdio.h>
#include <string.h>

char* reverseStr(char* str);

int main()
{
    char str[30];
    printf("����һ���ַ���: ");
    scanf("%s", str);
    printf("��ת֮ǰ���ַ���Ϊ:%s\n",str);
    printf("��ת֮����ַ���Ϊ:%s",reverseStr(str));
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
