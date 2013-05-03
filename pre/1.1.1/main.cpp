#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int n;
unsigned int result = -1;
int *limit,**table;
bool *isvisited;
ifstream in;
void deep(int depth,int position,int time,int totaltime)
{
    if(depth == n-1)
    {
        if(totaltime<result)
        {
            result = totaltime;
        }
        return ;
    }
    else
    {
        isvisited[position] = true;
        for(int i=1; i<n; i++)
        {
            if(!isvisited[i])
            {
                if(time + table[position][i] <=limit[i])
                {
                    deep(depth+1,i,time+table[position][i],totaltime+time+table[position][i]);
                }
            }
        }
        isvisited[position] = false;
    }
}
int go()
{
    result = -1;
    in>>n;
    if(n==0)
    {
        return false;
    }
    table = new int*[n];
    for(int i=0; i<n; i++)
    {
        table[i] = new int[n];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            in>>table[i][j];
        }
    }
    isvisited = new bool[n];
    memset(isvisited,0,n*sizeof(bool));
    isvisited[0] = true;
    limit = new int[n];
    for(int i=1; i<n; i++)
    {
        in>>limit[i];
    }

    deep(0,0,0,0);
    if(result !=-1)
    {
        cout<<result<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return true;
}
int main()
{
    in.open("in.txt");
    while(go())
        ;
    return 0;
}
