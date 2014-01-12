#include <iostream>
#include <cmath>
using namespace std;
const double esp = 1e-9;
long long x;
int main()
{
    cin>>x;
    for(int i=0;i<x;i++){
        if ((i*i-1)%8 == 0)
            cout<<i<<endl;
    }
    return 0;
}
