#include <iostream>

using namespace std;
long long n,a,b,ans,ans2,x,y;
int t;
inline long long ab(long long  x){
    return x>0?x:-x;
}
long long gcd(long long a,long long b){
  while( 1 )
    {
        a = a % b;
		if( a == 0 )
			return b;
		b = b % a;

        if( b == 0 )
			return a;
    }
}
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        ans = 0,ans2=0;
        long long gc = gcd(a,b);
        gc = (a*b)/gc;
        long long rm = n%gc;
        for(long long i=0;i<n;i++){
            x = i%a;
            y = i%b;
            ans+=ab(y-x);cout<<ab(y-x)<<endl;
            //if(i==rm-1){
           //     ans2 = ans;
           //     if(n/gc == 0)
           //         break;
          //  }

        }
        cout<<endl<< ans<<endl;
    }
    return 0;
}
