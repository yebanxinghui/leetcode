class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int x){
            return x == 0;
        } )){
            return string("0");
        }
        vector<string> s(nums.size(),"");
        transform(nums.begin(),nums.end(),s.begin(),[](int x){
            return to_string(x);
        });
        sort(s.begin(),s.end(),[](const string &s1,const string& s2){
            return s1+s2>s2+s1;
        });
        return accumulate(s.begin(), s.end(), string(""));
    }
};