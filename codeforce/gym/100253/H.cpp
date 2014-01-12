#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,len;
    char s[6000];
    int a[6000];
    a[0] = 0;
    cin>>n>>s;
    len = strlen(s);
    for(int i=0;s[i];i++){
        if(s[i]=='='){
            a[i+1] = a[i];
        }else if(s[i]=='<'){
            a[i+1] = a[i]+1;
        }else{
            a[i+1] = a[i]-1;
        }
    }
    int mx=-1000,mi=1000;
    for(int i=0;i<=len;i++){
        if(a[i]>mx)mx = a[i];
        if(a[i]<mi)mi = a[i];
    }
    //cout<<mx<<' '<<mi<<endl;
    if(mx-mi>=n){
        cout<<"-1\n";
    }else{
        for(int i=0;i<=len;i++){
            cout<<char(a[i]-mi+'a');
        }
        cout<<endl;
    }
}
