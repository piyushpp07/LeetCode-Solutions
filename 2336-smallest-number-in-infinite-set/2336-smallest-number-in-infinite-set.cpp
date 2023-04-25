class SmallestInfiniteSet {
public:
    multiset<int>ms;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int cnt = 1;
        while(ms.find(cnt)!=ms.end())
        {
            cnt++;
        }
        ms.insert(cnt);
        return cnt;
    }
    
    void addBack(int num) {
        ms.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */