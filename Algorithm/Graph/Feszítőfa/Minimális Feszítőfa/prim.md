```c++
struct edge{
	int from,node,weight;
	bool operator<(edge other) const{
        return weight>other.weight;
	}
};

int main()
{
    //Input
    int n,m;
    cin>>n>>m;

    vector<vector<edge>> g(n+1);
    for(int i=0;i<m;i++){
		int node1, node2;
		edge e;
		cin>>node1>>node2>>e.weight;

		e.node=node2;
		e.from=node1;
		g[node1].push_back(e);
		e.node=node1;
		e.from=node2;
		g[node2].push_back(e);
    }

    //Process & Output
    vector<bool> doneS(n+1);
    priority_queue<edge> q;
    for(edge e:g[1]){
		q.push(e);
    }
    doneS[1]=true;
    int sum=0;
    while(!q.empty()){
        edge current=q.top(); q.pop();
        if(doneS[current.node]){
			continue;
        }
        doneS[current.node]=true;

		for(edge e:g[current.node]){
			q.push(e);
		}
        cout<<current.from<<" "<<current.node<<" "<<current.weight<<'\n';
        sum+=current.weight;
    }
    cout<<sum;
}
```