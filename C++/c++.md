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

```c++
for (auto item : array){
}
for (auto& item : array){
}

{2,4,564,65}
```
