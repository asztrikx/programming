# Includes
> First part of the source file is including prewritten code  
> Syntax `#include <name>`
```c++
#include <iostream>
#include <algorithm>
#include <vector>
```

# Namespaces
> Namespaces separate functions with the same name  
> Sytanx `namespace::function`  
> E.g. robot::jump() and character::jump()  
> `std` namespace's functions are often used so we take it out from this separation  
```c++
using namespace std;
```

# Entrance point
> The function which is called after c++ finished setting up its environment  
```c++
int main() {
	return 0;
}
```

# Debugging
> assert(false); stops the program
```c++
#include <cassert>
```
```c++
assert(a != 0);
```
> Local testing messages
```c++
#ifdef _WIN32 
#define iff if(true)
#else
#define iff if(false)
#endif
```
```c++
iff cout << "This happened" << endl;
```

# Data types
- Text
	- `string`
- Number
	- Integer
		- Based on size
            - |   Syntax    |  Size  |
              | ----------- | -----: |
              | `char`      |  8 bit |
              | `short`     | 16 bit |
              | `int`       | 32 bit |
              | `long long` | 64 bit |
			- long long
				> After includes use
				```
				#define ll long long
				```
				```
				ll a = 1 << 60;
				```
		- Based on range
            - |           Syntax           |            Range            |
              | -------------------------- | --------------------------- |
              | `unsigned`                 | [-2^(x - 1), 2^(x - 1) - 1] |
              | `signed`  (can be ommited) | [0, 2^x - 1]                |
		- E.g. `unsigned int name;`
	- Non-integer
		> Avoid unless is specifically asked
		- `double`
		- `float`
- Complex
	- `struct`
		- Declaration
			> Outside of functions
			```c++
			struct name {
			};
			```
		- Addig different types
			```c++
			struct name {
				int name2, name3;
				string name3;
			};
			```
		- Addig operators between structs with the same time
			```c++
			struct point {
				long long y, x;
				point operator-(point other) {
					return { y - other.y, x - other.x};
				}
			};
			```
			```c++
			point p = {6, 7}, q = {-2, 3};
			point r = p - q;
			assert(r.x == 8 && r.y == 4);
			```
	- `class`

# Pointer
> Variable containing the memory address of another variable  
```c++
point* p = &a;
assert(p->x == a.x && p->y == a.y);
p = &b;
assert(p->x == b.x && p->y == b.y);
```

# Reference
> == `const` pointer
```c++
point& p = a;
assert(p.x == a.x && p.y == a.y);
p = &b; //Error
```

# Array
> [R] TODO what is it  
> Only use if vector would be redeclared many times  
```c++
int b[6];
int a[] = { 5, 4, 3 };
```

# IO
> Basic
```c++
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	//Input
	int var1;
	string var2;
	cin >> var1 >> var2; //153 duck

	//Output
	cout << var2 << " " << var1 << endl; //duck 153
	return 0;
}
```

> Fastest, usually not needed  
> For local tests on Windows use: `getchar();`  
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
```
```c++
int var1 = read();
```

# Binary shift
[R] TODO  
ll a = 1LL << 60 m

# Struct hashing
> For indexing `set` or `map` with a struct
```c++
struct point {
	int y, x;

	bool operator==(point other) const {
		return y == other.y && x == other.x;
	}
};

namespace std {
	template<> struct hash<point> {
		size_t operator()(const point& p) const {
			auto hasher = hash<int>{};
			auto hashY = hasher(p.y);
			auto hashX = hasher(p.x);
			return hashY ^ (hashX << 1);
		}
	};
}
```

# Overall structure
```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	//Input

	//Process

	//Output

	cout << endl;
	return 0;
}
```

# int to string
- ```c++
  #include <string>
  ```
  ```c++
  string s = to_string(187);
  ```
- ```c++
  #include <sstream>
  ```
  ```c++
  stringstream ss;
  ss << 187;
  string s = ss.str();
  ```

# Bultin classes
[R] In depth function uses  
## Iterátorok
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
> Much slower than vector  

|  Property  | Time |
|------------|------|
| front      | 1    |
| back       | 1    |
| resize     | N    |
| assign     | N    |
| pop_front  | 1    |
| pop_back   | 1    |
| push_front | 1    |
| push_back  | 1    |
| insert     | 1    |
> `erase` returns iterator to next element
## `vector`
> Tömb  
> Pass by value [R] TODO  

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
struct point {
	long long y, x;
	bool operator<(point other) const {
		return x > other.x;
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

# Builtin functions
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
[R] reverse(begin(), end());

## `unique`
> Gyorsabb ha előtte rendezzük az elemeket
```c++
auto it = unique(v.begin(), v.end());   
v.resize(distance(v.begin(), it));
```

## `swap`
[R] Iterators swap(*it1, *it2)

## `__gcd`
> Only on Linux  

## `lower_bound`

## `upper_bound`

## `next_permutation`

## `prev_permutation`

## `__builtin_popcount`
> Only on Linux
> Beállított bit-ek egy int-ben

## `__builtin_ctz`
> Only on Linux
> Jobb oldalról az első beállított bit indexe

## `__builtin_clz`
> Only on Linux
> Bal oldalról az első beállított bit indexe
