# Pointer
> Változó memóriacímét tartalmazó változó
```c++
point *p = &a, *q = &b;
p = &b; q = &a;
```
# Reference
> const pointer
```c++
point &p=a, &q=b;
```
```c++
void foo(const point &bar){
	cout << bar.x;
}
point a;
foo(a);
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
# Felépítés
```c++
#define _GLIBCXX_DEBUG //Codeblocks esetén
#include <bits/stdc++.h> //Codeblocks esetén
#include <iostream> //más esetén
#include <algorithm> //más esetén

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	//Input

	//Process

	//Output

	cout<<endl;
	return 0;
}
```
`#define _GLIBCXX_DEBUG` lassítást okozhat, beküldés előtt érdemes kivenni
# IO
> Alap
```c++
cin.sync_with_stdio(false);
cin.tie(nullptr);
cin >> var1 >> var2;
cout << var2 << " " << var1 << '\n';
```
> Leggyorsabb, nem feltétlen kell, de sokat gyorsít
> Ha lokálisan Windowson dolgozunk: `getchar();`
```c++
#define READ c = getchar_unlocked();
int read() {
	char READ;
	while (c <= ' ') {
		READ;
	}

	bool negative = false;
	if (c == '-') {
		negative = true;
		READ;
	}

	int number = 0;
	while (c > ' ') {
		number = 10 * number + (c - '0');
		READ;
	}
	if (negative) {
		return -number;
	}
	return number;
}
#undef READ
int var1=read();
```
# Struktúrák
```c++
struct point{
	long long x, y;
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
|----------|------|
| begin    | 1    |
| end      | 1    |
| back     | 1    |
| rbegin   | 1    |
| rend     | 1    |
| distance | 1    |
| next     | 1    |
| prev     | 1    |
# STD Típusok
## `stack`
> Csak az utolsó elemet lehet megnézni, kivenni

| Property | Time |
|----------|------|
| push     | 1    |
| empty    | 1    |
| top      | 1    |
| pop      | 1    |
## `set`
> Binary search tree

|    Property    |       Time        |
|----------------|-------------------|
| insert         | logN              |
| lower_bound    | logN              |
| upper_bound    | logN              |
| find           | logN              |
| size           | 1                 |
| erase(it)      | 1                 |
| erase(val)     | logN              |
| erase(it, it2) | distance(it, it2) |
| clear          | N                 |
> `find` returns `.end()` iterator if value could not be found
## `multiset`, ...
[R]TODO
## `unordered_set`, `unordered_map`
[R]TODO
## `list`
> Double linked list

|  Property  | Time |
|------------|------|
| front      | 1    |
| back       | 1    |
| assign     | N    |
| pop_front  | 1    |
| pop_back   | 1    |
| push_front | 1    |
| push_back  | 1    |
| insert     | 1    |
> `erase` returns iterator to next element
## `vector`
> Tömb

| Property  | Time |
|-----------|------|
| assign    | N    |
| resize    | N    |
| back      | 1    |
| push_back | 1    |
| size      | 1    |
| pop_back  | 1    |
```c++
for (auto item : array){
}
for (auto& item : array){
}
```
## `queue`
> Csak az első elemet lehet megnézni, kivenni

| Property | Time |
|----------|------|
| push     | 1    |
| empty    | 1    |
| front    | 1    |
| pop      | 1    |
## `priority_queue`
> Values ordered by priority  
> Values order according to `<` 
> `top()` will return values reversed because(?) it uses `heap`
```c++
struct point{
	long long x,y;
	bool operator<(point other) const{
		return x>other.x;
	}
};
```
## `deque`
> double ended queue: `vector` kiegészítve `push_front` és `pop_front` függvényekkel  
> Vector **gyorsabb**.

| Property   | Time |
|------------|------|
| empty      | 1    |
| size       | 1    |
| front      | 1    |
| back       | 1    |
| push_back  | 1    |
| push_front | 1    |
| pop_back   | 1    |
| pop_front  | 1    |
## `map`
> Associative array
> Elem deklarálás: `m["foo"] = m["foo"]`  
> Iterátor `pair<,>`-t ad vissza  

| Property | Time |
|----------|------|
| find     | 1    |
| []       | 1    |
| front    | 1    |
| pop      | 1    |
> `find` returns `.end()` iterator if value could not be found
> `find` returns pair<iterator, value>
## `multimap`
[R]TODO
## `pair`
make_pair(first, second);
## `array`
[R]TODO
# STD Függvények
## `min`
## `max`
## `sort`
> `strict weak`: ugyanazon tulajdonságokra `false`-t kell adni  
```c++
sort(v.begin(), v.end(), [](point a, point b) {
	if (
		a.y < b.y ||
		a.y == b.y &&
		a.x < b.x
	) {
		return true;
	}
	return false;
});
```
## `reverse`
## `unique`
> Gyorsabb ha előtte rendezzük az elemeket
```c++
auto it = unique(v.begin(), v.end());   
v.resize(distance(v.begin(),it));
```
## `swap`
## `__gcd`
> Linux only
> Legnagyobb közös osztó
## `lower_bound`
## `upper_bound`
## `next_permutation`
## `prev_permutation`
## `__builtin_popcount`
> Linux only
> Beállított bit-ek egy int-ben
## `__builtin_ctz`
> Linux only
> Jobb oldalról az első beállított bit indexe
## `__builtin_clz`
> Linux only
> Bal oldalról az első beállított bit indexe
# Futásidő
| Big O notation | Time | Input Limit/s |
|----------------|------|---------------|
| Constant       | 1    |       -       |
| Sublinear      | lgN  |      Big      |
| Linear         | N    |     100M      |
| ?              | NlgN |      5M       |
| Quadratic      | N^2  |      10K      |
| Cubic          | N^3  |      450      |
| ?????          | N^4  |      100      |
| Exponential    | 2^N  |      27       |
| Factorial      | N!   |      11       |
