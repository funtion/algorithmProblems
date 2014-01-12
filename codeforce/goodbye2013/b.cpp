#include <iostream>
using namespace std;
int n,m,k;
int a[400];
int tot;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tot+=a[i];
    }
    int pos = 0,dir = 0;
    while(tot){
        if(a[pos]){
            cout<<'P';
            tot--;
            a[pos]--;
        }
        if(pos == 0){
            dir = 0;
            cout<<'R';
            pos++;
        }else if(pos == n-1){
            dir = 1;
            cout<<'L';
            pos--;
        }else{
            if(dir==0)
                cout<<'R',pos++;
            else
                cout<<'L',pos--;
        }
    }
    cout<<endl;
    return 0;
}