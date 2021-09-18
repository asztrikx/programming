# Point
## Code
```c++
struct point {
	ll y, x;
	
	point operator-(point other) {
		return { y - other.y, x - other.x };
	}
	bool operator==(point other) {
		return y == other.y && x == other.x;
	}
};
```

# Line
## Code
```c++
struct line {
	point start, end;
};
```