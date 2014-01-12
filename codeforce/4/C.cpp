#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    int n;
    map<string,int> mp;
    string x;
    cin>>n;
    while(n--){
        cin>>x;
        if(mp.find(x)==mp.end()){
            cout<<"OK\n";
            mp[x] = 0;
        }else{
            mp[x]++;
            cout<<x<<mp[x]<<endl;
        }
    }

}
