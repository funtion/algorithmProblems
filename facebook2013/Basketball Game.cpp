#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n,m,p;
struct fk{
    string name;
    int shot_percentage,height;
    int time;
    int drift;
}a[100];
bool cmp(const fk& l,const fk& r){
    if(l.shot_percentage == r.shot_percentage){
        return l.height > r.height;
    }
    return l.shot_percentage > r.shot_percentage;
}
struct cmp2{
    bool operator()(const fk& l,const fk& r){
        if(l.time == r.time){
            return l.drift<r.drift;
        }
        return l.time < r.time;
    }
};

struct cmp3{
    bool operator()(const fk& l,const fk& r){
    if(l.time == r.time){
        return l.drift>r.drift;
    }
    return l.time > r.time;
}
};

int main(){
    int t;
    cin>>t;
    for(int cs=1;cs<=t;cs++){
        cin>>n>>m>>p;
        for(int i=0;i<n;i++){
            cin>>a[i].name>>a[i].shot_percentage>>a[i].height;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            a[i].time = 0;
            a[i].drift = i;
        }
        if(2*p < n){
            priority_queue<fk,vector<fk>,cmp2> a1,b1;
            priority_queue<fk,vector<fk>,cmp3> a2,b2;
            for(int i=0;i<n;i++){
                if(n<p*2){
                    if(i%2){
                        a1.push(a[i]);
                    }else{
                        b1.push(a[i]);
                    }
                }else{
                    if(i%2){
                        a2.push(a[i]);
                    }else{
                        b2.push(a[i]);
                    }

                }



            }
            for(int i=0;i<m;i++){
                fk t1 = a1.top();a1.pop();
                fk t2 = a2.top();a2.pop();

            }

        }
    }
}
