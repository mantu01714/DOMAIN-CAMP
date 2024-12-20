// Find Minimum Time to Finish All Jobs
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canAssign(const vector<int>& jobs, vector<int>& workers, int maxTime, int index) {
    if (index == jobs.size()) return true;

    for (int i = 0; i < workers.size(); ++i) {
        if (workers[i] + jobs[index] <= maxTime) {
            workers[i] += jobs[index];
            if (canAssign(jobs, workers, maxTime, index + 1)) return true;
            workers[i] -= jobs[index];
        }
        if (workers[i] == 0) break;
    }
    return false;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    sort(jobs.rbegin(), jobs.rend());
    int left = jobs[0], right = accumulate(jobs.begin(), jobs.end(), 0); // Use accumulate here
    while (left < right) {
        int mid = left + (right - left) / 2;
        vector<int> workers(k, 0);
        if (canAssign(jobs, workers, mid, 0)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    vector<int> jobs = {1, 2, 4, 7, 8};
    int k = 2;
    cout << "Minimum Time: " << minimumTimeRequired(jobs, k) << endl;
    return 0;
}
