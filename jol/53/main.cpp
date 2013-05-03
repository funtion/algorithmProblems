#include <iostream>
#include <cstring>
using namespace std;
bool box[10][3];
int main()
{
    int t;
    int n = 0,int times =0;
    memset(box,0,30*sizeof(bool));
    for(int i=0;i<20;i++){
        cin>>t;
        int j;
        for(j=2;j>=0;j--)
        {
            if(box[t][j] ==  false)
            {
                box[t][j] = true;
                break;
            }
        }
        int cou=0;
    }
    return 0;
}
