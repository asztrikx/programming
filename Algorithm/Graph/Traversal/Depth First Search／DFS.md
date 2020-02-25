# Thesis
[R] TODO

# Proof
[R] TODO

# Code
```c++
vector<int> colorS;
int timeAccess = 0;
int timeLeft = 0;
vector<int> timeAccessS;
vector<int> timeLeftS;
vector<int> parentS;
int dfs(int node) {
	//Pending node
	colorS[node] = 1;
	timeAccessS[node] = timeAccess++;

	for (auto child : g[node]) {
		if (colorS[child] == 0) {
			parentS[child] = node;
			dfs(child);
		}
		//assert(colorS[child] != 2);
	}

	//Finished node
	colorS[node] = 2;
	timeLeftS[node] = timeLeft++;
}
```