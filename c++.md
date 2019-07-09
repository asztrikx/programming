# Editor
## Codeblocks
# Pointers
```c++
void foo(string* _bar){ 
	string& bar = *_bar;
	cout << bar.property;
}
```
```c++
void foo(string* bar){
	cout << bar->property
}
```
# Adattípusok
- Terjedelem
	```c++
	int i; //[-2^(x-1), 2^(x-1)-1]
	unsigned int i; //[0, 2^x-1]
	```
- Méret
	- char `8bit`
	- short `16bit`
	- int `32bit`
	- long long `64bit`
		```c++
		#define ll long long
		```
# Felépítés
```c++
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	//Input

	//Process

	//Output

	return 0;
}
```
# IO
```c++
cin >> var1 >> var2;
cout << var2 << " " << var1 << '\n';
```
# Struktúrák
```c++
struct point{
	ll x, y;
	int index;
	point operator-(point other){
		point p;
		p.x=x-other.x;
		p.y=y-other.y;
		return p;
	}
};
```
# Iterátorok
> Adott helyen lévő érték `pointer`-e

| Property | Time |
| --- | --- |
| begin | 1 |
| end | 1 |
| back | 1 |
| rbegin | 1 |
| rend | 1 |
| distance | 1 |
| next | 1 |
| prev | 1 |
# STD Típusok
## stack
> Csak az utolsó elemet lehet megnézni, kivenni

| Property | Time |
| --- | --- |
| push | 1 |
| empty | 1 |
| top | 1 |
| pop | 1 |
## set
> Bináris keresőfa

| Property | Time |
| --- | --- |
| insert | logN |
| lower_bound | logN |
| upper_bound | logN |
| find | logN |
| size | 1 |
| erase(it) | 1 |
| erase(val) | logN |
| erase(it, it) | N |
| clear | N |
## multiset, ...
[R]TODO
## unordered_set, unordered_map
[R]TODO
## list
[R]TODO
## vector
> Tömb

| Property | Time |
| --- | --- |
| assign | N |
| resize | N |
| back | 1 |
| push_back | 1 |
| size | 1 |
| pop_back | 1 |
```c++
for (auto item : array){

}
```
## queue
> Csak az első elemet lehet megnézni, kivenni

| Property | Time |
| --- | --- |
| push | 1 |
| empty | 1 |
| front | 1 |
| pop | 1 |
## priority_queue
> Prioritás szerint rendezett elemek  
> Struktúrák `operator<` szerint rendeződnek  
> Kivétel `heap` miatt fordított sorrendben lesz  
## deque
[R]TODO
## map
> Asszociatív indexelésű tömb  
> Elem deklarálás: `m[0]=m[0]`  
> Iterátor `pair<,>` ad vissza  

| Property | Time |
| --- | --- |
| find | 1 |
| 'insert' | 1 |
| front | 1 |
| pop | 1 |
## multimap
[R]TODO
## pair
[R]TODO
## array
[R]TODO
# STD Függvények
## min
## max
## sort
> 2 dolog közös sortolása 3. index tartalmú tömbbel  
> Ha tudnunk kell az eredeti indexeket, akkor propertyként mentsük le  
> `strict weak`: ugyanazon tulajdonságokra `false`-t kell adni  
```c++
sort(v.begin(), v.end(), [](point a, point b){
	if(
		a.y<b.y ||
		a.y==b.y &&
		a.x<b.x
	){
		return true;
	}
	return false;
});
```
## reverse
## unique
```c++
auto it = unique(v.begin(), v.end());   
v.resize(distance(v.begin(),it));
```
## swap
# Futásidő
| Big O notation | Time | Input Limit/s |
| --- | --- | --- |
| Constant | 1 | - |
| Sublinear | logN | Big |
| Linear | N | 100M |
|  | NlogN | 5M |
| Quadratic | N^2 | 10K |
| Cubic | N^3 | 450 |
| Exponential | 2^N | 27 |
| Factorial | N! | 11 |