# Thesis
> Shortest path from starting node to all nodes can be aquired in O(N)
# Proof
> Nodes can be divided into groups based on their shortest path's length  
> In the 0th group will be the start node  
---
## Thesis
> We can be sure that from the x-th group nodes are only connected with nodes in the (x - 1)-th or (x + 1)-th group.
## Proof
> `If` A (A ∈ x-th) would be connected with node B (B ∈ y-th, y < x - 1)  
> `then` we could reach A in (y) + 1 which means (y) + 1 < (x - 1) + 1 = x.  
> `But` we said that x was the shortest path's length to A so y + 1 can't be smaller than x.  
>  
> `If` A (A ∈ x-th) would be connected with node B (B ∈ y-th, y > x + 1)  
> `then` we could reach B in (x) + 1.  
> `But` we said that y was the shortest path's length to B so x + 1 can't be smaller than y.  
---

> `If` we know each groups' nodes until the x-th, meaning we know all the shortest paths with the maximum length of x  
> `then` we know that the uncategorized nodes connected to nodes in the x-th group, must be in the group (x + 1)  
> `as` x-th group's nodes can only be connected to nodes in (x - 1)-th or (x + 1)-th group `but` (x - 1)-th group's nodes are already categorized and we looked at uncategorized nodes.  
> `Because` nodes in (x + 1)-th group must be reachable, they must be connected to x-th group `so` we already know each node in the (x + 1)-th group.  
> The 0th group was completed already so we can complete the 1st then the 2nd and so on...
# Code
```c++
vector<vector<int>> g;
vector<int> timeS;
void bfs(int start) {
	//All nodes are unreachable by default
	timeS.resize(g.size(), -1);
	//But we can reach the start node instantly
	timeS[start] = 0;

	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int current = q.front(); q.pop();
		for (auto child : g[current]) {
			//If the shortest time is not determined yet
			if (timeS[child] == -1) {
				timeS[child] = timeS[current] + 1;
				q.push(child);
			}
		}
	}
}
```
# Example
[R] KÉp
[R] KÉp átrendezve

```csharp
bool[,] g;
int n;

bool[] ElértCsúcsok;
int[] táv;
int[] szülő;
void Szélességi(int start)
{
	ElértCsúcsok = new bool[n];
	táv = new int[n];
	szülő = new int[n];
	for (int i = 0; i < n; i++)
	{
		táv[i] = int.MaxValue;
		szülő[i] = -1;
		ElértCsúcsok[i] = false;
	}

	Queue<int> q = new Queue<int>();
	q.Enqueue(start);
	ElértCsúcsok[start] = true;
	táv[start] = 0;
	while (q.Count > 0)
	{
		int current = q.Dequeue();
		for (int i = 0; i < n; i++)
		{
			if (!g[current, i] || ElértCsúcsok[i])
				continue;
				
			q.Enqueue(i);
			ElértCsúcsok[i] = true;
			táv[i] = táv[current] + 1;
			szülő[i] = current;
		}
	}
}
void Útkiír(int cél)  
{
	Stack<int> v = new Stack<int>();
	while (cél != -1)
	{
		v.Push(cél);
		cél = szülő[cél];
	}
	while (v.Count > 0)
		Console.Write(v.Pop() + " ");
}
void Main(string[] args)
{
	StreamReader sr = new StreamReader("input.txt");
	n = int.Parse(sr.ReadLine());
	int m = new bool[n, n];
	for (int i = 0; i < n; ++i)
	{
	   	string[] s = sr.ReadLine().Split('\t');
		g[int.Parse(s[0]), int.Parse(s[1])] = true;
	}

	Szélességi(0);
	Console.WriteLine();
	Útkiír(5);
	Console.Read();
}
```