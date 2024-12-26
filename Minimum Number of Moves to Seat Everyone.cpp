#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int moves = 0;
    for (int i = 0; i < seats.size(); i++) {
        moves += abs(seats[i] - students[i]);
    }
    return moves;
}

int main() {
    int n;
    cin >> n;
    vector<int> seats(n), students(n);
    for (int i = 0; i < n; i++) {
        cin >> seats[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }
    cout << minMovesToSeat(seats, students) << endl;
    return 0;
}