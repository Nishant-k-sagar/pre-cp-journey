#include<bits/stdc++.h>
using namespace std;

int main(){
   int n,m;
   cin>>n;
   int a[n], c[n];
   
   for(int i=0; i<n; i++){
    cin>>a[i];
    c[i] = a[i];
   }

    reverse(c,c+n);

   cin>>m;
   int b[m];
   for(int i=0; i<m; i++){
    cin>>b[i];
   }
   
   int v = 0;
   int p = 0;

    while(m--){
        for(int i=0; i<n; i++){
            if(b[m]==a[i])
            {
                v += i+1;
            }
            if(b[m]==c[i])
            {
                p += i+1;
            }
        }
        
    }
    cout<<v<<" "<<p<<endl;

    return 0;
}