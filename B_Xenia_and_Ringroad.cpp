#include<bits/stdc++.h>
using namespace std;

int main() {   
    int n, m;
    cin >> n >> m;

    vector<int> positions(m);
    for(int i = 0; i < m; i++) {
        cin >> positions[i];
    }

    long long totalDistance = positions[0] - 1;
    for(int i = 0; i < m - 1; i++) {
        if(positions[i+1] >= positions[i]) {
            totalDistance += positions[i+1] - positions[i];
        } else {
            totalDistance += n - abs(positions[i+1] - positions[i]);
        }
    }

    cout << totalDistance << endl;
    return 0;
}
