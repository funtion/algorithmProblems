#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long in[100010];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    sort(in,in+n);
    for(int i=1;i<n;i++){
        if(in[i]%in[0]!=0){
            cout<<"-1";
            return 0;
        }
    }
    cout<<in[0];
    return 0;
}
