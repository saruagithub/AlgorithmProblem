#include <vector>
#include <iostream>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //cout << "begin" << endl;
    if (nums1.size() == 0) {
        // in nums2
        if (nums2.size() % 2 != 0) return nums2[nums2.size() / 2];
        else return float((nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1])) / 2;
    } else {
        if (nums1.size() % 2 != 0) return nums1[nums1.size() / 2];
        else return float((nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1])) / 2;
    }
    // double pointer, merge array until index = (size1 + size2) / 2
    int mid = (nums1.size() + nums2.size()) / 2;
    int res= 0;
    int p1 = 0, p2 = 0, count = 0;
    while (count < mid + 1) {
        if (p1 < nums1.size() && nums1[p1] < nums2[p2]) {
            res = nums1[p1];
            p1++;
        } else {
            res = nums2[p2];
            p2++;
        }
        count++;
    }
    cout << " 1111 " << endl;
    if ((nums1.size() + nums2.size()) % 2 != 0) return res;
    else return float(res + nums2[p1]) / 2;
}

int main() {
    vector<int> num1 = {1,2};
    vector<int> num2 = {3,4};
    cout << findMedianSortedArrays(num1, num2) << endl;
    return 0;
}