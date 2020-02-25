# Definitions
- `array` = `ordered set`
	> First element's index is 0  
	> Every other element's index is the one before it + 1  
	> Notation of indexed array `A`.
	- A0
	- Ai
	- A(i + 1)
- `vector` = `array`
- `subsequence`
	> Let `A` be the `array`  
	> Let `SS` be the `subsequence`  
	> `Index of SSi` in A is `smaller than SS(i + 1)`'s  
	```
	A = (1, 2, 3, 4)
	SS = (1, 2, 3, 4)
	SS = (1, 2, 3)
	SS = (1, 3)
	SS = (4, 3) //Error
	```
- `subarray`
	> Let `A` be the `array`  
	> Let `SA` be the `subarray`  
	> `SA0` can be any value of A  
	> `Index of SAi` (i > 0) in A `is` the `index of SA(i - 1)` in A `+ 1`   
	```
	A = (1, 2, 3, 4)
	SA = (1, 2, 3, 4)
	SA = (1, 2, 3)
	SA = (3, 4)
	SA = (1, 3) //Error
	SA = (4, 3) //Error
	```