#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{

    const char a[]="_abcdefghijklmnopqrstuvwxyz.";
    char  bbbb[200];
    int s = sizeof(a);
    for(int i=0;i<s;i++){
        bbbb[(int)a[i]] = i;
    }
    string c,plaintext;
    unsigned int ciphertext, ciphercode,plaincode;
    while(cin>>s,s!=0){
        cin>>c;
        int n = c.size();
        plaintext.resize(n);
        for(unsigned int i=0;i<n;i++){
            ciphertext = c[i];
            ciphercode = bbbb[ciphertext];
            plaincode = a[(ciphercode+i)%28];
            plaintext[s*i % n] = plaincode;
        }
        cout<<plaintext<<endl;
    }
    return 0;
}
