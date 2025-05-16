#include <iostream>
#include <string>
#include <vector>

int main() {
    int T;
    std::cin >> T;
    
    while (T--) {
        int N;
        std::cin >> N;
        
        // Read the binary strings
        std::string A, B;
        std::cin >> A >> B;
        
        // Store operations as (type, L, R) with type = 1 (flip)
        std::vector<std::vector<int>> ops;
        
        int i = 0;
        while (i < N) {
            if (A[i] == B[i]) {
                i++;
                continue;
            }
            
            // Found a mismatch, start a contiguous block
            int start = i;
            while (i < N && A[i] != B[i]) {
                i++;
            }
            int end = i - 1;
            
            // Record operation: flip the block from start+1 to end+1 (1-indexing)
            ops.push_back({1, start + 1, end + 1});
        }
        
        // Output the number of operations and then each operation
        std::cout << ops.size() << std::endl;
        for (const auto& op : ops) {
            std::cout << op[0] << " " << op[1] << " " << op[2] << std::endl;
        }
    }
    
    return 0;
}