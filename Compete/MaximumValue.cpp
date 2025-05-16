#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int t;
    cin >> t;
    while (t--){
        long long int n, b, c, d, e;
        cin >> n;
        long long int a[n];
        for (int i= 0; i<n; ++i){
            cin >> a[i];
        }
        sort(a, a+n);

         e= a[0];
         b = a[1];
          c= a[n-1];
         d = a[n-2];

         long long int ansfirst= e*b + b-e;
         long long int anssec= c*d +c-d;

         ;
         cout  << max(ansfirst, anssec)<<endl;
        
    }
   return 0;
}