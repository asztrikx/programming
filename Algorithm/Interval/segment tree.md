# Thesis
- [R] TODO
can be used to calc sum, min, max

# Proof
- [R] TODO

# Example
- [R] TODO

# Code
```c++
vector<int> numberS /*= { -4,2,47,-8 }*/;
vector<int> segmenttree;

void segmenttreeUpdateRecursion(int node, int left, int right, int index, int value) {
	if (left == right) {
		segmenttree[node] = value;
		return;
	}

	int middle = (left + right) / 2;
	if (index <= middle) {
		segmenttreeUpdateRecursion(node * 2, left, middle, index, value);
	} else {
		segmenttreeUpdateRecursion(node * 2 + 1, middle + 1, right, index, value);
	}
	segmenttree[node] = segmenttree[node * 2] + segmenttree[node * 2 + 1];
}

void segmenttreeUpdate(int index, int value) {
	segmenttreeUpdateRecursion(1, 0, numberS.size() - 1, index, value);
}

int segmenttreeSumRecurion(int node, int left, int right, int start, int end) {
	if (start > end) {
		return 0;
	}
	if (left == start && right == end) {
		return segmenttree[node];
	}

	int middle = (left + right) / 2;
	int leftSum = segmenttreeSumRecurion(node * 2, left, middle, start, min(end, middle));
	int rightSum = segmenttreeSumRecurion(node * 2 + 1, middle + 1, right, max(start, middle + 1), end);
	return leftSum + rightSum;
}

int segmenttreeSum(int start, int end) {
	return segmenttreeSumRecurion(1, 0, numberS.size() - 1, start, end);
}

void segmenttreeBuildRecursion(int root, int left, int right) {
	if (left == right) {
		segmenttree[root] = numberS[left];
		return;
	}

	int middle = (left + right) / 2;
	segmenttreeBuildRecursion(root * 2, left, middle);
	segmenttreeBuildRecursion(root * 2 + 1, middle + 1, right);
	segmenttree[root] = segmenttree[root * 2] + segmenttree[root * 2 + 1];
}

void segmenttreeBuild() {
	segmenttree.resize(4 * numberS.size());
	segmenttreeBuildRecursion(1, 0, numberS.size() - 1);
}
```

# Problems
1. https://cp-algorithms.com/data_structures/segment_tree.html