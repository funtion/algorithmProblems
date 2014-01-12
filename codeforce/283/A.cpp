#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;
ll n,a[200010],sum,cnt=1,x,y;
int cmd;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){
        cin>>cmd;
        switch(cmd){
        case 1:
            cin>>x>>y;
            a[x]+=y;
            sum+=x*y;
            break;
        case 2:
            cin>>x;
            sum+=x;
            a[cnt]-=x;
            a[++cnt]+=x;
            break;
        case 3:
            sum-=a[cnt];
            a[cnt-1]+=a[cnt];
            a[cnt]=0;
            cnt--;
            break;
        default:
            break;
        }
        cout<<fixed<<setprecision(6)<<double(sum)/cnt<<endl;
    }
}
