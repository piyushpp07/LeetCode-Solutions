class TrieNode{
    public:
    TrieNode *child[26];
    bool isLeaf;
    int cnt;
    TrieNode()
    {
        isLeaf = false;
        memset(child,0,sizeof child);
        cnt = 0;
    }
};
class Solution {
public:
    TrieNode *root ;
    Solution()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *node = root;
        for(auto i : word)
        {
            int idx = i - 'a';
            if(node->child[idx] == NULL)
            {
                node->child[idx] = new TrieNode();
            }
            
            node = node->child[idx];
            node->cnt += 1;
        }
        node->isLeaf = true;
    }
    int search(string s)
    {
        int ans = 0;
        TrieNode *node = root;
        for(auto i : s)
        {
            int idx = i - 'a';
            ans += node->cnt;
            node = node->child[idx];
                 
        }
        ans += node->cnt;
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto i : words)
        {
            insert(i);
        }
        vector<int>v;
        for(int i =0;i<words.size();i++)
        {
            string word = words[i];

            int curr = search(word);
            v.push_back(curr);
        }
        return v;
    }
};