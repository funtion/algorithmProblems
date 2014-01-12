#include<iostream>
using namespace std;
int cnt[8];
int main()
{
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        cnt[x]++;
    }
    if(cnt[5]>0||cnt[7]>0||cnt[1]!=n/3||cnt[2]+cnt[3]!=n/3)
    {
        cout<<-1<<endl;
    }
    else
    {
        int a = cnt[4];
        int c = cnt[3];
        int b = n/3-a-c;
        if(b<0){
            cout<<-1;
        }
        if( a+b!=cnt[2]||b+c!=cnt[6] ){
            cout<<-1;
        }else{
            for(int i=0;i<a;i++){
                cout<<"1 2 4\n";
            }
            for(int i=0;i<b;i++){
                cout<<"1 2 6\n";
            }
            for(int i=0;i<c;i++){
                cout<<"1 3 6\n";
            }
        }
    }
    return 0;
}
