
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
char s[100010];
int t;
bool ck(char* c){
    int s=0;
    while(*c != '\0'){
        assert(*c>='0' && *c<='9');
        s+= *c-'0';s%=10;
        c++;
    }
    return s%10 == 0;
}
void ad(char* s,long long n){
    s[n]++;
    while(s[n]>'9'){
        s[n] -=10;
        n--;
        s[n]++;
    }
    assert(s[n]>='0' && s[n]<='9');
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(s,'0',sizeof(s));
        scanf("%s",s+1);
        long long len = strlen(s);
        ad(s,len-1);
        while(!ck(s)){
            ad(s,len-1);
        }
        char *ss =s;
        if(*ss == '0')
           ss++;
        printf("%s\n",ss);
    }
    return 0;
}

/*
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    int T,i,j,x,l,sum;
    char s[100001];
    int num[100001];
    scanf("%d",&T);
    while(T--)
    {
        memset(s,0,sizeof(s));
        memset(num,0,sizeof(num));
        scanf("%s",s);
        l=strlen(s);
        for (i=0; i<l; i++)
            num[l-i] = s[i] - '0';

        while(1)
        {

            num[1]++;  j=1;
            while(num[j]>9)
            {
                num[j+1]++;
                num[j]%=10;
                j++;
            }
            if (j>l) l++;

            sum=0;
            for (i=1; i<=l ;i++)
                sum+=num[i];
            if (sum%10==0)
            {
                for (i=l; i>=1; i--)
                    cout<<num[i];
                cout<<endl;
                break;
            }
        }
    }
}
*/
