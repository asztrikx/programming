# Point
## Code
```c++
struct Point {
	ll y, x;
	
	Point operator-(Point other) {
		return { y - other.y, x - other.x };
	}
	bool operator==(Point other) {
		return y == other.y && x == other.x;
	}
};
```

# Line
## Code
```c++
struct Line {
	Point start, end;
};
```