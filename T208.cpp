class Trie {
public:
    bool exist;         //结点值是否存在
    Trie* child[26];    //指向孩子结点
    /** Initialize your data structure here. */
    Trie() {
        exist = false;
        memset(child,0,sizeof(child));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        if(!word.empty()) exist = true;
        for(auto i:word)
        {
            if(node->child[i-'a'] == nullptr)
            {
                node->child[i-'a'] = new Trie();
                
            }
            node = node->child[i-'a'];
        }
        node->exist = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for(auto i : word)
        {
            node = node->child[i-'a'];
            if(node == nullptr)
                return false;
        }
        return node->exist;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for(auto i : prefix)
        {
            node = node->child[i-'a'];
            if(node == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */