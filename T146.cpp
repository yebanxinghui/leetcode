class LRUCache {
private:
    int cap;
    list<pair<int,int> > cache;//双链表
    unordered_map<int,list<pair<int,int>>::iterator > m;//哈希表
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it==m.end()) return -1;
        pair<int,int> tmp = *m[key];
        cache.erase(m[key]);
        cache.push_front(tmp);
        m[key] = cache.begin();
        return tmp.second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it==m.end()){
            if(cache.size()==cap)
            {
                auto last = cache.back();
                int key = last.first;
                m.erase(key);
                cache.pop_back();
            }
            cache.push_front(make_pair(key,value));
            m[key] = cache.begin();    
        }
        else{
            cache.erase(m[key]);
            cache.push_front(make_pair(key,value));
            m[key] = cache.begin();  
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */