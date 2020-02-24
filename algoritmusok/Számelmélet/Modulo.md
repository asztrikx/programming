# In Programming
> Modulo function should look like this  
```
      (y) ʌ              
          |              
    x    x|   x    x    x
   x    x |  x    x    x 
  x    x  | x    x    x  
 x    x   |x    x    x   
x----x----x----x----x----> (x)
          |              
```
> f(x) = x % m  
```
          (y) ʌ              
              |              
              |   x    x    x
              |  x    x    x 
              | x    x    x  
              |x    x    x   
----x----x----x----x----x----> (x)
   x    x    x|              
  x    x    x |              
 x    x    x  |              
x    x    x   |              
              |              
```
> f(x) = x % m + m  
```
      (y) ʌ              
          |              
          |   x    x    x              
          |  x    x    x               
          | x    x    x               
          |x    x    x                 
          x    x    x                  
    x    x|              
   x    x |              
  x    x  |              
 x    x   |              
x----x----|--------------> (x)
          |              
```
> f(x) = (x % m + m) % m  
```
      (y) ʌ              
          |              
    x    x|   x    x    x
   x    x |  x    x    x 
  x    x  | x    x    x  
 x    x   |x    x    x   
x----x----x----x----x----> (x)
          |              
```
## Code
```c++
int mod(int a, int b) {
	return (a % b + b) % b;
}
```

# Thesis
> (a * b) % c = ((a % c) * (b % c)) % c

# Proof
> Let `k1, k2, k3` be `positive, whole` numbers  
> Let `r1, r2` be the `remainders`, so r1, r2 ∈ [0; c)  
> a = k1 * c + r1  
> b = k2 * c + r2  
```
(a * b) % c = ((k1 * c + r1) * (k2 * c + r2)) % c
= (c^2 * k1 * k2 + c * k1 * r2 + c * k2 * r1 + r1 * r2) % c
= (c * (c * k1 * k2 + k1 * r2 + k2 * r1) + r1 * r2) % c
= (c * k3 + r1 * r2) % c
= (r1 * r2) % c
= (a % c * b % c) % c
```