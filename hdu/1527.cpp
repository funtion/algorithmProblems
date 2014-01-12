
#include <iostream>
using namespace std;
const int MAX = 10000;
bool win[MAX][MAX];
int main(){
    //win[0][0] = true;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(win[i][j] == false){
                for(int k=i+1;k<MAX;k++){
                    win[k][j] = true;
                }
                for(int k = j+1;k<MAX;k++){
                    win[i][k] = true;
                }
                for(int k=1;i+k<MAX&&j+k<MAX;k++){
                    win[i+k][j+k] = true;
                }
            }
        }
    }
    for(int i=0;i<MAX;i++){
        for(int j=i;j<MAX;j++){
            if(win[i][j] == false){
                cout<<i<<' '<<j<<endl;
            }
        }
    }
    /*
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(win[i][j]){
                cout<<"1 ";
            }else{
                cout<<"0 ";
            }

        }cout<<endl;
    }
    */
    return 0;
}

/*
#define B

#ifdef A
#include <iostream>
using namespace std;
typedef long long ll;
ll m[]={0,1,3,4,6};
ll n[]={0,2,5,7,10};
int main(){
    ll a,b,x,y;
    while(cin>>a>>b){
        x = min(a,b);
        y = max(a,b);
        x%=8;
        y%=13;
        bool win = true;
        for(int i=0;i<=4;i++){
            if(m[i] == x && n[i]==y){
                win = false;
                break;
            }
        }
        cout<<(win?1:0)<<endl;
    }
    return 0;
}
#endif
#ifdef B
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
 int a,b,c,k;

 while(cin>>a>>b)
 {
  
  if(a<b)
  {
   c=a;
   a=b;
   b=c;
  }
  k=abs(a-b);
  a =  (int)(k*( 1.0 + sqrt( 5.0 ) )/2.0);
  if(a==b)
   cout<<0<<endl;
  else
   cout<<1<<endl;
 }
 return 0;
}
#endif
#ifdef C
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    srand(time(0));
    for(int i=0;i<1000;i++){
        long long a = rand()%300,b = rand()%30;
        long long c = rand()%300,d = rand()%30;
        cout<<a*b<<' '<<c*d<<endl;
    }
    return 0;
}
#endif
*/