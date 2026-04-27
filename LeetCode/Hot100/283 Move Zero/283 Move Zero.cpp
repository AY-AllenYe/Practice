#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> new_set;
        for (int num : nums) {
            new_set.insert(num);
        }
        int longest = 0;
        for (int num : new_set) {
            if (!new_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (new_set.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
        

int main() {
    Solution solution;
    vector<string> strs;
    
    int n;
    vector<int> num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        num.push_back(value);
    }

    auto result = solution.longestConsecutive(num);
    
    // 输出结果
    cout << result;
    
    return 0;
}