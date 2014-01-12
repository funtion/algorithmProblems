/*
ID: funtion
LANG: C++
TASK: friday
*/
#include <iostream>
#include <cstdio>
using namespace std;
int ans[500][8];
int m[]  = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int mp[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
struct date
{
    int year,month,day;
    int wk;

    bool isLeep(){
        if(year%4==0){
            if(year%100==0){
                if(year%400==0)
                    return true;
                return false;
            }else{
                return true;
            }
        }else{
            return false;
        }
    }
    void next(){
        bool leep = isLeep();
        day++;
        if( (leep&&day>mp[month])||(!leep&&day>m[month])){
            day = 1;
            month++;
            if(month>12){
                month=1;
                year++;
            }
        }
        wk++;
        if(wk>7)
            wk = 1;
    }
};
int main(){
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    date d;
    d.year = 1900;
    d.month = 1;
    d.day = 1;
    d.wk = 1;
    while(d.year<=2300){
        //if(d.year == 1904 &&d.month==12){
       //     cout<<"find "<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
       // }
        if(d.day == 13){
            ans[d.year-1900+1][d.wk]++;
            //cout<<"find 13 "<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
        }
        d.next();
    }
    int n;
    while(cin>>n){
        int ta[8]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=7;j++)
                ta[j]+=ans[i][j];
        }
        cout<<ta[6]<<' '<<ta[7]<<' ';
        for(int i=1;i<=4;i++){
            cout<<ta[i]<<' ';
        }
        cout<<ta[5];
        cout<<endl;
    }
}