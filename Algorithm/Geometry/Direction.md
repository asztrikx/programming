# Code
```c++
// base->from->to
int direction(point base, point from, point to) {
	from = from - base;
	to = to - base;
	ll area = from.y * to.x - from.x * to.y;
	if (area > 0) {
		return 1; //balra
	} else if (area < 0) {
		return -1; //jobbra
	}
	return 0;
}
```
