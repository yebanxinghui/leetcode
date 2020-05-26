class Solution {
public:
    int stoi(string str) {
        int i=0;
        int sum=0;
        while(str[i]>='0' && str[i]<='9')
        {
            int temp = str[i]-'0';
            sum = sum*10 + temp;
            i++;
        }
        return sum;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<int> v;
        if(s.size()>12) return ans;
        dfs(ans,s,1,v);
        return ans;
    }
    bool ip(string s,vector<int> v)
    {
        string tmp = s.substr(0,v[0]);
        if(tmp.size() != 1 && tmp[0] == '0') return false;
        if(tmp.size() == 0 || tmp.size()>3 || stoi(tmp)>255) return false;
        
        tmp = s.substr(v[0],v[1]-v[0]);
        if(tmp.size() != 1 && tmp[0] == '0') return false;
        if(tmp.size() == 0 || tmp.size()>3 || stoi(tmp)>255) return false;
        tmp = s.substr(v[1],v[2]-v[1]);
        if(tmp.size() != 1 && tmp[0] == '0') return false;
        if(tmp.size() == 0 || tmp.size()>3 || stoi(tmp)>255) return false;
        tmp = s.substr(v[2]);
        if(tmp.size() != 1 && tmp[0] == '0') return false;
        if(tmp.size() == 0 || tmp.size()>3 || stoi(tmp)>255) return false;
        return true;
    }
    string app(string s,vector<int> v)
    {
        string str("");
        str+=s.substr(0,v[0]);
        str+=".";
        str+=s.substr(v[0],v[1]-v[0]);
        str+=".";
        str+=s.substr(v[1],v[2]-v[1]);
        str+=".";
        str+=s.substr(v[2]);
        return str;
    }
    void dfs(vector<string> &ans, string s, int low, vector<int> &v)
    {
        if(v.size() == 3)
        {
            if(!ip(s,v)) return ;
            ans.push_back(app(s,v));
        }
        for(int i = low; i < s.size(); i++)
        {
            v.push_back(i);
            dfs(ans,s,i+1,v);
            v.pop_back();
        }
    }
};