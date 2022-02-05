class Solution {
    public int[][] merge(int[][] arr) {
         
        int n = arr.length;
        ArrayList<Pair> myList = new ArrayList<Pair>();
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        Stack<Integer>st = new Stack<>();
        st.push(arr[0][0]);
        st.push(arr[0][1]);
        int z  = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i][0]>st.peek())
            {
                int k = st.pop();
                int j = st.pop();
                myList.add(new Pair(j,k));
                z++;
                st.push(arr[i][0]);
                st.push(arr[i][1]);
            }
            else if(st.peek()<arr[i][1])
            {
                st.pop();
                st.push(arr[i][1]);
            }
            else 
            continue;
        }
        int i = st.pop();
        int j = st.pop();
        myList.add(new Pair(j,i));
        int m = myList.size();
        int [][]ans = new int[m][2];
        for(int q=0;q<m;q++)
        {
            ans[q][0]=myList.get(q).st;
            ans[q][1]=myList.get(q).et;
        }
        return ans;
    }
    public static class Pair{
        int st;
        int et;
        Pair(int st,int et)
        {
            this.st = st;
            this.et = et;
        }
    }
    
}