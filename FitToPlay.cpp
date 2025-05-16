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

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int mini = v[0], maxi = 0, diff = 0;

    for(int i=0; i<n; i++){
        if(mini < v[i]){
            diff = max(diff, v[i] - mini);
        }
        else {
            mini = v[i];
        }
    }

    if(diff == 0){
        cout<<"UNFIT"<<endl;
    }
    else cout<<diff<<endl;

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