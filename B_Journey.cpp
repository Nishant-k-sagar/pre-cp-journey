#include <bits/stdc++.h>
using namespace std;

void codewithlove() {
   long long n, a, b, c;
   cin>>n>>a>>b>>c;

   long long sum = a+b+c;
   long long fcycle=n/sum;
    long long totwalk = fcycle*sum;
    int days = fcycle*3;

    if(totwalk>=n){
        cout<<days<<endl;
        return;
    }
    else if(totwalk+a>=n){
        cout<<days+1<<endl;
        }
        else if(totwalk+a+b>=n){
            cout<<days+2<<endl;
            }
            else if(totwalk+a+b+c>=n){
                cout<<days+3<<endl;
                
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        codewithlove();
    }

    return 0;
}