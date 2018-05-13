class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0) return 0;
        int ret = 0;
        for(int i=s.size() - 1; i>=0; i--) {
            char cur = s[i];
            ret += map(cur);
            if(i == 0) break;
            
            char prev = s[i-1];
            if((prev == 'I' && (cur == 'V' || cur == 'X')) ||
               (prev == 'X' && (cur == 'L' || cur == 'C')) ||
               (prev == 'C' && (cur == 'D' || cur == 'M'))) {
                i--;
                ret -= map(prev);
            }
        }
        return ret;
    }
    
    int map(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: assert(false);
        }
        return -1;
    }
};

