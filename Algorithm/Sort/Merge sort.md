# Thesis
- [R] TODO

# Proof
- [R] TODO

# Example
- [R] TODO

# Code
```c++
vector<int> numberS /*= { -1, 99, 4, 1, 55, -7, 3 }*/;
vector<int> mergeArray(numberS.size());

void merge(int start, int middle, int end) {
	for (int i = start; i <= end; i++) {
		mergeArray[i] = numberS[i];
	}

	int index = start;
	int first = start;
	int second = middle + 1;
	while (first <= middle && second <= end) {
		if (mergeArray[first] < mergeArray[second]) {
			numberS[index] = mergeArray[first];
			++first;
		} else {
			numberS[index] = mergeArray[second];
			++second;
		}
		++index;
	}
	while (first <= middle) {
		numberS[index] = mergeArray[first];
		++first;
		++index;
	}
	while (second <= end) {
		numberS[index] = mergeArray[second];
		++second;
		++index;
	}
}

void mergesort(int start, int end) {
	if (start == end) {
		return;
	}

	int middle = (start + end) / 2;
	mergesort(start, middle);
	mergesort(middle + 1, end);
	merge(start, middle, end);
}
```

# Problems
1. [mester/NT, OKTV, IOI Válogató/NT Online 2018 ∕ 19 1. forduló/2. Középső életkorú](https://github.com/asztrikx/mester-linux/blob/master/NT%2C%20OKTV%2C%20IOI%20V%C3%A1logat%C3%B3/NT%20Online%202018%20%E2%88%95%2019%201.%20fordul%C3%B3/2.%20K%C3%B6z%C3%A9ps%C5%91%20%C3%A9letkor%C3%BA%20%20%20%20__-100/feladat.pdf)