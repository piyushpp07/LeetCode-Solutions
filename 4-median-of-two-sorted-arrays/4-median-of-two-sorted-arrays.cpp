class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        vector<int>v;
        int n = num1.size();int m =num2.size();
        int i =0 , j =0;
        while(i<n&&j<m)
        {
            if(num1[i]>num2[j])
            {
                v.push_back(num2[j++]);
            }
            else
            v.push_back(num1[i++]);
        }
        while(i<n)
             v.push_back(num1[i++]);
        while(j<m)
              v.push_back(num2[j++]);
        if(v.size()%2==0)
            return (double)(double(v[v.size() / 2]  + v[v.size() / 2 - 1]))/2;
        else return double(v[v.size()/2]);
    }
};