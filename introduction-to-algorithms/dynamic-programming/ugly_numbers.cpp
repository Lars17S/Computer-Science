/*  
    Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
    The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the
    first 11 ugly numbers. By convention, 1 is included.
    
    Given a number n, the task is to find n’th Ugly number.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        int *uglydp = new int[n];
        uglydp[0] = 1;

        int it_2 = 0;
        int it_3 = 0;
        int it_5 = 0;

        int next_num_it_2 = uglydp[0] * 2;
        int next_num_it_3 = uglydp[0] * 3;
        int next_num_it_5 = uglydp[0] * 5;

        for (int j = 1; j < n; ++j) {
            int next_ugly = min(min(next_num_it_2, next_num_it_3), next_num_it_5);
            uglydp[j] = next_ugly;

            if (uglydp[j] == next_num_it_2) {
                ++it_2;
                next_num_it_2 = uglydp[it_2] * 2;
            }
            if (uglydp[j] == next_num_it_3) {
                ++it_3;
                next_num_it_3 = uglydp[it_3] * 3;
            }
            if (uglydp[j] == next_num_it_5) {
                ++it_5;
                next_num_it_5 = uglydp[it_5] * 5;
            }
        }

        cout << uglydp[n-1] << endl;
        delete[] uglydp;
    }
    return 0;
}