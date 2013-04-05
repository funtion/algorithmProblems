#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;
    while(cin>>s,s!="0")
    {
        int l = s.length();
        int *x = new int[l];
        x[0]=1;
        for(int i=1;i<l;i++)
        {

            if(s[i]=='0')
            {
                if(i==1)
                    x[i] = x[0];
                else
                    x[i] =x[i-2];
            }
            else if( (s[i-1]=='1') || (s[i-1] == '2' && s[i] <='6'))
            {
                if(i==1)
                    x[i] = x[i-1]+1;
                else
                    x[i] =x[i-1]+x[i-2];
            }
            else
            x[i] = x[i-1];

        }
        cout<<x[l-1]<<endl;
        delete[] x;
    }

    return 0;
}
