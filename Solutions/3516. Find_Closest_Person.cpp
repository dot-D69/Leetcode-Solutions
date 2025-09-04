class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1 = abs(x-z);
        int p2 = abs(y-z);

        if(p1>p2) return 2;
        else if(p2>p1) return 1;
        else return 0;
    }
};

/*
The code is basically a distance check:

  Measure how far x and y are from z.
  Whichever is closer, return its label (1 for x, 2 for y).
  If they tie, return 0.



Compute distance of x from z → p1.

Compute distance of y from z → p2.

Compare distances:

If p2 smaller → y is closer → return 2.

If p1 smaller → x is closer → return 1.

If equal → return 0.
*/