#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf(){
    //try it harder

    ll n;
    cin>>n;

    string str;
    cin>>str;

    ll cnt = 0;
    for(ll i=n-2; i>=0; i--){
        if(str[i] != str[i+1])cnt++;
    }

    if(str[0] == '1')cnt++;

    cout<<cnt<<endl;
}

int main(){
    fast
  ll t;
  cin>>t;
  while(t--){
    nottryingenouf();
  }
}