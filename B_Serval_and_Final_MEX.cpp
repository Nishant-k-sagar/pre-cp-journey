#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to calculate the MEX (Minimum Excluded) value of a vector
int mex(const vector<int>& arr, int l, int r) {
    set<int> present;
    for (int i = l; i <= r; i++) {
        present.insert(arr[i]);
    }
    
    int mex_val = 0;
    while (present.count(mex_val)) {
        mex_val++;
    }
    return mex_val;
}

// Function to apply the operation (replace subarray with its MEX)
void apply_operation(vector<int>& arr, int l, int r) {
    int mex_val = mex(arr, l, r);
    arr.erase(arr.begin() + l + 1, arr.begin() + r + 1);
    arr[l] = mex_val;
}

// Function to solve one test case
void solve_test_case() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Store the operations (l, r pairs)
    vector<pair<int, int>> operations;
    
    // Keep applying operations until array size becomes 1
    while (arr.size() > 1) {
        int best_l = 0;
        int best_r = 1;
        bool found_zero_mex = false;
        
        // If array size is 2, we have only one choice
        if (arr.size() == 2) {
            operations.push_back({1, 2});
            apply_operation(arr, 0, 1);
            continue;
        }
        
        // Try all possible subarrays
        for (int l = 0; l < arr.size() - 1; l++) {
            for (int r = l + 1; r < arr.size(); r++) {
                // Calculate MEX of the current subarray
                int mex_val = mex(arr, l, r);
                
                // If MEX is 0 and we'll immediately get our answer, use it
                if (mex_val == 0 && l == 0 && r == arr.size() - 1) {
                    best_l = l;
                    best_r = r;
                    found_zero_mex = true;
                    break;
                }
                
                // If MEX is 0, consider it as a good candidate
                if (mex_val == 0 && !found_zero_mex) {
                    best_l = l;
                    best_r = r;
                    found_zero_mex = true;
                }
            }
            if (found_zero_mex && best_l == 0 && best_r == arr.size() - 1) {
                break;
            }
        }
        
        // If we didn't find a subarray with MEX 0, we just try to reduce the array
        // with any operation (starting from the beginning for simplicity)
        if (!found_zero_mex) {
            for (int r = 1; r < arr.size(); r++) {
                int mex_val = mex(arr, 0, r);
                // Pick the first operation that produces a small value (ideally 1 or 2)
                if (mex_val <= 2) {
                    best_l = 0;
                    best_r = r;
                    break;
                }
                // If we didn't find a good one, just take the last option
                best_l = 0;
                best_r = 1;
            }
        }
        
        // Record and apply the operation
        operations.push_back({best_l + 1, best_r + 1}); // +1 because problem uses 1-indexed
        apply_operation(arr, best_l, best_r);
    }
    
    // Output the result
    cout << operations.size() << endl;
    for (const auto& op : operations) {
        cout << op.first << " " << op.second << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve_test_case();
    }
    
    return 0;
}