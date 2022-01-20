class Solution {
    
   public void swap(int [][]matrix,int i,int j)
  {
                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
  }
   public void transpose(int[][] matrix)
   {  // transpose 
        for(int i = 0;i<matrix.length;i++)
        {
            for(int j=i;j<matrix[0].length;j++)
            {
               swap(matrix,i,j);
            }
        }
   }
   public void reverse(int[][] matrix)
   {
       //for every row reverse all elements
       int k=0;
       int j=matrix[0].length-1;
       for(int i=0;i<matrix.length;i++)
       {
           while(k<=j)
           {
                int temp = matrix[i][j];
                matrix[i][j]=matrix[i][k];
                matrix[i][k]=temp;
               j--;
               k++;
           }
           k=0;
           j=matrix.length-1;
           
       }
       
   }
    public void rotate(int[][] matrix) {
     transpose(matrix);
     reverse(matrix);
    }
}