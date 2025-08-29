class Solution {
public:
    long long flowerGame(int n, int m) {
        return (1ll* n*m)/2;
    }
};

/*

Alice wins iff the total number of flowers T = x + y is odd.
So we just need to count the number of pairs (x,y) with 1 ≤ x ≤ n, 1 ≤ y ≤ m such that x + y is odd. That number equals ⌊n*m / 2⌋, which is exactly what the code returns via (1ll * n * m) / 2.

Why Alice wins ⇔ x + y is odd

Each turn, a player removes exactly one flower (from either lane). So after one turn the total T decreases by 1.
The game ends when T reaches 0. Therefore the game lasts exactly T turns.
Alice moves on turns numbered 1, 3, 5, ... (odd turns). Bob moves on 2, 4, 6, ... (even turns).
If T is odd, the final move is an odd-numbered turn → Alice makes it → Alice wins.
If T is even, the final move is even → Bob makes it → Alice loses.
So the winning condition depends only on the parity of x+y.



Imagine the n×m grid of all pairs (x,y) and look at parity of x+y. Parity alternates like a chessboard along each row and column.

If n*m is even, the grid has an even number of cells so exactly half are odd-sum and half are even-sum → count = n*m/2.

If n*m is odd, the grid has one extra cell. In that case the counts differ by exactly 1, so the count of odd-sum pairs is ⌊n*m/2⌋.

Either way the count = ⌊ n*m / 2 ⌋.

(Equivalently, algebra shows odd_x*even_y + even_x*odd_y = floor(n*m/2) because the difference between odd-sum and even-sum counts is (n%2)*(m%2).)


1ll * n * m casts/multiplies to long long so the product n*m is computed in 64-bit arithmetic. This is important because n*m may reach 10^10 (for n,m ≤ 10^5), which overflows 32-bit int.

Integer division / 2 truncates toward zero, so (1ll * n * m) / 2 computes ⌊n*m/2⌋ — exactly the count we need.

Complexity: O(1) time, O(1) space.

*/