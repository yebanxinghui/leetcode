class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        else if(strs.size() == 1) return strs[0];
        int len = strs[0].length();
        int vlen = strs.size();
        int count=0;
        for(int i=0;i<len;i++)
        {
            for(int j=1;j<vlen;j++)
            {
                if(i>strs[j].length() || strs[j][i] != strs[0][i]) 
                    return strs[0].substr(0,count);
            }
            count++;
        }
        return strs[0].substr(0,count);
    }
};