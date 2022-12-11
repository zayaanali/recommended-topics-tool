
### Results
---
Overall, we were able to complete most of the goals we set out to, however we ran into some issues with the output of one of our algorithms
#### Our deliverables
   * Our makefiles runs as expected
   * We properly read in our wikipedia set and built a graph based on it
   * We have thoroughly tested our graph and algorithms for bugs and memory leaks
   * 2 Wikipedia page input outputs page related to both results
   * 1 Wikipedia page recommendations are too large to be useful
   * see Kosaraju's algorithm for more details	 
#### Algorithms & Traversals
   * Dataset trimming
      * Trimmed dataset from 4 million nodes and 100 million edges to top 24 thousand with highest in-degree
      * Ran BFS on three seed nodes, terminated two steps from seed
      * Filtered out discarded nodes and output adjacency list to file in CSV format with 15.5 thousand nodes and about 952 thousand edges
   * Used Brandes Betweeness Centrality algorithm to determine the betweeness centrality of each wikipedia page in the trimmed dataset
      * output placed in CSV that can be loaded into a map to avoid expensive algorithm cost 
      * Used the CSV to get related article for 2 page input	 
   * Used Kosaraju's Algorithm to find all of the strongly connected components in the trimmed dataset
    	* consisted of first finding the DFS traversal of the graph, then running DFS again on the transpose of the original graph in the order of the original DFS
    	* Output resulted in nearly the all nodes being strongly connected (15.2k nodes)
    	* This algorithm was therefore unable to provide us with any useful recommendation since nearly the entire dataset is strongly connected


#### Example results:
```
insert results here
```
