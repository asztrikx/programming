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

| Név | Kezdés | Befejezés |
| --- | --- | --- |
| Visszaél | u>v | u<v |
| Előreél | u<v | u>v |
| Keresztél | u>v | u>v |
| Faél | u<v | u>v |
# Típusok
## Sűrű/Dense
## Ritka/Sparse
## Irányított/Directed
## Irányítatlan/Undirected