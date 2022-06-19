class Solution
{
    public:
        vector<vector < string>> suggestedProducts(vector<string> &products, string searchWord)
        {
            sort(products.begin(), products.end());

            vector<vector < string>> ans;
            for (int i = 1; i <= searchWord.size(); i++)
            {
                string z = searchWord.substr(0, i);
                vector<string> v;
                for (int j = 0; j < products.size(); j++)
                {
                    if (v.size() >= 3)
                        break;
                    else
                    {
                        string prd = products[j].substr(0, i);
                        if (prd == z)
                        {
                            v.push_back(products[j]);
                        }
                    }
                }
                ans.push_back(v);
            }
            return ans;
        }
};