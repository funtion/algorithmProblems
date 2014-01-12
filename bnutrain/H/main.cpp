#include <iostream>
#include <string>
#include <algorithm>
#define MAX 30
using namespace std;
int n,T;
int sc[MAX];
string s[MAX],t[MAX];
int top;
int main()
{
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i]>>sc[i];
        }
        top = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int ss = sc[i]+sc[j];
                bool xxx = false;
                for(int k=0;k<n;k++){
                    if(k==i ||k==j)
                        continue;
                    if(sc[k] == ss){
                        t[top++] = s[k];
                        xxx = true;
                    }
                }
                if(xxx)
                    continue;
                for(int l = j+1;l<n;l++){
                    int sss = ss + sc[l];
                    for(int k=0;k<n;k++){
                        if(k==i ||k==j|| k == l)
                            continue;
                        if(sc[k] == sss)
                            t[top++] = s[k];
                    }
                }
            }
        }
        sort(t,t+top);
        cout<<top<<endl;
        for(int i=0;i<top;i++){
            cout<<t[i]<<endl;
        }
    }
    return 0;
}
