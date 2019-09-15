/*
    时间:2015年5月13日
    功能:
    目的:测试%x %X %#X %#x的用法
*/
# include <stdio.h>
int main (void)
{
   int i=27;
   printf ("%x,\n",i);
   printf ("%X,\n",i);
   printf ("%#X,\n",i);
   printf ("%#x,\n",i);

   return 0;
}
/*
    在COdeBlocks中的输出结果是:
-------------------------------
1b,
1B,
0X1B,
0x1b,
-------------------------------
总结：
*/
