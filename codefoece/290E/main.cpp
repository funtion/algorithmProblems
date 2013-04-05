#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int64_t si;
    cin>>s;
    si = s.size()/2;
    for(int64_t i =0;i<=si;i++)
    {
        if(s[i]!=s[si-1-i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
