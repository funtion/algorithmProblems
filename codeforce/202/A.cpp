#include<iostream>
using namespace std;
int main()
{
    int n25=0,n50 = 0,n,an[100010];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>an[i];
    for(int i=0;i<n;i++)
    {
        if(an[i]==25)
            n25++;
        else if(an[i]==50)
        {
            if(n25>0)
            {
                n25--;
                n50++;
            }
            else
            {
                    cout<<"NO\n";
                    return 0;

            }
        }else{
            if(n50>0&&n25>0)
            {
                n50--;
                n25--;
            }
            else if(n25>2)
            {
                n25-=3;
            }
            else
            {
                    cout<<"NO\n";
                    return 0;
            }

        }
    }
    cout<<"YES\n";
    return 0;
}
