#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long T;
T n,k;
T ns[20000];
int main()
{
    while(cin>>n>>k){
        for(T i=0;i<n;i++){
            cin>>ns[i];
        }
        vector<T> nn;
        for(T i=0;i<n;i++){
            T s=0;
            for(T j=i;j<n;j++){
                s+=ns[j];
                nn.push_back(s);
            }
        }
        nth_element(nn.begin(),nn.begin()+k-1,nn.end());
        cout<<nn[k-1]<<endl;
    }
    return 0;
}
