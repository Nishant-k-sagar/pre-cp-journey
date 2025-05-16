#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> codewithlove(ll n, ll d) {
    vector<int> ans;
    ans.push_back(1);

    if(d==5)ans.push_back(5);

    if(n>=3 || d%3==0){
        ans.push_back(3);
    }
    if(n>=3 || (n==2 && d==7)){
        ans.push_back(7);
    }
    if(n>=6){
        ans.push_back(9);
    }
    else{
        ll fact=1;
        for(int i=2; i<=n; i++){
            fact*=i;
        }

        if((fact*d)%9==0){
            ans.push_back(9);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, d;
        cin >> n >> d;
        vector<int> div = codewithlove(n, d);

        sort(div.begin(), div.end());
        for (int it : div) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
