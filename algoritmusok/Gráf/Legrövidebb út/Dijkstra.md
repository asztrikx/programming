# Adatlap
## Használat
1. > Legrövidebb utak `Start`-ból az összes csúcsba, monoton összegű, szorzatú, ... éleknél
2. > Legrövidebb utak az összes csúcsból
## Big O notation
1. > O(NlogN+M)
2. > O(N^2logN+MN)
## Memória
> N^2
# Példakód
Bement
```c++
int n, start;
vector<vector<edge>> graph(n);
```
## 1.
```c++
struct edge{
	int weight, node;
	bool operator<(other edge){
		return weight>other.weight;
	}
}
vector<int> timeS(n, -1);
vector<int> doneS(n);
vector<int> parentS(n);
priority_queue<int> q;
timeS[start]=0;
doneS[start]=true;
q.push(start);
while(!q.empty()){
	int current=q.top().node; q.pop();
	if(doneS[current]){
		continue;
	}
	doneS[current]=true;
	for(auto item:graph[current]){
		if(
			!doneS[item.node] &&
			timeS[item.node] == -1 ||
			timeS[item.node] > timeS[current]+timeS[item].weight
		){
			timeS[item.node]=timeS[current]+timeS[item].weight;
			parentS[item.node]=current;
		}
	}
}
```
# Feladatok
⊆ mester.inf.elte.hu\Haladó\Gráfok, legrövidebb utak\\*