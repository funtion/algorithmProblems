#include<iostream>
using namespace std;
int main()
{
    /*
    long long ans = 0;
    for(long i=0;i<=100000000L;i++)
    {
        if(i%2==0 || i%3==0 ||i%5==0||i%7==0)
            ans+=i;
    }
    cout<<ans<<endl;
    return 0;
    */

    long long ans = 0;
    int mask = (1<<4)-1;
    int a[] = {2,3,5,7};
    while(mask)
    {
        int x = 1,cnt = 0;
        for(int i=0;i<4;i++)
        {
            if( mask &(1<<i))
            {
                x*=a[i];
                cnt++;
            }
        }
        long long  temp = 100000000/x;
        temp = ((1+temp)*temp)/2;
        if( cnt%2 == 1)
        {
            ans += x*temp;
        }
        else
        {
            ans -=x*temp;
        }
        mask --;
    }
    cout<<ans<<endl;
    return 0;

}
