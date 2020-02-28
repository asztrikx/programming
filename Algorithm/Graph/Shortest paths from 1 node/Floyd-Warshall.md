# Thesis
- [R] TODO
not simple graph --> negative edge --> negative cycle


# Proof
- [R] TODO

# Example
- [R] TODO

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
vector<vector<int>> timeSS;
vector<vector<int>> nextSS;
const int INFINITE = (1 << 31) - 1;
bool floydwarshall() {
	timeSS.assign(n, vector<int>(n, INFINITE));
	nextSS.assign(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++) {
		timeSS[i][i] = 0;
	}
	for (auto e : edgeS) {
		timeSS[e.start][e.end] = e.weight;
		nextSS[e.start][e.end] = e.end;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//Prevent overflow when adding together
				if (timeSS[i][k] == INFINITE || timeSS[k][j] == INFINITE) {
					continue;
				}
				if (timeSS[i][j] > timeSS[i][k] + timeSS[k][j]) {
					timeSS[i][j] = timeSS[i][k] + timeSS[k][j];
					nextSS[i][j] = nextSS[i][k];
				}
			}
		}
	}

	bool negativecycle = false;
	for (int i = 0; i < n; i++) {
		if (timeSS[i][i] < 0) {
			negativecycle = true;
			break;
		}
	}
	return !negativecycle;
}

void floydwarshallPath(int start, int end) {
	if (start == end) {
		cout << end << endl;
		return;
	}

	cout << start << endl;
	floydwarshallPath(nextSS[start][end], end);
}
```

# Problems