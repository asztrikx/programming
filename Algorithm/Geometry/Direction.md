# Code
```c++
int direction(point base, point from, point to) {
	from = from - base;
	to = to - base;
	ll area = from.y * to.x - from.x * to.y;
	if (area > 0) {
		return 1;
	} else if (area < 0) {
		return -1;
	}
	return 0;
}
```