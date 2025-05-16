#include<bits/stdc++.h>
using namespace std;
#define ll long long

void nottryingenouf(){
    //try it harder
    string w;
    cin >> w;
    string news = w.substr(0, w.size() - 2);
    cout << news + 'i' << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        nottryingenouf();
    }
}
