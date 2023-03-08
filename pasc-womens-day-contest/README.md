# PASC Women's Day Contest

## Problem A:
- check parity of sum of first and last digit of a number

## Problem B:
- prefix sums over some condition in the array, queries to answer valid indices computed using prefix sums

## Problem C:
- finding 3 disjoint but one-after-other subarrays with sums f[0], f[1] and f[2]
- since, given array had positive values we use binary search to find some valid endpoints and jump to next required array accordingly
- for some starting point i, there can be atmost 1 valid tuple of subarray endpoints this is true because once we fix the starting point, sum continue to increase (B[i] > 0)
- hence it is monotonous and we can apply binary search

## Problem D:
- greedy solution
- we needed add some values to get to the target using minimum cost
- it was optimal to take the values which reach the target as quickly as possible and also had least penalty
- hence it was optimal to add those values in increasing order of cost
- i.e over sorted sequence

## Problem E:
- again, monotonous function
- f: length of subarray with atleast M pairs with condition: A[i] + A[j] = K
- also, array had distinct elements
- hence, any index i shall only pair with atmost 1 index j
- induces that extending subarray to the right by 1, increases the number of pairs by atmost 1 hence we can binary search over the length of subarray
- if subarray length X has M pairs, then length X+1, X+2, ... will have more pairs (> M)
- greater or equal pairs than the previous length
- sliding window technique used along with maintaining frequency and count of pairs

## Problem F:
- A[i] % pow(2, P[i]) == 0
- pow(2, 3) = 8
- for this, A[i] belongs to {0, 8, 16, 24, 32, 40, ..}
- pow(2, 4) = 16
- for this, A[i] belongs to {0, 16, 32, 48, ..}
- create permutation in order of decreasing of P[i]
- multiply choices for each P[i] going from highest to lowest, decrease frequency of A[i] counted in multiple powers
- used mod int for modular integer computation
