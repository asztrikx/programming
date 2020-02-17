# Thesis
> `If` a >= 0 `And` b >= 0 `Then`  
> a ^ b can be done in O(log(b))  
> We multiple b with itself (double the exponentiation each iteration) and  
> `If` in the binary form at index iterationCount (starting from 0) from right is 1  
> `Then` we multiply b to result starting from 1
# Example
> 3^13
```
13(10) = 1101(2)
3^13 = (1 * 3^1) * (0 * 3^2) * (1 * 3^4) * (1 * 3^8) = 3^1 * 3^4 * 3^8 = 3^13
```
# Code
```c++
//a^b
long long exp(long long a, long long b) {
	//0^0 = 1
	if (b == 0) {
		return 1;
	}
	if (a == 0) {
		return 0;
	}

	long long result = 1;
	//iterationCount starts from 0 
	while (b != 0) {
		//Check if in b(2) exists 2^iterationCount
		if (b % 2 == 1){
			result *= a;
		}
		b /= 2;
		//3^1 3^2 3^4 3^8 3^16 3^32 ... 3^(2^iterationCount)
		a *= a;
	}
	return result;
}
```
# Playthrough
> `a = 3`  
> `b = 13`  
> b(2) = 1101

| b(2) |       a       |  result   |
| ---: | :-----------: | --------- |
| 1101 | 3^1 = 3^(2^0) | 1 * 3^1   |
|  110 | 3^2 = 3^(2^1) | 3         |
|   11 | 3^4 = 3^(2^2) | 3 * 3^4   |
|    1 | 3^8 = 3^(2^3) | 243 * 3^8 |
|    0 |       -       | -         |

> Result = 1594323