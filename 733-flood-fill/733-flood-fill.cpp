class Solution {
private : int dx[4] ={0,1,0,-1};
          int dy[4] = {-1,0,1,0};
    void dfs(vector<vector<int>>&image,int sr,int sc,int newColor,int num)
    {
        if(sr<0||sc<0||sr>=image.size()||sc>=image[0].size())
            return ;
        image[sr][sc] = newColor;
        for(int i = 0;i<4;i++)
        {   
            int x = dx[i]+sr;
            int y = dy[i]+sc;
            if(x>=0&&x<image.size()&&y>=0&&y<image[0].size()){
                if(image[x][y]==num)
                    dfs(image,x,y,newColor,num);
            }
        }
    }
          
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int num = image[sr][sc];
        if(num == newColor)
            return image;
        else{
        dfs(image,sr,sc,newColor,num);
        return image;            
        }

    }
};