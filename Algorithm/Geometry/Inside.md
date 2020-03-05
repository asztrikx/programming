# Triangle
## Code
```c++
bool insideTriangle(point a, point b, point c, point p) {
	if (between(a, b, p) || between(b, c, p) || between(c, a, p)) {
		return true;
	}
	if (
		direction(a, b, p) == direction(b, c, p) &&
		direction(a, b, p) == direction(c, a, p)
	) {
		return true;
	}
	return false;
}
```