class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
           vector<int> result;
    for (int q : queries) {
        int minLen = INT_MAX;
        for (auto& interval : intervals) {
            int l = interval[0], r = interval[1];
            if (q >= l && q <= r) {
                minLen = min(minLen, r - l + 1);
            }
        }
        result.push_back(minLen == INT_MAX ? -1 : minLen);
    }
    return result;
    }
};
