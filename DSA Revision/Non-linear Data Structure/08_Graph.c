/**
 *  Graph-
 *      1.it has nodes (veritces) and edges.
 *      2.Trees are also be graph
 *      3.An edge is uniquilky defined by its two endspoint.
 * 
 *      Application of Graph:
 *          i. used to model paths in a city , social networks , website backlinks etc.
 *          ii. used to model relationships between the node
 *    
 *      type of graph
 *          i. Directed graph- graph which has directed edges(one way connection) is called directed graph.
 *          ii.Undirected graph- it has undirected edges(two way connection)
 * 
 *      Indegree of a node: number of edges directed to the node.
 *      Outdegree of a node: number of edges coming out to the node.
 * 
 * 
 * 
 * 
 *          0
 *        /   \
 *       1-----2
 *      /       \
 *     3         4
 * Representation of the graph:
 *      1.Adjacency list- Mark the node with list of its neighbours
 *          representation of the above graph
 *          0->1->2
 *          1->0->2->3
 *          2->0->1->4
 *          3->1
 *          4->2
 *      2.Adjacency matrix: 1 for edge between i and j , otherwise 0!
 *          0   1   2   3   4
 *      0   0   1   1   0   0
 *      1   1   0   1   1   0   
 *      2   1   1   0   0   1
 *      3   0   1   0   0   0
 *      4   0   0   1   0   0
 * 
 *      Other representation technique of the graph
 *          i.Edge set--collection of connected edge
 *          ii.Cost adjacency list
 *          iii.Cost adjacency matrix
 * 
 *      3.Cost Adjacency matrix:
 *          Aij=sif no edge then -1, otherwise cost
 */