class TrieNode{
  public:
    TrieNode *child[26];
    bool isLeaf;
    TrieNode()
    {
        memset(child,0,sizeof child);
        isLeaf = false;
    }
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
         root = new TrieNode();
    }
    
    void addWord(string word) {
       TrieNode * node = root;
       for(auto i : word)
       {
         int idx = i - 'a';
         if(node->child[idx] == NULL)
         {
             node->child[idx] = new TrieNode();
         }
         node =  node->child[idx];
       }
        node->isLeaf = true;
    }
    bool dfs(TrieNode *node,string word)
    {    
        for(int i = 0;i<word.size();i++)
        {   char ch = word[i];
            if(ch == '.')
            {
                for(auto c : node->child)
                {
                    if(c  && dfs(c ,word.substr(i+1)) )
                    {
                        return true;
                    }
                }
                return false;
            }
            int idx = ch - 'a';
            if(node->child[idx] == NULL)
                return false;
            node = node->child[idx];
        }
        return node->isLeaf;
    }
    bool search(string word) {
       TrieNode *node = root;
        return dfs(node,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */