#include <iostream>

using namespace std;
int n;
char s[256];
int main()
{
    while(cin>>n,n!=0){
        char t[3][256];
        char tt;
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                cin>>tt;
                t[i]['A'+j] = tt;
            }
        }
        int nn;
        cin>>nn;
        while(nn--){
            cin>>s;
            char *ss =s;
            while(*ss!='\0'){
                char r = t[0][*ss];
                r = t[1][r];
                r = t[2][r];
                ss++;
                cout<<r;
            }
            cout<<endl;
        }
    }
    return 0;
}
