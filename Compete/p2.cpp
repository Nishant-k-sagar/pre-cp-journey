#include <iostream>
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        char arr[6];
        for (int i = 0; i < 6; i++) {
            cin >> arr[i];
        }

        bool found = false;
        for (int i = 0; i < 4; i++) {
            if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] && arr[i]=='W') {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
