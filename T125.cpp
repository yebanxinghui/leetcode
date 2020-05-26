class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for(auto ch:s)
        {
            if(islower(ch) || isdigit(ch)) tmp+=ch;
            else if(isupper(ch)) tmp+=tolower(ch);
        }
        int i=0,j = tmp.size()-1;
        while(i<j)
        {
            if(tmp[i] != tmp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};