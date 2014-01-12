#include<iostream>
#include<algorithm>
using namespace std;
int a[400][400];
int n,q;
struct bit{
    int c[400][400];
    bit(){
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                c[i][j] = 0;
    }
    inline int lowbit(int x){
        return x&(-x);
    }
    void add(int xx,int yy){

        for(int x = xx;x<=n;x+=lowbit(x)){
            for(int y = yy;y<=n;y+=lowbit(y)){
                c[x][y]++;
                //cout<<"x = "<<x<<" y = "<<y<<endl;
            }
        }

    }
    int sum(int xx,int yy){
        int a = 0;

        for(int x = xx;x>0;x-=lowbit(x))
            for(int y = yy;y>0;y-=lowbit(y))
                a+=c[x][y];
        return a;
    }
    int get(int x1,int x2,int y1,int y2){
        return sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
    }

}b[20];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            b[ a[i][j] ].add(i,j);
            //cout<<"add "<<a[i][j]<<"at "<<i<<' '<<j<<endl;
        }
    }
    /*
    for(int i=1;i<=10;i++){
        cout<<i<<":\n";
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++)
                cout<<b[i].sum(j,k)<<' ';
            cout<<endl;
        }
        cout<<endl;

    }
    */
    cin>>q;
    int x1,x2,y1,y2;
    for(int i=0;i<q;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        int ans = 0;
        for(int i=1;i<=10;i++){
            int tt = b[i].get(x1,x2,y1,y2);
            //cout<<"i= "<<i<<" tt= "<<tt<<endl;
            if( tt > 0)
                ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
