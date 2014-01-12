#include <iostream>

using namespace std;
int t;
long g,l;
long div[10000],cd;
inline long lcm(long x,long y,long z){

}
int main()
{
    cin>>t;
    while(t--){
        cin>>l>>g;
        if(g%l!=0){
            cout<<0<<endl;
        }else{
            g/=l;
            cd=0;
            for(long i=1;i<=g/2;i++){
                if(g%i==0){
                    div[cd++] = i;
                }
            }
            long ans = 0;
            for(int i=0;i<cd;i++){
                for(int j=0;j<cd;j++){
                    for(int k=0;k<cd;k++){
                        if(lcd(i,j,k)==1){
                            ans++;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
