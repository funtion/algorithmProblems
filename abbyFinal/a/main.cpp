#include <iostream>

using namespace std;
long long n,sum,mi,mj,mk;
long long nums[200000];
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>nums[i];
        }
        sum=-0xfffffff;
        mi=0,mj=n+1,mk=0;
        for(int i = 1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(nums[i] != nums[j])
                    continue;
                long long s = 0,kk=0;
                for(int k=i;k<=j;k++){
                    if(k==i || k== j)
                        s+=nums[k];
                    else if(nums[k]>0)
                        s+=nums[k];
                    else
                        kk++;
                }
                if(s>sum){
                    sum = s;
                    mi = i;
                    mj = j;
                    mk = kk;
                }

            }


        }
        long long  k =0;
        if(mi-1>0)
            k+=mi-1;
        if(n-mj>0)
            k+=n-mj;
        cout<<sum<<' '<<k+mk<<endl;
        if(mi==0 && mj ==0){
            for(int i=1;i<=n;i++){
                cout<<i<<' ';
            }
            cout<<endl;
            continue;
        }
            for(int i=1;i<=mi-1;i++)
                cout<<i<<' ';
            for(int i=mi+1;i<=mj-1;i++){
                if(nums[i]<0)
                    cout<<i<<' ';
            }
            for(int i=mj+1;i<=n;i++){
                    cout<<i<<' ';
            }

        cout<<endl;

    }
    return 0;
}
/////////////////////////////////////////////
#include <iostream>
#include <cstring>
long long  a[300001],n,i,j,k,top,t,c[300001],cut[300001],ans,s;
using namespace std;
int main()
{
    cin>>n;
    ans=-9999999999;
    for (i=1;i<=n;i++)
        cin>>a[i];

    for (i=1;i<=n-1;i++)
    {
        memset(c,0,sizeof(c));
        j=n;
        t=n-2;

        while (a[j]!=a[i]) j--;
        if (i==j) continue;
        s=a[i]+a[j];
        c[i]=1;c[j]=1;
        for(k=i+1;k<=j-1;k++)
        {
            if (a[k]>=0)
            {
                t--;
                s+=a[k];
                c[k]=1;
            }

        }
        if (s>ans)
        {
            top=t;
            ans=s;
            for (k=1;k<=n;k++)
                cut[k]=c[k];
        }
    }
    j=1;
    cout<<ans<<' '<<top<<endl;
    while (cut[j]!=0) {
            j++;
    }
    if (j>n) return 0;
        cout<<j;
    for (i=j+1;i<=n;i++)
        if (cut[i]==0) cout<<' '<<i;
    return 0;
}
