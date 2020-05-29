# Thesis
> `If` a >= 0 `Then`  
> ⌈a/b⌉ = ⌊(a+b-1)/b⌋
# Proof
```
    0/b 1/b 2/b ... b/b (b+1)/b (b+2)/b ... 2b/b
⌈x⌉   0   1   1       1     2       2          2 
⌊x⌋   0   0   0       1     1       1          2 


Values are shifted by b-1 between roundup and rounddown
```
# Code
```c++
int roundupDivision(int a, int b) {
	return (a + b - 1) / b;
}
```
