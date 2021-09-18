# Thesis
- [R] TODO: same as recursion, but: no stackoverflow(in c++ it is not a problem), memory reduction (formula only uses previous state, or the last state can be overwritten(floyd))
- https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/
[R] TODO
DP kérdések, amik irányában érdemes elindulni:
Hány dimenziód van? (Ütemterves feladatoknál: tömbindex, idő, érték)
A) Rendezés: Melyik dimenzió szerint? (Esetleg érték és idő hányadosa szerint?)
B) [1..i] intervallum vagy [i..j] intervallumot érdemes figyelembe venni
C) Minden "dimenzió" legyen valahol: D[tömbindex][idő] = érték pl.
D) Tudsz eldobni egy indexet (D[i][j] helyett D[j])?
E) Kell prev tömböt fenntartani?
F) A kimenet rendezett? N -> logN optimalizációt enged esetleg?

# Proof
- [R] TODO

# Example
- [R] TODO

# Code
# Alap //szülő kiírása
# Optimalizáció
# floyd
# Bitmask DP
```c++

```

# Problems
1. [mester/NT, OKTV, IOI Válogató/IOI Válogató 2018/7. Találkozó](https://github.com/asztrikx/mester-linux/blob/master/NT%2C%20OKTV%2C%20IOI%20V%C3%A1logat%C3%B3/IOI%20V%C3%A1logat%C3%B3%202018/7.%20Tal%C3%A1lkoz%C3%B3%20%20%20%20__-100/feladat.pdf)
1. [mester/NT, OKTV, IOI Válogató/IOI Válogató 2018/10. Vásárlások](https://github.com/asztrikx/mester-linux/blob/master/NT%2C%20OKTV%2C%20IOI%20V%C3%A1logat%C3%B3/IOI%20V%C3%A1logat%C3%B3%202018/10.%20V%C3%A1s%C3%A1rl%C3%A1sok%20%20%20%20__-100/feladat.pdf)
