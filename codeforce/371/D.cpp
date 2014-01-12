#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;
int n,m;
int a[300000],o[300000];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>o[i];
    o[n+1] = INT_MAX;
    set<int> st;
    for(int i = 1;i<=n; i++){
        st.insert(i);
        //o[i] = a[i];
        //a[i] = 0;
    }
    cin>>m;
    int cmd,x,y;
    for(int i=0;i<m;i++){
        cin>>cmd;

        if( cmd == 1){
            
            cin>>x>>y;
            /*
            set<int>::iterator p = st.lower_bound(x);
            if( p == st.end())
                p = st.upper_bound(x);
            while(y > 0 && p!=st.end()){
                if (a[*p] >= y)
                {
                    a[*p] -= y;
                    y = 0;
                }
                else
                {
                    y -=a[*p];
                    a[*p] = 0;
                    set<int>::iterator q = st.lower_bound(*p);
                    st.erase(q);
                    p = st.upper_bound(*p);
                }
            }
            */
            set<int>::iterator it = st.lower_bound(x);
            while(it != st.end() && y){
                int sp = min(y,o[*it] - a[*it]);
                y -= sp;
                a[*it]+=sp;
                if(o[*it] == a[*it]){
                    st.erase(it++);
                }

            }
        }else{
            cin>>x;
            cout<<a[x]<<endl;
        }
        /*
        for(int i=1;i<=n;i++){
            cout<<i<<' '<<a[i]<<endl;
        }
        cout<<"in set\n";
        for(int i=1;i<=n;i++){
            if(find(st.begin(), st.end(),i) != st.end())
                cout<<i<<' ';
        }
        cout<<endl;
        */
    }
    return 0;
}