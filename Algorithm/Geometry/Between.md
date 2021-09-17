# Code
```c++
bool between(point start, point end, point p) {
	if (direction(start, end, p) != 0) {
		return false;
	}
	return (
		p.y < end.y && p.y > start.y ||
		p.y < start.y && p.y > end.y
	) || (
		p.x < end.x && p.x > start.x ||
		p.x < start.x && p.x > end.x
	);
}
```
