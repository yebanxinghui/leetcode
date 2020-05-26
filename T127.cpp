class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //双向bfs
        unordered_set<string> dict(wordList.begin(),wordList.end());
        if(dict.find(endWord) == dict.end() ) return 0;
        unordered_set<string> beginset{beginWord},endset{endWord},tmp,visited;
        int len = 1;
        while(!beginset.empty() && !endset.empty())
        {
            if(beginset.size() > endset.size())
                swap(beginset,endset);
            for(auto s : beginset)
            {
                for(int i = 0; i < s.size(); i++)
                {
                    char oddch = s[i];
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if(ch == oddch) continue;
                        s[i] = ch;
                        if(endset.find(s)!=endset.end()) return len+1;
                        if(visited.find(s)==visited.end() && dict.find(s)!=dict.end())
                        {
                            tmp.insert(s);
                            visited.insert(s);
                        }
                    }
                    s[i] = oddch;
                }
            }
            len++;
            beginset = tmp;
            tmp.clear();
        }
        return 0;
    }
};