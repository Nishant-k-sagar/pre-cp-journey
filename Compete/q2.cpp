#include <iostream>
#include <vector>
using namespace std;

int maxScore(vector<int>& A) {
    int score = 0;
    for (int i = 0; i < A.size(); i += 2) {
        score += abs(A[i] - A[i + 1]);
    }
    return score;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cout << maxScore(A) << endl;
    }
    return 0;
}
