#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
struct mk{
    ll id,grade;
    bool operator<(const mk&r)const {
        return grade<r.grade;
    }
};
int go(){
    ll n,x,y;
    mk mm={1,1000000000},nmk;
    scanf("%I64d",&n);
    if(n==0)return 0;
    vector<mk> mks;
    mks.push_back(mm);//printf("mks = %I64d\n",mks.begin()->grade);
    for(ll i=0;i<n;i++){
        scanf("%I64d%I64d",&x,&y);
        nmk.id=x;nmk.grade=y;
        vector<mk>::iterator it;
        if(nmk< mks.front()){
            it = mks.begin();
            printf("%I64d %I64d\n",x,it->id);
            mks.insert(it,nmk);
        }
        else if(! (nmk<mks.back())){
            it = mks.end()-1;
            printf("%I64d %I64d\n",x,it->id);
            mks.insert(it,nmk);
        }
        else
        {
            it = lower_bound(mks.begin(),mks.end(),nmk);
            //printf("it=%I64d,it-1=%I64d\n",it->grade,(it-1)->grade);
            if(it->grade - y < y - (it-1)->grade){
                printf("%I64d %I64d\n",x,(it)->id);
            }else{
                printf("%I64d %I64d\n",x,(it-1)->id);
            }
            mks.insert(it,nmk);
        }


        //for(vector<mk>::iterator i=mks.begin();i!=mks.end();i++){
        //    printf("%I64d:%I64d ",i->id,i->grade);
       // }
       // puts("");
    }
    return 1;
}
int main(){
    while(go()!=0);
    return 0;
}
