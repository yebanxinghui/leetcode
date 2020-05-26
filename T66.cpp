class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num = 0;
        digits.back()+=1;
        for(int i = digits.size()-1;i>=0;i--)
        {
            digits[i] += num;
            if(digits[i] >= 10)
            {
                digits[i]=0;
                num=1;
            }
            else num=0;
        }
        if(num==1) digits.insert(digits.begin(), 1);
        return digits;
    }
};