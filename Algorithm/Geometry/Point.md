# Code
```c++
struct point {
	ll y, x;
	
	point operator-(point other) {
		return { y - other.y, x - other.x };
	}
};
```