#include <iostream>

using namespace std;

void fibonacci(int n) {
    if (n <= 0) return;

    int fibSeq[n];
    fibSeq[0] = 0;
    if (n > 1) {
        fibSeq[1] = 1;

        // Calculate the rest of the Fibonacci sequence
        for (int i = 2; i < n; ++i) {
            fibSeq[i] = fibSeq[i - 1] + fibSeq[i - 2];
        }
    }

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; ++i) {
        cout << fibSeq[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of Fibonacci sequence elements to generate: ";
    cin >> n;
    fibonacci(n);
    return 0;
}
