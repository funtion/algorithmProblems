#include<iostream>
using namespace std;
int pr[100100];
int main(){
    int n,p,a,b;
    int s = 0;
    cin>>n>>p>>a>>b;
    for(int i=0;i<n;i++){
        cin>>pr[i];
    }
    int ic=0,dc = 0;
    for(int i=1;i<n;i++){
        if(pr[i]>pr[i-1]){
            ic++;
            dc = 0;
            if(p/pr[i]<a*ic){
                s+=p/pr[i];
                p%=pr[i];
            }else{
                s+=a*ic;
                p-=a*ic*pr[i];
            }
        }else if(pr[i]<pr[i-1]){
            ic = 0;
            dc++;
            if(s<b*dc){
                p+=s*pr[i];
                s=0;
            }else{
                p+=b*dc*pr[i];
                s-=b*dc;
            }
        }
    }
    cout<<p<<' '<<s<<endl;

}
