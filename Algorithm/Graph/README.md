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