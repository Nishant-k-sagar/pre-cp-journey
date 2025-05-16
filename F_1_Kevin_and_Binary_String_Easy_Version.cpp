#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Structure to represent a block
struct Block {
    char value;
    int start;
    int length;
    Block(char v, int s, int l) : value(v), start(s), length(l) {}
};

class BlockSwapSolver {
private:
    // Get blocks from a string
    vector<Block> getBlocks(const string& s) {
        vector<Block> blocks;
        char currVal = s[0];
        int currStart = 0;
        int currLen = 1;
        
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == currVal) {
                currLen++;
            } else {
                blocks.emplace_back(currVal, currStart, currLen);
                currVal = s[i];
                currStart = i;
                currLen = 1;
            }
        }
        blocks.emplace_back(currVal, currStart, currLen);
        return blocks;
    }

    // Check if source blocks can transform into target blocks
    int canTransform(vector<Block>& sBlocks, const vector<Block>& tBlocks) {
        // Must have same number of blocks
        if(sBlocks.size() != tBlocks.size())
            return -1;

        // Count total zeros and ones
        int sZeros = 0, sOnes = 0, tZeros = 0, tOnes = 0;
        for(const auto& block : sBlocks) {
            if(block.value == '0') sZeros += block.length;
            else sOnes += block.length;
        }
        for(const auto& block : tBlocks) {
            if(block.value == '0') tZeros += block.length;
            else tOnes += block.length;
        }

        // Must have same count of zeros and ones
        if(sZeros != tZeros || sOnes != tOnes)
            return -1;

        // Check if blocks have same lengths in some order
        vector<int> sLengths, tLengths;
        for(const auto& block : sBlocks) sLengths.push_back(block.length);
        for(const auto& block : tBlocks) tLengths.push_back(block.length);
        sort(sLengths.begin(), sLengths.end());
        sort(tLengths.begin(), tLengths.end());
        if(sLengths != tLengths)
            return -1;

        // Count minimum swaps needed
        int swaps = 0;
        int n = sBlocks.size();

        // For each position, find correct block and swap it into place
        for(int i = 0; i < n-1; i++) {
            if(sBlocks[i].value != tBlocks[i].value || 
               sBlocks[i].length != tBlocks[i].length) {
                // Find matching block
                bool found = false;
                for(int j = i+1; j < n; j++) {
                    if(sBlocks[j].value == tBlocks[i].value && 
                       sBlocks[j].length == tBlocks[i].length) {
                        // Swap block j into position i
                        while(j > i) {
                            swap(sBlocks[j-1], sBlocks[j]);
                            swaps++;
                            j--;
                        }
                        found = true;
                        break;
                    }
                }
                if(!found) return -1;
            }
        }
        return swaps;
    }

public:
    int solve(const string& s, const string& t) {
        auto sBlocks = getBlocks(s);
        auto tBlocks = getBlocks(t);
        return canTransform(sBlocks, tBlocks);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    BlockSwapSolver solver;
    while(t--) {
        string s, t;
        cin >> s >> t;
        cout << solver.solve(s, t) << '\n';
    }
    
    return 0;
}