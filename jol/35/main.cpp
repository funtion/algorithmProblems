#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long T;
T n;
string s,t;
bool cmp(string a,string b){
    for(size_t i=0;i<a.size() && i<b.size();i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
int main()
{
    while(cin>>n){
        cin>>s;
        T total=0;
        vector<string> sa;
        for(T i=0;i<n;i++){
            sa.push_back(s.substr(i,n-i));
        }
        sort(sa.begin(),sa.end());
        int m;
        cin>>m;
        while(m--){
            cin>>t;
            pair< vector<string>::iterator,vector<string>::iterator > pr;
            pr  = equal_range(sa.begin(),sa.end(),t,cmp);
            T ma =0;
            vector<string>::iterator ii = pr.first;
            while(ii != pr.second){
                if((*ii).length()>ma)
                    ma = (*ii).length();
                ii++;
            }
            total+=ma-t.length();
        }
        if(total %2 == 1){
            cout<<"ZhuZhu\n";
        }else{
            cout<<"YangYue\n";
        }
    }
    return 0;
}
