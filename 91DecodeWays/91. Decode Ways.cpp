//对应的解码位数是1或者2，要求返回的是能够有多少种解码方式
//跟爬楼梯的题目相比增加了走两层楼梯的限制条件
//
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s.size()>1 && s[0] == '0')
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 1; i < dp.size(); i++){
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if(i > 1 && s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6')
                dp[i] += dp[i-2];
        }
        return dp.back();
    }
};