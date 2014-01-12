/*********
PRO: hdu 4584
TIT: Building bridges
DAT: 2013-08-10-13.22
AUT: UKean
EMA: huyocan@163.com
*********/
#include<cstdio>
#include<cstring>
#include<iostream>
#define INF 1e8
using namespace std;
char tu[45][45];
struct  point
{
    int x,y;
};
int m,n;
point tempa,tempb;
int inline fabs(int x){return x>0?x:-x;}//ȡ����ֵ�ĺ���
int cal(int i,int j,int ii,int jj)//����2��ľ���
{
    if(tu[ii][jj]==tu[i][j]||tu[ii][jj]=='O') return INF+INF;
    return fabs(ii-i)+fabs(jj-j);
}

bool smalldo(int i,int j,int milen)//����ö�ٶ��ڵ�ǰ�����H�治��������������milen��C
{
    for(int ii=0;ii<m;ii++)//��Ȼ����ö��i��С��
    for(int jj=0;jj<n;jj++)//����jҲ�Ǵ�С����ö��
    if(tu[ii][jj]=='C'&&milen==cal(i,j,ii,jj))
    {
        tempb.x=ii;
        tempb.y=jj;
        return 1;
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    while(scanf("%d%d",&m,&n))
    {
        if(m==0&&n==0) break;
        for(int i=0;i<m;i++)
            scanf("%s",tu[i]);
        int milen=INF;//milen��H ��C����С����
        for(int i=0;i<m;i++)//����ö��2�������С�ľ���
            for(int j=0;j<n;j++)
        {
            if(tu[i][j]=='O') continue;
            for(int ii=0;ii<m;ii++)
                for(int jj=0;jj<n;jj++)
            {
                if(ii==i&&jj==j) continue;
                int len=cal(i,j,ii,jj);
                milen=min(len,milen);
            }
        }//�ҳ�milen


        for(int i=0;i<m;i++)//����ö�����H
        for(int j=0;j<n;j++)
        if(tu[i][j]=='H')
        {
            tempa.x=i;tempa.y=j;
            if(smalldo(i,j,milen))
                i=m,j=n;//�ҵ��˴𰸣�ǿ������ѭ��
        }
        printf("%d %d %d %d\n",tempa.x,tempa.y,tempb.x,tempb.y);
    }
    return 0;
}
