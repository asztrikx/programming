# Thesis
- [R] TODO

# Proof
- [R] TODO

# Example
- [R] TODO

# Code
```c++
struct edge {
	int start, end, weight;

	bool operator<(edge other) const {
		return weight > other.weight;
	}
};
vector<vector<edge>> g /*= {
	{ { 0, 1, 2 }, { 0, 3, 6 }, },
	{ { 1, 0, 2 }, { 1, 2, 3 }, { 1, 3, 8 }, { 1, 4, 5 } },
	{ { 2, 1, 3 }, { 2, 4, 7 }, },
	{ { 3, 0, 6 }, { 3, 1, 8 }, { 3, 4, 9 }, },
	{ { 4, 1, 5 }, { 4, 2, 7 }, { 4, 3, 9 }, },
}*/;

vector<edge> mst;
int sum;
void prim() {
	vector<bool> doneS(g.size());
	priority_queue<edge> pq;
	doneS[0] = true;
	for (auto e : g[0]) {
		pq.push(e);
	}
	while (!pq.empty()) {
		auto current = pq.top(); pq.pop();
		if (doneS[current.end]) {
			continue;
		}
		mst.push_back(current);
		sum += current.weight;
		doneS[current.end] = true;

		for (auto e : g[current.end]) {
			if (!doneS[e.end]) {
				pq.push(e);
			}
		}
	}
}
```

# Problems
