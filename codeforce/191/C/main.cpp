#include <iostream>

using namespace std;
char a[100002];
long a0[100002],a5[100002];
int64_t k,a00=0,a55=0;
int main()
{
    cin>>a;
    cin>>k;
    long i;
    for( i = 0;a[i] != '\0'; i++){
        if(a[i] == '0')
            a0[a00++] = i;
        if(a[i] == '5')
            a5[a55++] = i;
    }
    int64_t sum = 0;
    while(k--){
        for()
    }

    return 0;
}
