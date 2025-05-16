#include <bits/stdc++.h>
using namespace std;

int maxStates(int A[], int N, int M) {
    int count = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (sum < M) {
            continue;
        }
        count++;
        sum = 0;
    }
    if (sum >= M) {
        count++;
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--){
    int N, M;
    cin >> N >> M;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << maxStates(A, N, M) << endl;}
    return 0;
}