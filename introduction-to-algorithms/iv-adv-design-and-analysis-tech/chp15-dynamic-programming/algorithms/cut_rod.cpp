/*  The rod-cutting problem is the following. Given a rod of length n inches and a
    table of prices pi for i = 1, 2, 3 ... n, determine the maximum revenue rn obtain-
    able by cutting up the rod and selling the pieces. Note that if the price pn for a rod
    of length n is large enough, an optimal solution may require no cutting at all. */

#include <iostream>
#include <algorithm>
using namespace std;

int memoizedCutRod(int *p, int n);
int memoizedCutRodAux(int *p, int n, int *r);

int main() {
    int n;
    cin >> n;
    int *p = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    cout << "res: " << memoizedCutRod(p, n) << endl;

    return 0;
}

int memoizedCutRod(int *p, int n) {
    int *r = new int[n + 1];
    /*  Initializes all the optimal solutions as a negative number */
    for (int i = 0; i < (n + 1); ++i) 
        r[i] = -INT32_MAX;
    return memoizedCutRodAux(p, n, r);
}

int memoizedCutRodAux(int *p, int n, int *r) {
    int q;
    /*  If the optimal solution for n = j is already calculated, then
        omit it */
    if (r[n] >= 0) 
        return r[n];
    /*  Base case, the length of the rod is equal to zero */
    if (n == 0)
        q = 0;
    else {
        q = -INT32_MAX;
        /*  For each sub-segment of rod, calculated the optimal solution
            r[n] = max (r[n], p[i] + r[n - i]) */
        for (int i = 0; i < n; ++i)
            q = max(q, p[i] + memoizedCutRodAux(p, n - (i + 1), r));
    }
    r[n] = q;
    return q;
}