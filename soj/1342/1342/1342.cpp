
 #include <iostream>
 #include <string>
 #include <cstring>
 #include <cmath>
 
 using namespace std;
 
 int main() {
     int n,m;
     while(cin >> m >> n){
     
     long long w[25],v[25],f[30001];
     
     for (int i=1;i<=n;i++) {
         cin >> w[i] >> v[i];
         v[i] = w[i] * v[i];
     }
     for(int i=1;i<=m;i++)
	 {
		f[i] =0;
	 }
     for (int i=1;i<=n;i++) {
         for (int j=m;j>=w[i];j--) {
             f[j] = max(f[j],f[j-w[i]]+v[i]);
         }
     }
     cout << f[m] << endl;
	 }
     return 0;
 }