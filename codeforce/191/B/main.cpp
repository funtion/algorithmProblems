#include <iostream>

using namespace std;

int main()
{
    int64_t n;
    cin>>n;
    bool *pr = new bool[n*100];
    for(int64_t i = 0; i<n*100; i++)
    {
        pr[i] = true;
    }
    for(int64_t i=2; i<n*100; i++)
    {
        if(pr[i])
        {
            for(int64_t j = 2*i; j<n*100; j+=i)
                pr[j]  = false;
        }
    }
    int64_t kk = 0;
    for(int64_t i = 2; i<n*100; i++)
    {
        if(pr[i])
        {
            kk++;
            if(kk <= n)
            {
                cout<<i<<' ';
            }
            else
            {
                break;
            }
        }


    }
    return 0;
}
