#include <iostream>
int n,l;
using namespace std;

int main()
{
   cin>>n>>l;
   int sa=0,sb=0,a,b,s;
   while(n--){
        cin>>a>>b;
        if(b==-1)
            s = 1;
        else if(b<=l)
            s=2;
        else
            s=3;

        if(a==1)
            sa+=s;
        else
            sb+=s;
   }
   cout<<sa<<':'<<sb<<endl;
}
