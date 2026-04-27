#include<vector>
#include<array>
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable;
        vector<vector<string>> ans;

        for (const string& s : strs) {
            unordered_map<char, int> dict_hashmap;
            string key = s;
            for(int i = 0; i < key.size(); ++i) {
                dict_hashmap[key[i]-'a'] += 1;
            }

            string keyStr;
            for (int i = 0; i < 26; ++i) {
                keyStr += to_string(dict_hashmap[i]) + "#";
            }
            
            hashtable[keyStr].push_back(s);
        }

        for (auto it = hashtable.begin(); it != hashtable.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
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