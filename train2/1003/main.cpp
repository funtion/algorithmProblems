#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int T;
long N;
struct st{
    long long w,h;
    int id;
    bool operator<(const st& r) const{
        if(w!=r.w)
            return w<r.w;
        if(h!=r.h)
            return h<r.h;
        return id<r.id;
    }
};
st x[200000];
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        for(long i=0;i<N;i++){
            //cin>>x[i].w>>x[i].h;
            scanf("%lld %lld",&x[i].w,&x[i].h);
            x[i].id = 1;
        }
        for(long i=N;i< N<<1;i++){
            //cin>>x[i].w>>x[i].h;
            scanf("%lld %lld",&x[i].w,&x[i].h);
            x[i].id = 0;
        }
        sort(x,x+(N<<1));
        long sum=0,nb=0;
        for(long i=0;i< N<<1;i++){
            if(nb>0  &&x[i].id == 1 ){
                nb--;
                sum++;
            }else{
                nb++;
            }

        }
        cout<<sum<<endl;
    }
}
