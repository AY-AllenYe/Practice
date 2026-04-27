#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            hashmap[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : hashmap) {
            result.push_back(pair.second);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs;
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    auto result = solution.groupAnagrams(strs);
    
    // 输出结果
    for (const auto& group : result) {
        cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << group[i];
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "],";
    }
    
    return 0;
}