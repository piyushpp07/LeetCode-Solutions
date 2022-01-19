class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int minr=0;
        int minc=0;
        int maxr=matrix.length-1;
        List<Integer>arr=new ArrayList<Integer>();
        int maxc=matrix[0].length-1;
        int count =0;
        int total = matrix.length*matrix[0].length;
        
        while(count<total)
        {
            for(int j=minc;j<=maxc&&count<total;j++)
            {
                arr.add(matrix[minr][j]);
                count++;
            }
            minr++;
            for(int i=minr;i<=maxr&&count<total;i++)
            {
                arr.add(matrix[i][maxc]);
                count++;
            }
            maxc--;
            for(int j=maxc;j>=minc&&count<total;j--)
            {
                arr.add(matrix[maxr][j]);
                count++;
            }
            maxr--;
            for(int i=maxr;i>=minr&&count<total;i--)
            {
                arr.add(matrix[i][minc]);
                count++;
            }
            minc++;            
        }
        return arr;
        
    }
}