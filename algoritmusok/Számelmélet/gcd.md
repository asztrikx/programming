# Thesis
> Let `a` and `b` be `positive, whole` numbers  
> Let `a` be `greater than b`  
> Change `a to b` and `b to a % b` (simultaneously) until b is zero  
> The result will be in `a`  
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

## Thesis
> (a * b) % c = ((a % c) * (b % c)) % c

## Proof
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

## Thesis
> (b * a) % (b * c) = (a % c) * b
## Proof
> Let `k` be `positive, whole` number  
> Let `r` be the `remainder` of a % c, so r ∈ [0; c)  
> Let `r2` be the `remainder` of (b * a) % (b * c), so r ∈ [0; b * c)  
> a = k * c + r    
```
b * a = b * (k * c + r)
= b * k * c + b * r 
= k * (b * c) + (b * r)
//r < c so b * r < b * c so b * r will be the remainder when divided by b * c
= k * (b * c) + r2

(b * a) % (b * c) = r2 = b * r = b * (a % c)
```

> Generally  
> Let `g` be the unknown `GCD`  
> `x = a / g`  
> `y = b / g`  
> `a % b = (x * g) % (y * g) = (x % y) * g`  

|    a    |    b    |     a % b     |
| ------- | ------- | ------------- |
| `x` * g | `y` * g | (`x % y`) * g |

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
