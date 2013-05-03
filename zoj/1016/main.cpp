#include <iostream>
#include <cstring>
using namespace std;
int t;
int n;
char p[40];
bool used[40];
int main()
{
    cin>>t;
    while(t--){
        int l=0,r;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>r;
            while(l<r){
                p[l+i]='(';
                l++;
            }
            p[l+i]=')';
        }
        memset(used,false,sizeof(used));
        for(int i=0;i<n*2;i++){
            if(p[i] == ')'){
                int t=0;
                for(int j=i-1;j>=0;j--){

                    if(p[j]=='('){
                        t++;
                        if(!used[j]){
                            used[j] = true;
                            cout<<t;
                            if(i!=2*n-1){
                                cout<<' ';
                            }
                            break;
                        }
                    }
                }
            }
        }
        if(t!=0)
            cout<<endl;
    }
    return 0;
}
