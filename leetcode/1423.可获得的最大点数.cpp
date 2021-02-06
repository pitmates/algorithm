/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        vector<int> pre(n+1, 0), suf(n+1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i+1] = pre[i] + card[i];
            suf[i+1] = suf[i] + card[n-i-1];
        }
        int mx = suf[k];
        for (int i = 1; i <= k; ++i) {
            int now = pre[i] + suf[k-i];
            mx = max(mx, now);
        }
        return mx;
    }
};
// @lc code=end

