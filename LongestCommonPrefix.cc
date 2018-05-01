class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        std::string ret;
        
        for(int i=0; i<strs[0].size(); i++) {
            char &ch = strs[0][i];
            for(int j=1; j<strs.size(); j++) {
                if(strs[j].size() < i + 1 ||
                  strs[j][i] != ch) {
                    return ret;
                }
            }
            ret.push_back(ch);
        }
        return ret;
    }
};

