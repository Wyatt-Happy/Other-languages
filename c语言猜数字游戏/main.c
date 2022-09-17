//猜数游戏
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
1.设计要求：
有一定的容错功能，界面友好，功能齐全。
2.设计提示：
猜数字游戏规则：
a) 一个四位数，各位上的数字不重复,从1到9。
b) 按以下提示猜出这个四位数。
c) 每次猜测输入的数据给出类似的提示*A*B。
d）其中A前的*代表你本次猜对了多少个数字。
   其中B前的*代表你本次猜对的数字并且位置正确的个数
*/
int n;
int main()//主函数随机生成四位数
{
    int o=0;
    printf("您想猜的次数：");
    scanf("%d",&o);
    srand((unsigned)time(NULL));
    char a[5],b[5];
    int i,j,s,k=0;
     for(i=0;i<4;i++)
     {
        a[i]=rand()%10+48;
        for(j=i-1;j>=0;j--)
        {
            if(a[i]==a[j])
            {
                i--;
                break;
            }
        }
   }
   a[i]='\0';

    do{
        gets(b);
        s=cmp(a,b);
        printf("%dA\t%dB\n",n,s);
        n=0;
        k++;
    }while(s!=4&&k!=o+1);
    if(k!=o+1)
        printf("你赢了，数字是%s",a);
    else
        printf("你输了,数字是 %s",a);
}
int cmp(char a[],char b[])//比较四位数位置及正确性
{
    int s=0,i,j;
    for(i=0;i<4;i++)
        if(a[i]==b[i])
            s++;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(b[j]==a[i]&&j!=i)
                n++;
        }
    }
    return s;
}
