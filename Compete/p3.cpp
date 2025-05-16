#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, X;
        cin >> N >> X;

        string S;
        cin >> S;

        int pass=X;

        for (int i = 0; i < N; ++i) {
            if (S[i] == '0') {
                pass--;
            } else {
                pass;
            }
        }

        if (pass>0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
