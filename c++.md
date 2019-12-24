# Editor
## Codeblocks
# Pointer
> Változó memóriacímét tartalmazó változó
```c++
point *p=&a, *q=&b;
p=&b; q=&a;
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
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

int main()
{
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
Alap
```c++
cin.sync_with_stdio(false);
cin.tie(nullptr);
cin >> var1 >> var2;
cout << var2 << " " << var1 << '\n';
```
Leggyorsabb, nem feltétlen kell, de sokat gyorsít
```c++
#define READ c = getchar_unlocked();
int read(){
	char READ;
	while(c<=' '){
		READ;
	}
	bool negative=false;
	if(c=='-'){
		negative=true;
		READ;
	}
	int number;
	do{
		number=(number<<3)+(number<<1)+c-'0';
		READ;
	}while(c>' ')
	if(negative){
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
> Bináris keresőfa

| Property      | Time |
|---------------|------|
| insert        | logN |
| lower_bound   | logN |
| upper_bound   | logN |
| find          | logN |
| size          | 1    |
| erase(it)     | 1    |
| erase(val)    | logN |
| erase(it, it) | N    |
| clear         | N    |
## `multiset`, ...
[R]TODO
## `unordered_set`, `unordered_map`
[R]TODO
## `list`
[R]TODO
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
> Prioritás szerint rendezett elemek  
> Struktúrák `<` szerint rendeződnek  
> Kivétel `heap` miatt fordított sorrendben lesz
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
> Asszociatív indexelésű tömb  
> Elem deklarálás: `m["foo"]=m["foo"]`  
> Iterátor `pair<,>`-t ad vissza  

| Property | Time |
|----------|------|
| find     | 1    |
| []       | 1    |
| front    | 1    |
| pop      | 1    |
## `multimap`
[R]TODO
## `pair`
[R]TODO
make_pair(first, second);
## `array`
[R]TODO
# STD Függvények
## `min`
## `max`
## `sort`
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
## `reverse`
## `unique`
> Gyorsabb ha előtte rendezzük az elemeket
```c++
auto it = unique(v.begin(), v.end());   
v.resize(distance(v.begin(),it));
```
## `swap`
## `__gcd`
> Legnagyobb közös osztó
## `lower_bound`
## `upper_bound`
## `next_permutation`
## `prev_permutation`
## `_builtin_popcount`
> Beállított bit-ek egy int-ben
## `__builtin_ctz`
> Jobb oldalról az első beállított bit indexe
## `__builtin_clz`
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