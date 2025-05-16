class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto incr = [](int passes, int totstu) {
            return (double)(passes + 1) / (totstu + 1) -
                   (double)passes / totstu;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for (const auto& it : classes) {
            maxHeap.push({incr(it[0], it[1]),
                          {it[0], it[1]}});
        }

        while (extraStudents--) {
            auto [currentGain, classInfo] = maxHeap.top();
            maxHeap.pop();
            int passes = classInfo.first;
            int totstu = classInfo.second;
            maxHeap.push({incr(passes + 1, totstu + 1),
                          {passes + 1, totstu + 1}});
        }

        double totalPassRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, classInfo] = maxHeap.top();
            maxHeap.pop();
            totalPassRatio += (double)classInfo.first / classInfo.second;
        }

        return totalPassRatio / classes.size();
    }
};