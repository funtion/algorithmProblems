#include<iostream>
using namespace std;
int main(){
    int a[100100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] == i)
            cnt++;
    }
    bool flg = false;
    for(int i=0;i<n;i++){
        if(a[i]!=i){
            int j = a[i];
            if(a[j]==i){
                cnt+=2;
                flg = true;
                break;
            }
        }
    }
    if(!flg&&cnt<n)
        cnt++;
    cout<<cnt<<endl;
}

