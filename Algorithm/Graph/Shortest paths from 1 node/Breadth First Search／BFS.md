# Thesis
> Shortest path from starting node to all nodes can be aquired in O(N + M)
# Proof
> Nodes can be divided into groups based on their shortest path's length  
> In the 0th group will be the start node  
> There may be a separate group if there are nodes which can't be reached. At first every node except the start will be here.     
---
## Thesis
> We can be sure that from the x-th group nodes may only be connected with nodes in the (x - 1)-th, (x + 1)-th or x-th group.
## Proof
> `If` A (A ∈ x-th) would be connected with node B (B ∈ y-th, `y < x - 1`)  
> `then` we could reach A in y + 1 which means (`y`) + 1 `<` (`x - 1`) + 1 = x.  
> `But` we said that x was the shortest path's length to A so y + 1 can't be smaller than x.  
>  
> `If` A (A ∈ x-th) would be connected with node B (B ∈ y-th, `y > x + 1`)  
> `then` we could reach B in x + 1 which means `x + 1 < y`.  
> `But` we said that y was the shortest path's length to B so x + 1 can't be smaller than y.  
---

> `Let's suppose` we know each groups' nodes until the x-th, meaning we know all the shortest paths with the maximum length of x.  
> `We know` that every shortest path with the length of x + 1 without the last node is also a shortest path (see thesis) with the length of (x + 1) - 1 = x.  
> `That means` there must be an `edge between` every node in `(x + 1)-th` group with one in the `x-th`.  
> `We know` that the x-th group may only be connected with the group x - 1, x, x + 1 from which only the (x + 1)-th group's is not complete currently.  
> `So` every node connected to the x-th group's nodes which are not caregorized into any group are the only nodes of (x + 1)th group. 
> The 0th group's nodes are known already as it is the start node only so we can complete the 1st group then the 2nd group and so on...
 
# Code
```c++
vector<vector<int>> g;
vector<int> timeS;
vector<int> parentS;
void bfs(int start) {
	//All nodes are unreachable by default
	timeS.resize(g.size(), -1);
	parentS.resize(g.size(), -1);
	//But we can reach the start node instantly
	timeS[start] = 0;

	//All categorized nodes in a vector
	//Until index i the vector contains the x-th group's nodes
	//After i the vector contains the currently explored (x + 1)-th group's nodes 
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		//x-th
		int current = q.front(); q.pop();
		for (auto child : g[current]) {
			//Only the (x + 1)-th children
			if (timeS[child] == -1) {
				timeS[child] = timeS[current] + 1;
				parentS[child] = parentS[current] + 1;
				q.push(child);
			}
		}
	}
}

void bfsPathto(int node) {
	//We know for every (x + 1)-th node what was the node that connected it to the x-th
	//If we want to get the path starting from the start node we must reverse the path
	stack<int> s;
	int current = node;
	while (current != -1) {
		s.push(current);
		current = parentS[current];
	}
	while (!s.empty()) {
		cout << s.top() << " "; s.pop();
	}
}
```