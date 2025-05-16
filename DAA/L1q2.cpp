#include <iostream>

using namespace std;

int countZeros(int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == 1) {
            left = mid + 1;  
        } else if (arr[mid] == 0) {
            if (mid == 0 || arr[mid - 1] == 1) {
                return size - mid;  
            } else {
                right = mid - 1;  
            }
        }
    }

    return 0;  
}

int main() {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int count = countZeros(arr, size);

    cout << "Count of 0s: " << count << endl;

    return 0;
}