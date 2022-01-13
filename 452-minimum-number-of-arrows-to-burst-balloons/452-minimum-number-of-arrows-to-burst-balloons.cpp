class Solution {
private:
    static bool sortcol(const vector<int>&v1,const vector<int>&v2)
    {
        return v1[1]<v2[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& vect) {
        if(vect.size()==0)
            return 0;
        sort(vect.begin(), vect.end(),sortcol);
        int count = 0;
        int n=vect.size();
        int last =vect[0][1];
        int  arrow =1 ;
        for(int i=1;i<n;i++)
        {
            if(vect[i][0]>last)
            {
                arrow++;
                last = vect[i][1];
            }
        }
        return arrow;
    }
};