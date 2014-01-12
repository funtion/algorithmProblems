#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        bool x  = true;
        while(true){
            //cout<<n<<endl;
            if(x){
                n = ceil(double(n)/9);
            }else{
                n = ceil(double(n)/2);
            }
            if(n<=1)
                break;
            x = !x;
        }
        cout<<(x?"Stan wins.":"Ollie wins.")<<endl;
    }
}
