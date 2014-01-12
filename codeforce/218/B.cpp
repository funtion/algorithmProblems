#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> qa;
priority_queue<int,vector<int>,greater<int> > qb;
int n,m,p[1005],aa,ab;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>p[i];
        qa.push(p[i]);
        qb.push(p[i]);
    }
    for(int i=0;i<n;i++){
        int pa = qa.top();qa.pop();
        aa+=pa;pa--;
        if(pa>0)qa.push(pa);

        int pb = qb.top();qb.pop();
        ab+=pb;pb--;
        if(pb>0)qb.push(pb);
    }
    cout<<aa<<' '<<ab<<endl;
}
