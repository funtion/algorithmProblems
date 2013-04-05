#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
 int64_t n,q;
void query(int64_t a,int64_t b,int64_t *p2)
{
    //for(int64_t i=a;i<=b;i++)
       // p2[i]++;
       p2[a]++;
       if(b!=n)
            p2[b+1]--;
}
void query(int64_t* p2)
{
    for(int64_t i=1;i<=n;i++)
        p2[i]+=p2[i-1];
}
int compare(const void * a, const void * b)
{
    return (*(int64_t*)a-*(int64_t*)b);
}
int main()
{

    cin>>n>>q;
    int64_t *p1 = new int64_t[n+1];
    for(int64_t i=1;i<=n;i++)
        cin>>p1[i];
    int64_t *p2 = new int64_t[n+1];
    memset(p2,0,(n+1)*sizeof(int64_t));
    for(int64_t i=0;i<q;i++)
    {
        int64_t t1,t2;
        cin>>t1>>t2;
        query(t1,t2,p2);
    }
    query(p2);
    qsort(p1+1,n,sizeof(int64_t),compare);
    qsort(p2+1,n,sizeof(int64_t),compare);
    int64_t sum =0;
    for(int64_t i=1;i<=n;i++)
    {
        sum +=p1[i]*p2[i];
    }
    cout<<sum;
    delete p1;
    delete p2;
    return 0;

}
