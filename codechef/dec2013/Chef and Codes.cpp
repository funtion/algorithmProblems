#include<cstdio>
#include<algorithm>
#include<map>
#include<iostream>
struct node{
    char x;
    int f;
    bool operator<(const node& r)const{
        if(f == r.f)
            return x<r.x;
        return f<r.f;
    }
}ns[30];
using namespace std;
char frq[30],s[150010];
int main()
{
    int t;
    char fk;
    cin>>t;
    cin.get(fk);
    while(t--){

        cin.getline(frq,150010);
        cin.getline(s,150010);
        //cout<<"frq="<<frq<<endl;
        //cout<<"s="<<s<<endl;
        for(int i=0;i<26;i++){
            ns[i].x = 'a'+i;
            ns[i].f = 0;
        }
        for(int i=0;s[i];i++){
            if( 'a'<=s[i] && s[i]<='z'){
                ns[s[i]-'a'].f++;
            }
            if( 'A'<=s[i] && s[i]<='Z'){
                ns[s[i]-'A'].f++;
            }
        }
        sort(ns,ns+26);
        //for(int i=0;i<26;i++){
        ////    cout<<ns[i].x;
        //}
        //cout<<endl;
        map<char,int> mp;
        for(int i=0;i<26;i++){
            mp[ns[i].x] = i;
        }
        for(int i=0;s[i];i++){
            char t;
            int id;
            if( 'a'<=s[i] && s[i]<='z'){
                id = mp[s[i]];
                t = frq[id];
                 cout<<t;
                //cout<<"id="<<id<<"t="<<t<<endl;
            }else if( 'A'<=s[i] && s[i]<='Z'){
                //cout<<"!!!\n";
                id = mp[s[i]-'A'+'a'];
                t = frq[id];
                cout<<char(t+'A'-'a');
            }else{
               // cout<<"$$$\n";
                t = s[i]; cout<<t;
            }

        }
        if(t)
            cout<<endl;

    }
    return 0;
}
