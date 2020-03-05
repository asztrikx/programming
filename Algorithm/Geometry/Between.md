# Code
```c++
bool between(point start, point end, point a) {
	if (direction(start, end, a) != 0) {
		return false;
	}
	if (
		(
			a.y < end.y && a.y > start.y ||
			a.y < start.y && a.y > end.y
		) || (
			a.x < end.x && a.x > start.x ||
			a.x < start.x && a.x > end.x
		)
	) {
		return true;
	}
}
```