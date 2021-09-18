# Thesis
- [R] TODO

# Proof
- [R] TODO

# Example
- [R] TODO

# Code
```c++
struct edge {
	int node1, node2, weight;
};
vector<edge> edgeS /*= {
	{ 0, 1, 2 },
	{ 0, 3, 6 },
	{ 1, 0, 2 },
	{ 1, 2, 3 },
	{ 1, 3, 8 },
	{ 1, 4, 5 },
	{ 2, 1, 3 },
	{ 2, 4, 7 },
	{ 3, 0, 6 },
	{ 3, 1, 8 },
	{ 3, 4, 9 },
	{ 4, 1, 5 },
	{ 4, 2, 7 },
	{ 4, 3, 9 },
}*/;
int n /*= 5*/;

vector<int> parentS;
vector<int> maxheightS;
int findd(int a) {
	if (a == parentS[a]) {
		return parentS[a];
	}

	return parentS[a] = findd(parentS[a]);
}

bool unionn(int a, int b) {
	int rootA = findd(a);
	int rootB = findd(b);
	if (rootA == rootB) {
		return false;
	}

	if (maxheightS[a] < maxheightS[b]) {
		parentS[rootA] = rootB;
	} else if (maxheightS[a] > maxheightS[b]) {
		parentS[rootB] = rootA;
	} else {
		parentS[rootA] = rootB;
		maxheightS[rootB]++;
	}
	return true;
}

vector<edge> mst;
int sum;
void kruskal() {
	mst.resize(0);
	sum = 0;

	parentS.resize(n);
	for (int i = 0; i < parentS.size(); i++) {
		parentS[i] = i;
	}
	maxheightS.assign(n, 1);

	sort(edgeS.begin(), edgeS.end(), [](edge a, edge b) {
		return a.weight < b.weight;
	});
	for (auto e : edgeS) {
		if (unionn(e.node1, e.node2)) {
			mst.push_back(e);
			sum += e.weight;
		}
	}
}
```

# Problems