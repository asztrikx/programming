# [R] TODO
## Használat
1. > Legrövidebb utak `Start`-ból az összes csúcsba, ha nincs negatív kör
2. > Negatív kör meghatározása
## Big O notation
> O(N^2+MN)
## Memória
> N

# Code
```c++
struct edge {
	int start, end, weight;
};
int n /*= 5*/;
vector<edge> edgeS /*= {
	{ 0, 1, -1 },
	{ 0, 2, 4 },
	{ 1, 2, 3 },
	{ 1, 3, 2 },
	{ 1, 4, 2 },
	{ 3, 2, 5 },
	{ 3, 1, 1 },
	{ 4, 3, -3 },
}*/;
vector<int> timeS;
vector<int> parentS;
const int INFINITE = (1 << 31) - 1;
bool bellmanford(int start) {
	timeS.assign(n, INFINITE);
	parentS.assign(n, -1);
	timeS[start] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (auto e : edgeS) {
			if (timeS[e.end] > timeS[e.start] + e.weight) {
				timeS[e.end] = timeS[e.start] + e.weight;
				parentS[e.end] = e.start;
			}
		}
	}

	//Negative cycle in this component
	bool negativecycle = false;
	for (int j = 0; j < n; j++) {
		for (auto e : edgeS) {
			if (timeS[e.end] > timeS[e.start] + e.weight) {
				negativecycle = true;
				break;
			}
		}
	}
	return !negativecycle;
}

void bfsPathto(int node) {
	if (node == -1) {
		return;
	}

	bfsPathto(parentS[node]);
	cout << node << endl;
}
```

# Problems
1. ⊆ mester.inf.elte.hu/Haladó/Gráfok, legrövidebb utak/*