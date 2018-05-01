class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minv = prices[0];
        int ret = 0;
        for(int i=1; i<prices.size(); i++) {
            minv = std::min<int>(minv, prices[i]);
            ret = std::max<int>(ret, prices[i] - minv);
        }
        return ret;
    }
};

