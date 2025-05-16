#include <iostream>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int size = 2 * N;
        deque<int> dq(size);
        for (int i = 0; i < size; ++i) {
            cin >> dq[i];
        }

        // max-heap to pick the best possible values for Alice
        priority_queue<int> pq;
        long long aliceScore = 0;

        for (int i = 0; i < N; ++i) {
            // Add all current elements to pq (only needed once)
            // Actually we simulate by just popping from back and pushing to pq
            while (!dq.empty()) {
                pq.push(dq.back());
                dq.pop_back(); // simulate Alice's view (from back)
            }

            // Alice picks the best
            aliceScore += pq.top();
            pq.pop();

            // Bob removes from front of original deque
            dq.pop_front();
        }

        cout << aliceScore << "\n";
    }

    return 0;
}
