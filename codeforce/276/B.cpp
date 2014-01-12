#include <iostream>
using namespace std;
char in[1005],*p=in;
int cnt[256],odd;
int main(){
    cin>>in;
    while(*p !='\0'){
        cnt[*p++]++;
    }
    for(int i='a';i<='z';i++){
        if(cnt[i]&1)odd++;
    }
    if(odd<=1)cout<<"First\n";
    else if(odd&1)cout<<"First\n";
    else cout<<"Second\n";
}
