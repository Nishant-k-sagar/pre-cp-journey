#include<bits/stdc++.h>
using namespace std;

void read_data(map<string, int> &mp, int n) {
    for (int i = 0; i < n; ++i) {
        string s;
        int ct;
        cin >> s >> ct;
        mp[s] += ct;
    }
}

vector<int> sort_counts(map<string, int> &mp) {
    vector<int> v;
    for (auto &i : mp) {
        v.push_back(i.second);
    }
    sort(v.begin(), v.end());
    return v;
}

void print_sorted_counts(const vector<int> &v) {
    for (auto &i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> mp;

        for (int i = 0; i < 3; ++i) {
            read_data(mp, n);
        }

        vector<int> sorted_counts = sort_counts(mp);
        print_sorted_counts(sorted_counts);
    }
    return 0;
}