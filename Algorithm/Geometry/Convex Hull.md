# Weak
## Code
```c++
vector<point> convexhull;
void convexhullBuild() {
	if (pointS.size() <= 2) {
		convexhull = pointS;
		return;
	}

	//A point from which all points are vertically (or horizontally) at one side
	auto itMin = pointS.begin();
	for (auto it = pointS.begin() + 1; it != pointS.end(); it++) {
		if (
			itMin->x > it->x ||
			itMin->x == it->x && itMin->y > it->y
		) {
			itMin = it;
		}
	}
	swap(*pointS.begin(), *itMin);

	sort(pointS.begin() + 1, pointS.end(), [](point a, point b) {
		int d = direction(pointS[0], a, b);
		if (d == 0) {
			return between(pointS[0], b, a);
		}
		return d == -1;
	});

	//Reverse all points which are in one line with last point
	int index = pointS.size() - 2;
	while (direction(pointS[0], pointS[pointS.size() - 1], pointS[index]) == 0) {
		--index;
	}
	++index;
	reverse(pointS.begin() + index, pointS.end());

	stack<int> st;
	st.push(0);
	st.push(1);
	st.push(2);
	for (int i = 3; i < pointS.size(); i++) {
		int last = st.top(); st.pop();
		while (direction(pointS[st.top()], pointS[last], pointS[i]) == 1) {
			last = st.top(); st.pop();
		}
		st.push(last);
		st.push(i);
	}

	convexhull.resize(st.size());
	for (int i = convexhull.size() - 1; i >= 0; i--) {
		convexhull[i] = pointS[st.top()]; st.pop();
	}
}
```
# Strong
## Code
[R] TODO
