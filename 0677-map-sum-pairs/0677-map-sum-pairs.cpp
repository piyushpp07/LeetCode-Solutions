class TrieNode{
    public:
    bool isCompleted;
    TrieNode *character[26];
    int curr;
    TrieNode()
    {   curr = 0;
        isCompleted = false;
        memset(character,0,sizeof character);
    }
};
class MapSum {
public:
    TrieNode *root;
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *node = root;
        for(auto ch : key)
        {
            int idx = ch - 'a';
            if(node->character[idx] == NULL)
                node->character[idx] = new TrieNode();
            
            node = node->character[idx];
            
        }
        node->curr = val;
        node->isCompleted = true;
    }
    void helper(TrieNode *node,int &ans)
    {
        if(node->isCompleted)
            ans += node->curr;
        for(int i =0 ;i<26;i++)
        {
            if(node->character[i] != NULL)
                helper(node->character[i],ans);
        }
    }
    int sum(string prefix) {
        int ans = 0;
        TrieNode *node = root;
        for(int i = 0;i<prefix.size();i++)
        {
            int idx = prefix[i] - 'a';
            if(node->character[idx] == NULL)
                return 0;
            node = node->character[idx];
        }
        helper(node,ans);
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */