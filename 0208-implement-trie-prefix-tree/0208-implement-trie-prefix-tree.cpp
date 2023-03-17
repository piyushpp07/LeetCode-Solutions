class Trie {
public:
    unordered_map<string,int>mp;
    Trie() {
        
    }
    
    void insert(string word) {
        mp[word] = 1;
    }
    
    bool search(string word) {
        if(mp.find(word)!=mp.end())
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {

        for(auto j : mp)
        {
            if(j.first.size() >= prefix.size())
            {
               string s = j.first.substr(0,prefix.size());
               
               if(s == prefix)
                   return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */