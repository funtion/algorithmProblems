#include <cstdio>
int main()
{
    int t,m,n;
    scanf("%d",&t);
    for(int cs = 1; cs<=t; cs++)
    {
        scanf("%d%d",&m,&n);
        printf("Case #%d: ",cs);
        if(m==1)
        {
            for(int i=0; i<n; i++)
                printf("a");
            puts("");
        //    continue;
        }
        else if( m >=3 )
        {
            for(int i=0; i<n; i++)
            {
                if(i%3==0)printf("a");else
                if(i%3==1)printf("b");else
                if(i%3==2)printf("c");
            }
            puts("");
         //   continue;
        }
        else
        {
            if (n==1) printf("a");
            else if (n==2) printf("ab");
            else if (n==3) printf("aab");
            else if (n==4) printf("aabb");
            else if (n==5) printf("aaaba");
            else if (n==6) printf("aaabab");
            else if (n==7) printf("aaababb");
            else if (n==8) printf("aaababbb");
            else
            {
                printf("aa"),n-=2;
                for (int i=1; i<=n/6; i++) printf("aababb");
                if (n%6==1) printf("a");
                if (n%6==2) printf("aa");
                if (n%6==3) printf("aaa");
                if (n%6==4) printf("aaaa");
                if (n%6==5) printf("aabab");
            }
            puts("");
        }
       // continue;
    }
}
