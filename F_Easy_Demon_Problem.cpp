#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    int a[n], b[n];
    long long totbeauty = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    unordered_map<int, long long> rsum;
    unordered_map<int, long long> csum;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int prod = a[i] * b[j];
            totbeauty += prod;
            rsum[i] += prod;
            csum[j] += prod;
        }
    }

    // for(int i=0; i<n; i++){
    //     cout<<rsum[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<m; i++){
    //     cout<<csum[i]<<" ";
    // }
    // cout<<endl;
    // cout<<totbeauty<<endl;

 while (q--) {
        long long x;
        cin >> x;

        bool found = false;

        for (int r = 0; r < n; ++r) {
            if(!found){
                for (int c = 0; c < m; ++c) {
                    if(!found){
                    long long cal = totbeauty - rsum[r] - csum[c] + a[r] * b[c];
                        if (cal == x) {
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}
