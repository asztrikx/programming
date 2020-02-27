# Array
## Thesis
> Let `A` be an `array of numbers`  
> All sum from index i to j (i <= j) can be aquired in O(N)

## Proof
> We are going to use DP to calculate the sum from 0 to i  
``` 
DPi = DP(i - 1) + Ai

DPj - DPi + Ai
= ((A0 + A1 + ... + Ai + ... + Aj) - (A0 + A1 + ... + Ai)) + Ai
= (A(i + 1) + ... + Aj) + Ai
= Ai + ... + Aj
```

## Example
|       |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
| ----- | --- | --- | --- | --- | --- | --- | --- | --- |
| Ai  | 2   | -5  | 3   | 100 | 14  | 0   | 0   | 7   |
| DPi | 2   | -3  | 0   | 100 | 114 | 0   | 0   | 121 |

> i = `1`, j = `7` → 121 - (-3) + (-5) = `119`

# Matrix
i j = x y closer
k l = x y further
DPk,l - DPi,l - DPk,j + DPi,j
[R] TODO