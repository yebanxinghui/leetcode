class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> v;
        unordered_map<int, string> m = {{5,"Buzz"},{3,"Fizz"}};
        for(int i=1;i<=n;i++)
        {
            string s = "";
            for(auto mm:m)
            {
                if(i % mm.first == 0)
                    s += mm.second;
            }
            if(s.empty()) s+=to_string(i);
            v.push_back(s);
        }
        return v;
    }
};