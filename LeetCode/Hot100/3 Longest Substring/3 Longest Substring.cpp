#include<vector>
#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_set<char> hashset;
        int index_start = 0;
        int index_end = index_start;
        while(index_end < s.length()){
            if(!hashset.count(s[index_end])){
                hashset.insert(s[index_end]);
                index_end++;
                ans = max(ans, index_end - index_start);
            }else{
                hashset.erase(s[index_start]);
                index_start++;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string strs;

    cin >> strs;

    auto result = solution.lengthOfLongestSubstring(strs);
    
    // 输出结果
    cout << result;
    
    return 0;
}