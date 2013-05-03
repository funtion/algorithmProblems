#include <iostream>
using namespace std;
bool m[200][200];
int a,b;
struct mo{
    int mi;
    int ma;
    char po;
};
mo mos[10000];
int n;
bool va(int i,int j){
    if(i<0 || i>=a || j<0 || j>=b)
        return false;
    return true;
}
bool con(int i,int j,int k){
    if(!va(i,j) || m[i][j])
    {
        return false;
    }
    if(k>=n){
        return true;
    }else{
        int mi = mos[k].mi;
        int ma = mos[k].ma;
        char po= mos[k].po;
        int in,jn;
        for(int l=mi;l<=ma;l++){
            switch(po){
                case 'R':{
                    in=i;
                    jn=j+l;
                    if(jn>=b){
                        return false;
                    }
                    for(int ll=j;ll<=jn;ll++){
                        if(m[in][ll])
                            return 0;
                    }
                    if(m[in][jn])
                        return 0;
                    break;
                }

                case 'L':{
                    in = i;
                    jn = j-l;
                    if(jn<0){
                        return false;
                    }
                    for(int ll=j;ll>=jn;ll--){
                        if(m[in][ll])
                            return 0;
                    }
                    break;
                }

                case 'U':{
                    in = i-l;
                    jn = j;
                    if(jn<0){
                        return 0;
                    }
                    for(int ll=i;ll>=in;ll--){
                        if(m[ll][jn])
                            return false;
                    }
                    break;
                }

                 case 'D':{
                    in = i+l;
                    jn = j;
                    if(in>=a){
                        return false;
                    }
                    for(int ll=i;ll<=in;ll++){
                        if(m[ll][jn])
                            return false;
                    }
                    break;
                }
                default:return false;
            }
            if(con(in,jn,k+1)){
                return true;
            }

        }

    }
return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cin>>m[i][j];
            }
        }
        int i,j;
        char c;
        n=0;
        while(cin>>i>>j,i+j!=0){
            cin>>c;
            mos[n].mi=i;
            mos[n].ma=j;
            mos[n].po=c;
            n++;
        }
        int sum=0;
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                if(!m[i][j]){
                    bool tt = con(i,j,0);
                    //cout<<i<<','<<j<<tt<<endl;
                    if(tt)
                        sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
