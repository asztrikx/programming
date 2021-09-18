# Code
```c++
bool between(Point start, Point end, Point p) {
	if (direction(start, end, p) != STRAIGHT) {
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
