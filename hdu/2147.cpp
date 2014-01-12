#include <iostream>
using namespace std;


int main(){
    int m,n;
    while(cin>>m>>n&&(m+n)){
        m%=2;
        n%=2;
        if(m==1&&n==1)
            cout<<"What a pity!\n";
        else
            cout<<"Wonderful!\n";
    }
    return 0;
}