# Adatlap
## Használat
1. > Legrövidebb utak `Start`-ból az összes csúcsba, egység hosszúságú éleknél
2. > Szélességi feszítőfa
3. > Kör keresése irányítatlan gráfban
## Big O notation
> O(N+M)
## Memória
> N
# Példakód
Bement
```c++
int n, start;
vector<vector<int>> graph(n, vector<int>(n));
```
## 1.
```c++
vector<int> timeS(n, -1);
vector<bool> doneS(n);
vector<bool> parentS(n);
queue<int> q;
timeS[start]=0;
doneS[start]=true;
q.push(start);
while(!q.empty()){
	int current=q.top(); q.pop();
	for(auto item:graph[current]){
		if(!doneS[item]){
			q.push(item);
			doneS[item]=true;
			timeS[item]=timeS[current]+1;
			parentS[item]=current;
		}
	}
}
```
## 2.
```c++
vector<vector<int> st(n, vector<int>(n));
vector<bool> doneS(n);
queue<int> q;
doneS[start]=true;
q.push(start);
while(!q.empty()){
	int current=q.top(); q.pop();
	for(auto item:graph[current]){
		if(!doneS[item]){
			q.push(item);
			doneS[item]=true;
			st[current].push_back(item);
			st[item].push_back(current);
		}
	}
}
```
## 3.
```c++
vector<bool> doneS(n);
vector<bool> parentS(n);
queue<int> q;
doneS[start]=true;
q.push(start);
bool circle=false;
while(!q.empty()){
	int current=q.top(); q.pop();
	for(auto item:graph[current]){
		if(!doneS[item]){
			q.push(item);
			doneS[item]=true;
			timeS[item]=timeS[current]++;
			parentS[item]=current;
		}else if(item!=parentS[current]){
			circle=true;
			break;
		}
	}
	if(circle){
		break;
	}
}
```
# Feladatok
mester.inf.elte.hu\Haladó\Gráfok, szélességi bejárás\\*