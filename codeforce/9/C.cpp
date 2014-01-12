#include <iostream>
inline int pow(int x,int y)
{
    int a=1;
    while(y--)
    {
        a*=x;
    }
    return a;

}
using namespace std;

int n;
int g(int x){
    int tp=0;
    //cout<<x<<endl;
    for(int i=0;i<10;i++){
        if(x&(1<<i))
        {
            tp+=pow(10,i);
            //cout<<"tp"<<tp<<endl;
        }
    }

    return tp;
}
int main(){
    cin>>n;
    //cout<<"gt"<<g(4)<<endl;
    int ans = 0,t=1;
    while(t< (1<<10) ){
        //
        if(g(t)<=n)
        {
            ans++;//cout<<"gt :"<<g(t)<<endl;
        }

        t++;
    }
    cout<<ans;
}
