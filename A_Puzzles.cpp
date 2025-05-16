#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);

    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    

    // v.resize(n);
    // int a= *min_element(v.begin(), v.end());
    // int b= *max_element(v.begin(), v.end());
    // cout <<a-b << endl; 
    return 0;
}
