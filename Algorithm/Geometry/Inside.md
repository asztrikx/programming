# Any convex polygon e.g.: Triangle
## Code
```c++
bool insideTriangle(Point a, Point b, Point c, Point p) {
	if (p == a || p == b || p == c) {
		return true;
	}
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

# Any polygon
> Points should be sorted [R] TODO
## Code
```c++
vector<Point> pointS /*= {
	{ 2, 0 },
	{ 1, 0 },
	{ 0, 1 },
	{ 1, 2 },
	{ 0, 3 },
	{ 2, 5 },
	{ 4, 5 },
}*/;
bool inside(Point p) {
	ll maxxY = -1;
	for (auto item : pointS) {
		maxxY = max(maxxY, item.y);
	}

	line l = { p, { maxxY + 1, p.x + 1} };

	pointS.push_back(pointS[0]);
	int count = 0;
	for (int i = 0; i < pointS.size() - 1; i++) {
		if (intersect(l, { pointS[i], pointS[i + 1] })) {
			++count;
		}
		if (p == pointS[i] || p == pointS[i + 1]) {
			pointS.pop_back();
			return true;
		}
		if (between(pointS[i], pointS[i + 1], p)) {
			pointS.pop_back();
			return true;
		}
	}
	pointS.pop_back();
	if (count % 2 != 0) {
		return true;
	}
	return false;
}
```