class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int counter[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }
        for(auto count : counter) {
            if(count != 0) {
                return false;
            }
        }
        return true;
    }
};