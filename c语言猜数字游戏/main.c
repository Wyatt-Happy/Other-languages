//������Ϸ
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
1.���Ҫ��
��һ�����ݴ��ܣ������Ѻã�������ȫ��
2.�����ʾ��
��������Ϸ����
a) һ����λ������λ�ϵ����ֲ��ظ�,��1��9��
b) ��������ʾ�³������λ����
c) ÿ�β²���������ݸ������Ƶ���ʾ*A*B��
d������Aǰ��*�����㱾�β¶��˶��ٸ����֡�
   ����Bǰ��*�����㱾�β¶Ե����ֲ���λ����ȷ�ĸ���
*/
int n;
int main()//���������������λ��
{
    int o=0;
    printf("����µĴ�����");
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
        printf("��Ӯ�ˣ�������%s",a);
    else
        printf("������,������ %s",a);
}
int cmp(char a[],char b[])//�Ƚ���λ��λ�ü���ȷ��
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
