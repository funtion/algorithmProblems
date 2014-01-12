#include<iostream>
using namespace std;
bool has[200000];
int ans[200000],num[200000],q[200000];
int main()
{
    ios::sync_with_stdio(0);
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>num[i];
    for(int i=0;i<m;i++)
        cin>>q[i];
    ans[n] = 0;
    //cout<<"aaa\n";
    for(int i=n-1;i>=0;i--){
        if(!has[num[i]])
            ans[i] = ans[i+1]+1;
        else
            ans[i] = ans[i+1];
        has[num[i]] = true;
        //cout<<"bbb\n";
    }
    for(int i=0;i<m;i++)
        cout<<ans[q[i]-1]<<endl;
    return 0;

}
