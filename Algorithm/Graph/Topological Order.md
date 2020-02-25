# Definition
> `Topological Order is an array` of the nodes where the i-th node is not connected with one in index < i 
# Thesis
> If there's a cycle in the graph we can not make one.
# Proof
> Let A be the subsequence of topological order containing the cycle's nodes.  
> The definition of topological order should hold on A as we have not changed to order of the nodes.  
## Thesis
> After choosing a node to be A0, Ai's child which is part of the cycle and not already in A will be A(i + 1).
## Proof
> If it wouldn't then it would be Aj (j > i + 1).  
> To reach the nodes in [i + 1, j) there must be an edge from [j, |A| - 1) which does not hold the definition of topological order.  
> We should be able to reach every element of the cycle from any node.
---
> Theres and edge between 
//[R] TODO