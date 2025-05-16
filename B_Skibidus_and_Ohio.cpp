#include<bits/stdc++.h>
using namespace std;
#define ll long long

void nottryingenouf(){

    //try harder
    string s;
    cin >> s;
    int n = s.length();
    
    int i=0;
    while(i<n-1){
        if (s[i] == s[i + 1]) {
            cout << 1 << endl;
            return;
        }
        i++;
    }
    
    cout << n << endl;
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    nottryingenouf();
  }
}
