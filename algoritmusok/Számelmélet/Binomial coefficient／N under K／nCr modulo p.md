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

b ^ (p - 1) ≡ 1
b * b^(p - 2) ≡ 1

b * b^-1 ≡ b * b^(p - 2)
b^-1 ≡ b^(p - 2)

n! / (k! * (k - n)!) ≡ n! * (k! * (k - n)!)^(p - 2)
```