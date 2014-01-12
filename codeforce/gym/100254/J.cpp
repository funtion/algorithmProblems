#include<iostream>
#include<cstring>
char in[100];
bool l[100],r[100];
using namespace std;
int main(){
    int len;
    cin>>len>>in;
    l[0] = true;
    r[len-1] = true;
    int cnt=0;
    for(int i=0;in[i];i++){
        if(in[i]=='S'){
            l[i] = r[i] = true;
            cnt = 0;
        }else{
            if(cnt%2==0){
                l[i] = true;
            }else{
                r[i] = true;
            }
            cnt++;
        }
    }
    int ans = 0;
    for(int i=0;in[i];i++){
        if(l[i]){
            ans++;
            l[i] = false;
        } else if(r[i]){
            ans++;
            r[i] = l[i+1]=false;
        }
    }
    cout<<ans<<endl;


}
