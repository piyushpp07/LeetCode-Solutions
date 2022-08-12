class LRUCache
{
    private:
        int cap = 0;
    int size = 0;
    list<int> l;
    map<int, int> mp;
    map<int, list<int>::iterator > address;
    public:
        LRUCache(int capacity)
        {
            cap = capacity;
        }

    int get(int key)
    {
        if (mp.find(key) == mp.end()) return -1;
        auto it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return mp[key];
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            size--;
        }
        if (size == cap)
        {
            int key = l.back();
            l.pop_back();
            mp.erase(key);
            address.erase(key);
            size--;
        }
        size++;
        l.push_front(key);
        address[key] = l.begin();
        mp[key] = value;
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */