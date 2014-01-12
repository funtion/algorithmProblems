#include<iostream>
using namespace std;
char s[200000];
int c[200000][3];
int n,x,y;
int main()
{
    //ios::sync_with_stdio(0);

    cin>>s;
    for(int i=0;s[i];i++){
        c[i+1][0] = c[i][0];
        c[i+1][1] = c[i][1];
        c[i+1][2] = c[i][2];
        if(s[i]=='x')
            c[i+1][0]++;
        else if(s[i]=='y')
            c[i+1][1]++;
        else
            c[i+1][2]++;
    } //cout<<"!!!!!!!!!!\n";

   // for(int i=0;s[i];i++){
   //         cout<<c[i+1][0]<<' ';
   //          cout<<c[i+1][1]<<' ';
   //          cout<<c[i+1][2]<<endl;
   // }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;

        int xx = c[y][0]-c[x-1][0];
        int yy = c[y][1]-c[x-1][1];
        int zz = c[y][2]-c[x-1][2];

       // cout<<xx<<' '<<yy<<' '<<zz<<endl;
        int len = y-x+1;
        if(len<=2)
        {
            cout<<"YES\n";
            continue;
        }
        if( len %3 == 0)
        {
            if(xx==yy&&yy==zz)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(len%3 == 1){
            if(xx==yy+1&&xx==zz+1)
                cout<<"YES\n";
            else if(yy==xx+1&&yy==zz+1)
                cout<<"YES\n";
            else if(zz==yy+1&&zz==xx+1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else{
            if(xx==zz+1&&yy==zz+1)
                cout<<"YES\n";
            else if(yy==xx+1&&zz==xx+1)
                cout<<"YES\n";
            else if(xx==yy+1&zz==yy+1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;

}



