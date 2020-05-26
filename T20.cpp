class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(auto i : s)
        {
            if(i=='('||i=='['||i=='{') v.push_back(i);
            else if(i==']')
            {
                if(v.empty()||v.back()!='[') return false;
                else v.pop_back();
            }
            else if(i==')')
            {
                if(v.empty()||v.back()!='(') return false;
                else v.pop_back();
            }
            else if(i=='}')
            {
                if(v.empty()||v.back()!='{') return false;
                else v.pop_back();
            }
        }
        if(v.empty()) return true;
        else return false;
    }
};