# Code
```c++
bool intersect(Line a, Line b) {
	if (
		a.start == b.start || a.start == b.end ||
		a.end == b.start || a.end == b.end
	) {
		return true;
	}
	if (between(a.start, a.end, b.start) || between(a.start, a.end, b.end)) {
		return true;
	}
	if (between(b.start, b.end, a.start) || between(b.start, b.end, a.end)) {
		return true;
	}
	return direction(a.start, a.end, b.start) * direction(a.start, a.end, b.end) < 0 &&
		   direction(b.start, b.end, a.start) * direction(b.start, b.end, a.end) < 0;
}
```