# [R] TODO
# Adatlap
## Használat
1. > Legrövidebb utak `Start`-ból az összes csúcsba, monoton összegű, szorzatú, ... éleknél
2. > Legrövidebb utak az összes csúcsból
## Big O notation
1. > O(NlogN+M)
2. > O(N^2logN+MN)

# Code
```c++
vector<vector<edge>> g;
struct edge {
	int start, end, weight;
	bool operator<(edge other) const {
		return weight > other.weight;
	}
};
vector<int> timeS;
vector<int> parentS;
void dijkstra(int start) {
	timeS.assign(g.size(), -1);
	parentS.assign(g.size(), -1);
	priority_queue<edge> pq;

	edge e;
	e.start = -1;
	e.end = start;
	e.weight = 0;
	pq.push(e);
	while (!pq.empty()) {
		e = pq.top(); pq.pop();
		if (timeS[e.end] != -1) {
			continue;
		}

		timeS[e.end] = e.weight;
		parentS[e.end] = e.start;
		for (auto ee : g[e.end]) {
			if (timeS[ee] == -1) {
				edge enew;
				enew.start = e.end;
				enew.end = ee.end;
				enew.weight = timeS[e.end] + ee.weight;
				pq.push(enew);
			}
		}
	}
}
```
# Problems
1. ⊆ mester.inf.elte.hu/Haladó/Gráfok, legrövidebb utak/*