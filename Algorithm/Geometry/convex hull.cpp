#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG

using namespace std;

struct point{
	long long x,y;
	point operator-(point other){
		point p;
		p.x = x-other.x;
		p.y = y-other.y;
		return p;
	}
};
vector<point> pointS;

int direction(point a, point b, point c){
	b = b-a;
	c = c-a;
	long long area = c.x*b.y - b.x*c.y;
	if(area < 0){
		return -1;
	} else if(area > 0){
		return 1;
	}
	return 0;
}

bool intersect(point a, point b, point c){
    if(
		a.x < b.x && b.x < c.x ||
		c.x < b.x && b.x < a.x ||
		a.y < b.y && b.y < c.y ||
		c.y < b.y && b.y < a.y
	){
		return true;
	}
	return false;
}

void reversee(){
	int index = pointS.size() - 2;
	while(direction(pointS[0], pointS[pointS.size()-1], pointS[index]) == 0){
		--index;
	}
	++index;
	reverse(pointS.begin() + index ,pointS.end());
}

void base(){
	int minIndex = 0;
	for(int i=1; i<pointS.size(); i++){
		if(
			pointS[minIndex].y > pointS[i].y ||
			pointS[minIndex].y == pointS[i].y &&
			pointS[minIndex].x > pointS[i].x
		){
			minIndex = i;
		}
	}
	point temp = pointS[0];
	pointS[0] = pointS[minIndex];
	pointS[minIndex] = temp;
}

int main(){
	//Input
	int n;
	cin >> n;

	pointS.resize(n);
	for(int i=0; i<n; i++){
		cin >> pointS[i].x >> pointS[i].y;
	}

	//Process
	base();
	sort(pointS.begin()+1, pointS.end(), [](point a, point b){
		int dir = direction(pointS[0], a, b);
		if(dir == 0){
			return intersect(pointS[0], a, b);
		}
		return dir == -1;
	});
	reversee();

	stack<int> result;
	result.push(0);
	result.push(1);
	int prev, prevprev;
	for(int i=2; i<n; i++){
		if(direction(pointS[i-2], pointS[i-1], pointS[i]) != 1){
			result.push(i);
			continue;
		}
		result.pop();
		prev = result.top(); result.pop();
		prevprev = result.top(); result.pop();
		while(!result.empty()){
			if(direction(pointS[prevprev], pointS[prev], pointS[i]) == -1){
				result.push(prevprev);
				result.push(prev);
				result.push(i);
				break;
			} else {
				prev = prevprev;
				prevprev = result.top(); result.pop();
			}
		}
	}

	//Output
	stack<int> resultReversed;
	while(!result.empty()){
		resultReversed.push(result.top()); result.pop();
	}
	while(!resultReversed.empty()){
		int index = resultReversed.top(); resultReversed.pop();
		cout << pointS[index].x << " " << pointS[index].y << '\n';
	}

	return 0;
}
