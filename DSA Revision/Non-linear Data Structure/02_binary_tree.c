/**
 * Binary tree--> A tree which nodes have at most two children.
 * Important points -
 *      1. if a tree have  n nodes then no. of edges  = n-1 
 *      2. degree of tree = max(degree of node)
 *      3. degeee of node = no. of directed connected child.
 * 
 * Types of binary tree-->
 *      1.full or strict BT-> binary tree which nodes have 0 or two children .
 *      2.Perfect BT--> binary tree which internal nodes have two children and all leaf node are at same level.
 *      3.Complete BT-->perfect binary tree expect last level or last level are left aligned.
 *      4.Degenerate BT-->binary tree which parent nodes have only one children.
 *          type of degenerate tree.
 *          1.left skewed tree
 *          2.Right skewed tree
 * 
 * Representation of Binary Tree-->
 *      1. Array Representation--> not optimal
 *      2. Linked Representation--> using link (optimal)
 * note: if a node have only one child then its other child's value is NULL.
 * and leaf node's childs value are assing to NULL.
 *       
 */