# Code
```c++
// base->from->to
enum Direction {
	RIGHT = 1,
	LEFT = -1,
	STRAIGHT = 0,
};


// base->from->to
Direction direction(Point base, Point from, Point to) {
	from = from - base;
	to = to - base;
	ll area = from.y * to.x - from.x * to.y;
	if (area > 0) {
		return RIGHT;
	} else if (area < 0) {
		return LEFT;
	} else {
		return STRAIGHT;
	}
}
```
[Playground](https://www.geogebra.org/m/dygr7xjt)
