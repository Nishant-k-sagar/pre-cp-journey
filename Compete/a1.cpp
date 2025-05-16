#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> p;

        for (int i = 0; i < n; ++i) {
            int a, x;
            cin >> a >> x;
            p.push_back({a, x});
        }

        int lower_bound = -1e9, upper_bound = 1e9;

        for (int i = 0; i < n; ++i) {
            if (p[i].first == 1) {
                lower_bound = max(lower_bound, p[i].second);
            } else if (p[i].first == 2) {
                upper_bound = min(upper_bound, p[i].second);
            }
        }

        int count = upper_bound - lower_bound +1;

        for (int i = 0; i < n; ++i) {
            if (p[i].first == 3){
                cout<<count<<"  ";
                if((p[i].second >= lower_bound || p[i].second <= upper_bound)) {
                count--;
                break;
            }
        }}

        cout << max(0, count) << endl;
    }

    return 0;
}
