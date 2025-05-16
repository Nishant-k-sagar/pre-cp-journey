#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    cin>>n;

    string stra, strb;

    cin>>stra>>strb;

    if (stra.find('1') == string::npos) {
        cout << "YES"<<endl;
        return;
    }

    bool flag = true;
    for(int i=0; i<n; i++){
        if(i-1>=0){
            if((stra[i]!=strb[i-1]) || (strb[i] != stra[i-1])){
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}