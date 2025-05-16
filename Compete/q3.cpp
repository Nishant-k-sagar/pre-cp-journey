#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Integer to make zero

        // Check if it's possible to make n zero using 3 or 4
        if (n % 3 == 0 || n % 4 == 0) {
            cout << "YES" << endl;
        } else {
            // Check for combinations of 3 and 4
            bool possible = false;
            for (int i = 0; i <= n / 3; i++) {
                if ((n - i * 3) % 4 == 0) {
                    possible = true;
                    break;
                }
            }
            cout << (possible ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
