#include <iostream>
bool square[4][4];
using namespace std;

bool test(int i,int j)
{
    bool m = !square[i][j];
    for(int p=-1;p<=1;p+=2)
    {
        for(int q=-1;q<=2;q+=2)
        {
            int s = i+p;
            int t = j+q;
            if(s<0 || s>=4 || t <0 || t>=4)
                continue;
            else
            {
                if(square[s][t]==m && square[s][j] == m && square[i][t] == m)
                        return true;
            }
        }
    }
    return false;
}
 bool test()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
         bool t = square[i][j] ;
         if(t == square[i+1][j] && t == square[i][j+1] && t== square[i+1][j+1])
            return true;
        }
return false;
}
int main()
{
    char t;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>t;
            if(t== '#')
                square[i][j] = true;
            else
                square[i][j] = false;
        }
    }
    if(test())
    {
        cout<<"YES";
                return 0;
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(test(i,j))
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}
