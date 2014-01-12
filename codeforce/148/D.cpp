#include <iostream>
using namespace std;
double win[1100][1100],lost[1100][1100];
int main(){
    int w,b;
    cin>>w>>b;
    for(int i=1;i<=w;i++)win[i][0]=1.0;
    for(int i=1;i<=b;i++)lost[0][i]=0.0;
    for(int i=1;i<=w;++i){
        for(int j=1;j<=b;++j){
            win[i][j] = double(i)/(i+j)+double(j)/(i+j)*lost[i][j-1];
            lost[i][j] = double(j)/(i+j)*(double(i)/(i+j-1)*win[i-1][j-1]+double(j-1)/(i+j-1)*win[i][j-2]);
        }
    }
    cout.precision(9);
    cout<<win[w][b];

}

