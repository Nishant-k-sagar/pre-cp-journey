#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> sticks(n);
        map<int, int> counter;

        for (int i = 0; i < n; ++i) {
            cin >> sticks[i];
            counter[sticks[i]]++;
        }

        vector<int> possible_lengths;
        for (auto it = counter.begin(); it != counter.end(); ++it) {
            if (it->second >= 2) {
                possible_lengths.push_back(it->first);
            }
        }

        sort(possible_lengths.rbegin(), possible_lengths.rend());

        bool found = false;
        for (size_t i = 0; i < possible_lengths.size() - 1; ++i) {
            int base1 = possible_lengths[i];
            int base2 = possible_lengths[i + 1];

            if (counter[base1] >= 4) { // Case where we can use four identical lengths
                cout << base1 << " " << base1 << " " << base1 << " " << base1 << "\n";
                found = true;
                break;
            }

            if (counter[base1] >= 2 && counter[base2] >= 2) { // Case where two pairs of lengths form the trapezoid
                cout << base1 << " " << base1 << " " << base2 << " " << base2 << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
