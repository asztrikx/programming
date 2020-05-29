# Graph
> Graph consist of `nodes` and `edges`  
> `node` is an object, it can hold anything, usually an unique identifier  
> `edge` is an ordered set consisting of three values  
> - A unique identifier of the node `s` it `starts from`
> - A unique identifier of the node `e` where it `ends`  
> - A value of cost, also called as `weight` it takes to move from `s` to `e`  

## Notation
- `node:` V/Verticies/Nodes
- `number of nodes:` N
- `edge:` E/Edges E = (s, e, c)
- `number of edges:` M
- `graph:` G/Graph G = (V, E)

# Definition
- `child`
	- [R] TODO
- `parent`
	- [R] TODO
- `negative cycle`
	- [R] TODO

## Types
- Edges
	- Direction
		- `Directed`
		- `Undirected`
			> ∃ (s, e, c) ∈ E → (e, s, c)
	- Weight
		- `Weighted`
		- `Unweighted`
			> Can be viewed as all edge have the same weight `c`
	- Number
		- `Sparse`
		- `Dense`
			> Close to maximum number of edges: ≈N^2
	- `Connected`
		- [R] TODO
	- `Strongly Connected`
		- [R] TODO
	- `Simple`
		- [R] TODO

## Representation
- Adjacency Matrix
	- [R] TODO
- Adjacency List
	- [R] TODO

# Danger
- Complex? graph
	- [R] TODO
- Not connected? graph
	- [R] TODO
- Undirected graph
	- [R] TODO

# [R] TODO
- postfix
- prefix
- infix
- infós füzetek
- összes út pl dijkstra

# Ábrázolás
## Csúcsmátrix
## Éllista
## Szomszédsági lista
## Első gyerek, következő gyerek
# Élek
## Visszaél/Back edge
> Közvetett felmenőre mutató él  
> Hurokél  
## Előreél/Forward edge
> Közvetett leszármazottra mutató él
## Keresztél/Cross edge
> Nem leszármazottra vagy felmenőre mutató él  
> \==  
> Már bejárt területre mutató él
## Faél/Tree edge
> Maradék él

# Élek mélységi bejárás ideje szerint  
u->v

| Név       | Kezdés | Befejezés |
|-----------|--------|-----------|
| Visszaél  | u>v    | u<v       |
| Előreél   | u<v    | u>v       |
| Keresztél | u>v    | u>v       |
| Faél      | u<v    | u>v       |

# Trükkök
- csúcs sokszorozás  
	1. [mester/NT, OKTV, IOI Válogató/IOI Válogató 2019/11. Csatornák](https://github.com/asztrikx/mester-linux/blob/master/NT%2C%20OKTV%2C%20IOI%20V%C3%A1logat%C3%B3/IOI%20V%C3%A1logat%C3%B3%202019/11.%20Csatorn%C3%A1k%20%20%20%20__-100) (részleges pontszám/feladat.pdf)
	1. [mester/NT, OKTV, IOI Válogató/OKTV 2018 ∕ 19 3. forduló/6. Vasútállomások (30 pont)](https://github.com/asztrikx/mester-linux/blob/master/NT%2C%20OKTV%2C%20IOI%20V%C3%A1logat%C3%B3/OKTV%202018%20%E2%88%95%2019%203.%20fordul%C3%B3/6.%20Vas%C3%BAt%C3%A1llom%C3%A1sok%20(30%20pont)%20%20%20%20__-30/feladat.pdf)