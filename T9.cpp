class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string p = s;
        reverse(s.begin(), s.end());
        if(s==p) return true;
        else return false;
    }
};