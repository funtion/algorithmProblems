#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    char *a1="XYZABCDEFGHIJKLMNOPQRSTUVW";
    char *a2="xyzabcdefghijklmnopqrstuvw";
    cin>>s;
    int m;
    cin >>m;

    char t1 = a2[m];
    char t2 =a1[m];
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == t1)
            s[i] = t2;
    }
    cout<<s;
    return 0;
}
