#include<iostream>
#include<algorithm>
using namespace std;
int a[200];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    swap(a[0],a[n-1]);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}
