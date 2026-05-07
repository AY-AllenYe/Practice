#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string strs;
    string strs_sub;
    
    cin >> strs;
    cin >> strs_sub;

    auto result = solution.findAnagrams(strs, strs_sub);
    
    // 输出结果
    cout << "[";
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
        if(i != result.size() - 1){
            cout << ",";
        }
    }
    cout << "]";
    
    return 0;
}