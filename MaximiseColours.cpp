#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int a, b, c;
    
    int n = 3;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int cnt = 0;
    if(v[0]>0){
        cnt++;
        v[0]--;
    }
    if(v[1]>0){
        cnt++;
        v[1]--;
    }
    if(v[2]>0){
        cnt++;
        v[2]--;
    }

    if(v[0]>0 && v[1])
    {
        cnt++;
        v[0]--;
        v[1]--;
    }
    if(v[0]>0 && v[2]>0){
        cnt++;
        v[0]--;
        v[2]--;
    }
    if(v[1]>0 && v[2]>0){
        cnt++;
    }
    cout<<cnt<<endl;
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