# [R] TODO
# Adatlap
## Használat
1. > Legrövidebb utak `Start`-ból az összes csúcsba, monoton összegű, szorzatú, ... éleknél
2. > Legrövidebb utak az összes csúcsból
## Big O notation
1. > O(NlogN+M)
2. > O(N^2logN+MN)

if - edges convert to +

# Code
```c++
struct edge {
	int start, end, weight;
	bool operator<(edge other) const {
		return weight > other.weight;
	}
};
vector<vector<edge>> g /*= {
	{ { -1, 1, 4 }, { -1, 7, 8 }, },
	{ { -1, 0, 4 }, { -1, 2, 8 }, { -1, 7, 11 }, },
	{ { -1, 1, 8 }, { -1, 3, 7 }, { -1, 5, 4 }, { -1, 8, 2 }, },
	{ { -1, 2, 7 }, { -1, 4, 9 }, { -1, 5, 14 }, },
	{ { -1, 3, 9 }, { -1, 5, 10 }, },
	{ { -1, 2, 4 }, { -1, 3, 14 }, { -1, 4, 10 }, { -1, 6, 2 }, },
	{ { -1, 5, 2 }, { -1, 7, 1 }, { -1, 8, 6 }, },
	{ { -1, 0, 8 }, { -1, 1, 11 }, { -1, 6, 1 }, { -1, 8, 7 }, },
	{ { -1, 2, 2 }, { -1, 6, 6 }, { -1, 7, 7 }, },
}*/;
vector<int> timeS;
vector<int> parentS;
void dijkstra(int start) {
	timeS.assign(g.size(), -1);
	parentS.assign(g.size(), -1);
	priority_queue<edge> pq;

	pq.push({ -1, start, 0 });
	while (!pq.empty()) {
		edge e = pq.top(); pq.pop();
		if (timeS[e.end] != -1) {
			continue;
		}

		timeS[e.end] = e.weight;
		parentS[e.end] = e.start;
		for (auto ee : g[e.end]) {
			if (timeS[ee.end] == -1) {
				pq.push({ e.end , ee.end , timeS[e.end] + ee.weight });
			}
		}
	}
}

void dijkstraPath(int node) {
	if (node == -1) {
		return;
	}

	dijkstraPath(parentS[node]);
	cout << node << endl;
}
```

# Problems
1. ⊆ mester.inf.elte.hu/Haladó/Gráfok, legrövidebb utak/*