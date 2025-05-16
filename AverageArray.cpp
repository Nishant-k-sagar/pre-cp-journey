#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n, x;
    cin>>n>>x;

    if(n&1){
        cout<<x<<" ";

        for(int i=1; i<=(n/2); i++){
            cout<<x-i<<" "<<x+i<<" ";
        }
        cout<<endl;
    }
    else{
        for(int i=1; i<=(n/2); i++){
            cout<<x-i<<" "<<x+i<<" ";
        }
        cout<<endl;
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