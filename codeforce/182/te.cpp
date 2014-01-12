#include<iostream>
#include <cstring>
using namespace std;
char words[50][50];
int time[50]={0};
int Process(char []);

int main()
{
    char input[50]="This is an apple,that is an apple,too";
    int size=Process(input);
    for(int counter=0;counter<size;counter++)
    {
        cout<<words[counter]<<"\t"<<time[counter]<<endl;
    }
    return 0;
}

int Process(char input[])
{
    int counter=0;
    char temp[50]="";
    strcpy(words[counter],strtok(input," ,."));
    time[0]++;

    while(1)
    {
        strcpy(temp,strtok(NULL," ,."));
        char n[]="";
        if(!strcmp(temp,n))
            break;
        for(int c2=0;c2<counter;c2++)
        {
            if(!strcmp(temp,words[c2]))
            {
                counter--;
                time[c2]++;
                break;
            }
            else
            {
                strcpy(words[counter],temp);
            }
        }
    }
    return counter;
}
