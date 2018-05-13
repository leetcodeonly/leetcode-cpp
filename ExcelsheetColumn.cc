class Solution {
public:
    int titleToNumber(string s) {
        assert(s.size() >= 0);
        int ret = 0;
        int base = 1;
        for(int i=s.size()-1; i>=0; i--) {
            ret += base * (s[i] - 'A' + 1);
            base *= 26;
        }
        return ret;
    }
};

