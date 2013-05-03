#include <iostream>
#define pmax 10000001
using namespace std;
bool p[pmax];
int main()
{
    p[0]=p[1] = false;
    //p[2] = true;
    for(long i=2;i<pmax;i++){
        p[i] = true;
    }
    for(long i=2;i<pmax;i++){
        if(p[i] == true){
            for(long j = i*2;j<pmax;j+=i){
                p[j] = false;
            }
        }
    }
    long a,b;
    while(cin>>a>>b){
        while(!p[a])
            a++;
        do{
            b--;
        }
        while(!p[b]);
        long sum = 0;
        for(long i=a;i<=b;i++){
            if(p[i]){
                sum++;
            }

        }
        cout<<sum<<endl;
    }


    return 0;
}
