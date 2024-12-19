// Count Digits in a Number
// Objective
// Count the total number of digits in a given number n. The number can be a positive integer. For example, for the number 12345, the count of digits is 5. For a number like 900000, the count of digits is 6.
// Given an integer n, your task is to determine how many digits are present in n. This task will help you practice working with loops, number manipulation, and conditional logic.
// Task
// Given an integer n, print the total number of digits in n.
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }

    cout << count << endl;
    return 0;
}
