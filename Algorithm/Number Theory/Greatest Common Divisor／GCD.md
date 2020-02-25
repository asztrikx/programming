# Thesis
> To calculate gcd(a, b) call gcd(b, a % b) until b is zero  
> The result will be in `a`  
# Proof
> Let `g` be the unknown `GCD`  
> Let `x` be `a / g`  
> Let `y` be `b / g`  
> By definition a >= b so x * g >= y * g so `x >= y`  
> Because of the thesis `a % b =` (x * g) % (y * g) = `(x % y) * g`  
> `x % y ∈ [0; y)` which means the multiplier decreases in each iteration, reaching 0 in the end.  
## Thesis
> Before x % y would reach 0 it will be 1
## Proof
> `If` b = 0  
> `then` gcd(a, b) = gcd(a, 0) = a  
> `so` a = 1 * a = 1 * gcd(a, b)  
> b = 0 = 0 * gcd(a, b)  

> `Otherwise` let's suppose it won't be 1  

|   a    |   b    | a % b  |
| ------ | ------ | ------ |
| 52 * 3 | 28 * 3 | 24 * 3 |
| 28 * 3 | 24 * 3 | 4 * 3  |
| 24 * 3 | 4 * 3  | 0      |
| 4 * 3  | 0      | -      |
> Let `g = gcd(a, b)`  
> Let `A be a vector containing the values of b in reverse order`  
> Let the `first a` value be the `last element of A`  
> (in this example A = (0; 12; 72; 84; 156))  
> Let `Ai` be the `element of A` where `i is the index`  
> Let `Ki be a non-negative integer` where `i is the index`  
> Let `L be a positive integer` which is now not 1  
> Let `Hi be a non-negative integer` where `i is the index`  
```
A0 = K0 * g = 0 * g = 0 * L * g = 0;
A1 = K1 * g = L * g;
A2 = K2 * g;

A2 % A1 = A0
(K2 * g) % (L * g) = 0
(K2 % L) * g = 0
K2 % L = 0
K2 = H2 * L + 0
A2 = K2 * g = H2 * L * g
```
> A0, A1, A2 is a multiple of L  
### Thesis
> `If` there are more than 3 elements in A  
> Let `i be greater than 2`  
> Let `k be a non-negative integer`  
> `If` A(i - 2) and A(i - 1) is a multiple of L  
> `then` Ai is also a multiple of L  
### Proof
```
A(i - 2) = H(i - 2) * L * g
A(i - 1) = H(i - 1) * L * g
Ai = Ki * g

Ai % A(i - 1) = A(i - 2)
(Ki * g) % (H(i - 1) * L * g) = H(i - 2) * L * g
(Ki % (H(i - 1) * L)) * g = H(i - 2) * L * g
Ki % (H(i - 1) * L) = H(i - 2) * L
Ki = k * (H(i - 1) * L) + H(i - 2) * L
Ki = k * H(i - 1) * L + H(i - 2) * L
Ki = L * (k * H(i - 1) + H(i - 2))
Ai = Ki * g = L * (k * H(i - 1) + H(i - 2)) * g
```
---
> Ai is a multiple of L  
> `Therefore` Ai / L / g = Ai / (L * g) is an integer  
> `which means` that the gcd(a, b) should have been L * g  
> A1 = (L * g) = gcd(a, b) = 1 * gcd(a, b)  
> `so` it will always be 1


|      a       |      b      |    a % b    |
| ------------ | ----------- | ----------- |
| 13 * 4 * `3` | 7 * 4 * `3` | 6 * 4 * `3` |
| 7 * 4 * `3`  | 6 * 4 * `3` | 1 * 4 * `3` |
| 6 * 4 * `3`  | 1 * 4 * `3` | 0 * 4 * `3` |
| 1 * 4 * `3`  | 0 * 4 * `3` | -           |

|     a     |    b     |  a % b   |
| --------- | -------- | -------- |
| 13 * `12` | 7 * `12` | 6 * `12` |
| 7 * `12`  | 6 * `12` | 1 * `12` |
| 6 * `12`  | 1 * `12` | 0 * `12` |
| 1 * `12`  | 0 * `12` | -        |
---

> The gcd(a, b) will in fact be in `a` when `b = 0`  

# Example
> `a = 270`  
> `b = 192`  

|  a  |  b  | a % b |
| --- | --- | ----- |
| 270 | 192 | 78    |
| 192 | 78  | 36    |
| 78  | 36  | 6     |
| 36  | 6   | 0     |
| 6   | 0   |       |

> GCD is 6  
> `a = 45 * 6`  
> `b = 32 * 6` 

|   a    |   b    | a % b  |
| ------ | ------ | ------ |
| 45 * 6 | 32 * 6 | 13 * 6 |
| 32 * 6 | 13 * 6 | 6 * 6  |
| 13 * 6 | 6 * 6  | 1 * 6  |
| 6 * 6  | 1 * 6  | 0 * 6  |
| 1 * 6  | 0 * 6  |        |

# Code
```c++
int gcd(int a, int b) {
	//a shall be greater than b based on thesis
	if (a < b) {
		return gcd(b, a);
	}

	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
```
> gcd(406, 224) = 14  
> gcd(224, 406) = gcd(406, 224)  
