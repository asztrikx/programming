# Adatlap
## Használat
1. > Legrövidebb utak `Start`-ból az összes csúcsba, ha nincs negatív kör
2. > Negatív kör meghatározása
## Big O notation
> O(N*(N+M))
## Memória
> N
# Példakód
Bement
```c++
int n, start;
vector<vector<edge>> graph(n, vector<int>(n));
```
## 1. (`Egyszerű gráf`, `irányítatlan`)
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
timeS[start]=0;
doneS[start]=true;
queue<int> q;
q.push(start);
q.push(-1);
for(int i=0; i<n-1; i++){
	while(true){
		int j=q.top(); q.pop();
		if(j==-1){
			break;
			q.push(-1);
		}
		for(auto item:graph[j]){
			if(parentS[j]==item.node){
				continue;
			}
			if(timeS[item.node]>timeS[j]+timeS[item.weight]){
				timeS[item.node]=timeS[j]+timeS[item.weight];
				parentS[item.node]=j;
				q.push(item.node);
			}
		}
	}
	if(q.size()!=1){
		break;
	}
}
```
## 2.
```c++
????
```
# Feladatok
⊆ mester.inf.elte.hu\Haladó\Gráfok, legrövidebb utak\\*