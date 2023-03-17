class MagicDictionary {
public:
    unordered_map<string,int>mp;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto i : dictionary)
            mp[i] = 1;
    }
    
    bool search(string searchWord) {
        for(auto i : mp)
        {
            string k = i.first;
            if(k.size() == searchWord.size())
            {
                int cnt = 0;
                for(int j = 0;j<k.size();j++)
                {
                    if(k[j] == searchWord[j])
                        cnt++;
                }
                if(cnt == k.size() - 1)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */