#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 50010;
#define ls (p<<1)
#define rs (ls|1)
#define mid  ((t[p].l+t[p].r)>>1)
using namespace std;
int cse,n,m,a,b,c;
struct tree{
int l,r,sum,lazy;
}t[maxn<<2];
void pushup(int p){
    t[p].sum = t[rs].sum+t[rs].sum;
}
void pushdown(int p){
    if(t[p].lazy == 0){//È«²¿0
        t[ls].sum = 0;
        t[rs].sum = 0;
        t[ls].lazy= 0;
        t[rs].lazy= 0;
        t[p].lazy =-1;
    }else if(t[p].lazy == 1){
        t[ls].lazy = 1;
        t[rs].lazy = 1;
        t[ls].sum = t[ls].r - t[ls].l+1;
        t[rs].sum = t[rs].r - t[rs].l+1;
        t[p].lazy = -1;
    }
}
void build(int p,int l,int r){
    t[p].l = l;
    t[p].r = r;
    t[p].sum = 1;
    t[p].lazy = -1;
    if(l==r)
        return;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
void change(int p,int l,int r,int val){
    if(t[p].l==l && t[p].r == r){
        t[p].lazy = val;
        if(val == 1){
            t[p].sum = t[p].r-t[p].l+1;
        }
        else{
            t[p].sum = 0;
        }
    }else{
        pushdown(p);
        if(l>mid)change(rs,l,r,val);
        else if(r<=mid)change(ls,l,r,val);
        else{change(ls,l,mid,val);change(rs,mid+1,r,val);}
        pushup();
    }
}
void query(int p,int l,int r){
    if(t[p].l==l && t[p].r == r){
        return t[p].sum;
    }
    pushdown(p);
    if(l>mid)return query(rs,l,r);
    else if(r<=mid)return query(ls,l,r);
    else return query(ls,l,mid)+query(rs,mid+1,r);
}
int main()
{
    scanf("%d",&cse);
    while(cse--)
    {
        scanf("%d%d",&n,&m);
        build(1,0,n-1);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a==1)
            {
                int ttmp = query(1,b,n-1);
                if(ttmp == 0){
                    printf("Can not put any one.\n");
                }else{
                    if(ttmp<c)c=ttmp;
                }
            }
            else
            {

            }
        }
        printf("\n");
    }
    return 0;
}
