class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int leng = s.length();
        string p = "";
        for(int i=0; i<leng; i++)
        {
            p+=s[i];
            int chang=p.length();
            if(chang == 1){
                len = 1;
                continue;
            }
            for(int j=0; j<chang-1; j++)
            {
                if(s[i]==p[j])
                {
                    if(len<chang)len = chang-1;
                    p=p.substr(j+1);
                    //p.erase(p.begin(),p.begin()+j+1);
                    break;
                }
            }
        }
        if(p.length()>len) len = p.length();
        return len;
    }
};