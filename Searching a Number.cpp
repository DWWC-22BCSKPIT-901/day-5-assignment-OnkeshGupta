#include <iostream>
#include <vector>
using namespace std;

int findPosition(vector<int> arr, int k) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == k) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findPosition(arr, k) << endl;
    return 0;
}