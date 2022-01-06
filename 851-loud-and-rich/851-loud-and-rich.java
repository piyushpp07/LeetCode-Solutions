class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        List<Integer>[] graph = new ArrayList[quiet.length + 1];
        for(int i = 0; i < quiet.length; i++){
            graph[i] = new ArrayList<>();
        }
	    for(int[] edge: richer){
		    graph[edge[1]].add(edge[0]);
	    }
	    int[]res = new int[quiet.length];
	    Arrays.fill(res,-1);
	    for(int i = 0; i < quiet.length; i++){
		    dfs(i, graph, quiet, res);
	    }
	    return res;
    }
    private int dfs(int src, List<Integer>[] graph, int[] quiet, int[]res){
	    if(res[src] == -1){
		    res[src] = src;
		    for(int e: graph[src]){
			    int curr = dfs(e, graph, quiet, res);
			    if(quiet[curr] < quiet[res[src]]){
				    res[src] = curr;
                }
		    }
	    }
	    return res[src];
    }
}