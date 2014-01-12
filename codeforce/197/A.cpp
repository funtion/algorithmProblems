#include <iostream>
#include <algorithm>
using namespace std;
char s[200];
int nm[200],n;
int main()
{
    cin>>s;
    for(int i=0;s[i];i++){
        if(s[i]=='+'){
            n++;
        }else{
            nm[n] = s[i]-'0';
        }
    }
    n++;
    sort(nm,nm+n);
    for(int i=0;i<n-1;i++){
        cout<<nm[i]<<'+';
    }
    cout<<nm[n-1];
    return 0;
}
