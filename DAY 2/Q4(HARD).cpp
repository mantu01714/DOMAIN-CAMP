// Maximum Number of Groups Getting Fresh Donuts
#include <iostream>
#include <vector>
using namespace std;

int maxHappyGroups(int batchSize, vector<int>& groups) {
    vector<int> remainders(batchSize, 0);
    int happyGroups = 0;
    for (int group : groups) {
        int rem = group % batchSize;
        if (rem == 0) {
            ++happyGroups;
        } else if (remainders[batchSize - rem] > 0) {
            ++happyGroups;
            --remainders[batchSize - rem];
        } else {
            ++remainders[rem];
        }
    }
    return happyGroups;
}

int main() {
    vector<int> groups = {1, 2, 3, 4, 5, 6};
    int batchSize = 3;
    cout << "Happy Groups: " << maxHappyGroups(batchSize, groups) << endl;
    return 0;
}
