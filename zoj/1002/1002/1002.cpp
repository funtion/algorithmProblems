#include <iostream>
#include <stack>
#include<memory>
using namespace std;
int a,b,c;
bool used[1001],prime[10000];
int aa[1001];

void init()
{

    for(int i=0;i<10000;i++)
        prime[i] = true;
    prime[1]=false;
    for(int i=2;i<10000;i++)
    {
        if(!prime[i])
            continue;
        prime[i] = true;
        int j=i;
        while(j < 10000)
        {
            j+=i;
            prime[j] =false;
           
        }
    }
}
bool isPrime(int sum)
{

    /*if(sum == 1)
        return false;
    for(int i=2;i*i<=sum   ;i++)
        {
            if(sum%i == 0 )
            {
                return false;
            }
        }
    return true;*/
    return prime[sum];
}
bool isPrime(int location,int n)
{
    int sum =n;
    for(int i=0;i<c-1;i++)
    {
        if(location < a)
            return false;
        sum += aa[location--];
        if(isPrime(sum))
            return true;
    }
    return false;
}
bool s(int location )
{
    if(location == b)
        return true;
    for(int i=a;i<=b;i++)
    {
        if(!used[i] && !isPrime(location,i))
        {
            used[i] = true;
            aa[location+1] = i;
            if(s(location+1))
                {

                    return true;

                }
            used[i]=false;
        }
    }
    return false;
}
int main()
{
    init();
    while(cin>>a>>b>>c)
    {
        if(a==0 &&b==0&&c==0)
            return 0;
        //used = new bool[b+1];
        //aa = new int[b+1];
        for(int i=a;i<=b;i++)
            used[i] =false;
        aa[a-1]=0;
        if(s(a-1))
        {
             for(int i=a;i<b;i++)
                cout<<aa[i]<<',';
            cout<<aa[b]<<endl;
        }
        else
            cout<<"No anti-prime sequence exists.\n";

    }
}
