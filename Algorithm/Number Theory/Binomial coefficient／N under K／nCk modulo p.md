# Problem
> Dividing large numbers causes overflow?  
# Fermat's Little Theorem
> a^(p - 1) ≡ 1

# Thesis
> Let `p be a positive prime number`  
> a ≡ b means a % p = b % p  
> n! / (k! * (k - n)!) ≡ n! / quickpow(k! * (k - n)!, p - 2) solves the problem  

# Proof
> Multiplication does not cause overflow?
```
n! / (k! * (k - n)!) ≡ n! * (k! * (k - n)!)^-1

b / b = 1 ≡ 1
b * b^-1 ≡ 1

b^(p - 1) ≡ 1
b * b^(p - 2) ≡ 1

b * b^-1 ≡ b * b^(p - 2)
b^-1 ≡ b^(p - 2)

n! / (k! * (k - n)!) ≡ n! * (k! * (k - n)!)^(p - 2)
```

# Code
```c++
const p;
// faktorialis MOD-os maradéka, ha a < MOD
// ha a >= MOD, akkor 0 lesz a maradék, ami elrontja az n alatt a k számítását
vector<int> factorialS;
long long factorial(long long a) {
    assert(a < p);//[R] ?
    if (a == 0) {
		return 1;
	}
	if (factorialS[a] != -1) {
		return factorialS[a];
	}
    return factorialS[a] = a * factorial(a - 1) % p;
}

long long quickpow(int a, int b) {//[R] ?
    a = a%MOD;
    if (a == 0) return 0;
    b = b%(MOD-1); // Kis Fermat-tétel miatt
    int val = 1;
    for (int i = (1<<30); i; i>>=1) { // minden bitre
        val = 1LL * val * val % MOD;
        if (i&b)
            val = 1LL * val * a % MOD;
    }
    return val;
}


long long ncr(int n, int r) {
    assert(0 <= r && r <= n && n < p); // az utolso nagyon fontos //[R] ?
	// moduláris inverz. assert(1LL*a*modinv(a,MOD) % MOD == 1); //[R] ?
    long long n = factorial(n);
    long long r = factorial(r);
    long long nr = factorial(n - r);

    return n * quickpow(r * nr % p, p - 2);
}
```
