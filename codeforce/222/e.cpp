#include <iostream>
using namespace std;
typedef long long ll;
ll n;
int m,k;
const ll md = 1000000007;
struct matrix
{
    ll ma[60][60];
    matrix(){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                ma[i][j] = 1;
        }
    }
    matrix operator*(const matrix& r) const {
        matrix rr;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                ll tmp = 0;
                for(int k=0;k<m;k++){
                    tmp+=ma[i][k]*r.ma[k][j];
                    tmp%=md;
                }
                rr.ma[i][j] = tmp;
            }
        }
        return rr;
    }

    matrix operator^(ll n) const{
        matrix rr;
        if(n==0){
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    rr.ma[i][j] = (i==j);
                }
            }
            return rr;
        }
            
        if(n==1)
            return *this;
        matrix tmp = this->operator^(n/2);
        rr = tmp*tmp;
        if(n%2 == 1)
            rr =rr*(*this);
        return rr;
    }
    void forbid(int x,int y){
        ma[x][y] = 0;
    }
    ll sum() const{
        ll ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                ans+=ma[i][j];
                ans%=md;
            }
        }
        return ans;
    }
};
int main(){
    cin>>n>>m>>k;
    matrix mt;
    char x,y;
    int xx,yy;
    while(k--) {
        cin>>x>>y;
        if('a'<=x&&x<='z'){
            xx = x-'a';
        }else{
            xx = x-'A'+26;
        }
        if('a'<=y&&y<='z'){
            yy = y-'a';
        }else{
            yy = y-'A'+26;
        }
        mt.forbid(xx,yy);
    }
    matrix mm = mt^(n-1);
    ll ans = mm.sum();
    cout<<ans<<endl;
    return 0;
}