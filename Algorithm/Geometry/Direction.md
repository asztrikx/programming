# Code
```c++
// base->from->to
int direction(point base, point from, point to) {
	from = from - base;
	to = to - base;
	ll area = from.y * to.x - from.x * to.y;
	if (area > 0) {
		return 1; //jobbra
	} else if (area < 0) {
		return -1; //balra
	}
	return 0;
}
```
[Playground](https://www.geogebra.org/m/dygr7xjt)
