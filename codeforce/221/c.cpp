#include <iostream>
#include <algorithm>
using namespace std;
char s[1001000];
int cnt[10];
int len;
int ten[20];
void force(){
     do{
            int t =0,k =  1;
            for(int i=len-1;i>=0;i--){
                t+=(s[i]-'0')*k;
                k*=10;
            }
            if(t %7==0){
                cout<<t<<endl;
                break;
            }
        }while(next_permutation(s,s+len));
}
bool dfs(int location,int value,int tans){
    //cout<<location<<' '<<value<<' '<<tans<<endl;
    if(location >=6){
        int a = tans/1000,b = tans%1000;
        //cout<<"a="<<a<<"b="<<b<<endl;
        if( tans!= 0&& (b-a)%7 == 0){
            for(int i=1;i<=9;i++){
                for(int j=0;j<cnt[i];j++){
                    cout<<i;
                }
            }
            for(int i=0;i<cnt[i];i++){
                cout<<0;
            }
            cout<<tans<<endl;
            return true;
        }else{
            return 0;
        }
    }else{
        bool has = false;
        for(int i=0;i<=9;i++){
            if(cnt[i]>0){
                //cout<<"appending"<<i<<endl;
                //cout<<tans<<' '<<i*ten[location]<<endl;
                has = true;
                cnt[i]--;
                if(dfs(location+1,i,tans+i*ten[location])){
                    return true;
                }
                cnt[i]++;
            }
        }
        if(!has){
            dfs(location+1,0,tans);
        }
    }
}
int main(){
    ten[0] = 1;
    for(int i=1;i<=10;i++)
        ten[i] = ten[i-1]*10;
    cin>>s;
    for(int i=0;s[i];i++){
        cnt[s[i]-'0']++;
        len++;
    }
    if(!dfs(0,0,0)){
        cout<<"0\n";
    }
    return 0;
}