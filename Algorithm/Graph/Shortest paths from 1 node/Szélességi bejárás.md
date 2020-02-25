# Adatlap
## Használat
2. > Szélességi feszítőfa
3. > Kör keresése irányítatlan gráfban
# Példakód
Bement
```c++
int n, start;
vector<vector<int>> graph(n);
```
## 2.
```c++
vector<vector<int> st(n);
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