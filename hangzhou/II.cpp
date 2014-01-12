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
int inline fabs(int x){return x>0?x:-x;}//取绝对值的函数
int cal(int i,int j,int ii,int jj)//计算2点的距离
{
    if(tu[ii][jj]==tu[i][j]||tu[ii][jj]=='O') return INF+INF;
    return fabs(ii-i)+fabs(jj-j);
}

bool smalldo(int i,int j,int milen)//暴力枚举对于当前的起点H存不存在满足距离等于milen的C
{
    for(int ii=0;ii<m;ii++)//当然得先枚举i最小的
    for(int jj=0;jj<n;jj++)//至于j也是从小到的枚举
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
        int milen=INF;//milen是H 和C的最小距离
        for(int i=0;i<m;i++)//暴力枚举2点算出最小的距离
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
        }//找出milen


        for(int i=0;i<m;i++)//暴力枚举起点H
        for(int j=0;j<n;j++)
        if(tu[i][j]=='H')
        {
            tempa.x=i;tempa.y=j;
            if(smalldo(i,j,milen))
                i=m,j=n;//找到了答案，强行跳出循环
        }
        printf("%d %d %d %d\n",tempa.x,tempa.y,tempb.x,tempb.y);
    }
    return 0;
}
