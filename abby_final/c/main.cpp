#include <iostream>

using namespace std;
long long n,nn,st;
int x;

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n){
        st = 0;
        while(n!=0){
            nn = n;
            x = 0;
            while(nn !=0){
                if(nn%10 > x)
                    x = nn%10;
                nn/=10;
            }
            n -= x;
            st++;
        }
        cout<<st<<endl;

    }
    return 0;
}
