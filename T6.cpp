class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows,"");
        int len = s.length();
        int num = 0, direct = 1;//1表示向下，-1表示向上
        for(int i=0;i<len;i++)
        {
            v[num] += s[i];
            if(num == numRows-1 && direct == 1)
                direct = -1;
            if(num == 0 && direct == -1)
                direct = 1;
            num += direct;
        }
        string p = "";
        for(int i=0;i<numRows;i++)
            p += v[i];
        return p;
    }
};