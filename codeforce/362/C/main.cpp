#include <iostream>

using namespace std;
int a[6000];
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
    cin>>a[i];
   int an = 0,ai,aj;
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        int x = 0;
        for(int k=i+1;k<j;k++){
            if(a[i]<a[k]&&a[k]<a[j])
                x++;
             if(a[j]<a[k]&&a[i]<a[j])
                x++;
        }
        int tp = x;

        if(a[j]<a[i]){
            tp++;
        }
        cout<<i<<' '<<j<<' '<<tp<<endl;
        if(tp<an){
            an = tp;
            ai = i;
            aj = j;
        }

    }
   }
    cout<<ai+1<<' '<<aj+1;
    return 0;
}
