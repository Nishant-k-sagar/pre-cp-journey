#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Assistant {
    int t, z, y;
};

int m, n;

bool canInflateInTime(const vector<Assistant>& assistants, int T, vector<int>& balloonsPerAssistant) {
    int total = 0;
    balloonsPerAssistant.assign(n, 0);
    
    for (int i = 0; i < n; ++i) {
        int cycleTime = assistants[i].t * assistants[i].z + assistants[i].y;
        int fullCycles = T / cycleTime;
        int remainingTime = T % cycleTime;
        int extraBalloons = min(assistants[i].z, remainingTime / assistants[i].t);

        int totalBalloons = fullCycles * assistants[i].z + extraBalloons;
        balloonsPerAssistant[i] = totalBalloons;
        total += totalBalloons;
    }
    return total >= m;
}

int main() {
    cin >> m >> n;
    vector<Assistant> assistants(n);
    for (int i = 0; i < n; ++i) {
        cin >> assistants[i].t >> assistants[i].z >> assistants[i].y;
    }

    int low = 0, high = 1e9, answerTime = -1;
    vector<int> balloons(n), finalBalloons(n);

    while (low < high) {
        int mid = (low + high) / 2;
        if (canInflateInTime(assistants, mid, balloons)) {
            answerTime = mid;
            finalBalloons = balloons;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Adjust balloon counts to make sure total is exactly m
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += finalBalloons[i];
    }
    int extra = total - m;
    for (int i = 0; i < n && extra > 0; ++i) {
        int reduce = min(extra, finalBalloons[i]);
        finalBalloons[i] -= reduce;
        extra -= reduce;
    }

    cout << answerTime << "\n";
    for (int i = 0; i < n; ++i) {
        cout << finalBalloons[i] << " ";
    }
    cout << "\n";

    return 0;
}
