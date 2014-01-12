#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
typedef int ll;
using namespace std;
ll N;
char s[10];
ll a;
const string add("add"),del("del"),sum("sum");
int main()
{
    while(scanf("%d",&N)!=EOF){
        vector<ll> v;

        for(ll i=0;i<N;i++){
            scanf("%s",s);
            if(s == add){
                scanf("%d",&a);
                v.insert(lower_bound(v.begin(),v.end(),a),a);
            }else if(s == del){
                scanf("%d",&a);
                v.erase(lower_bound(v.begin(),v.end(),a));
            }else{
                long long  ss=0;
                for(unsigned int i=2;i<v.size();i+=5){
                    ss+=v[i];
                }
                printf("%I64d\n",ss);
            }
        }
    }
    return 0;
}
