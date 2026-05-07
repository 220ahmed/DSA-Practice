#include<bits/stdc++.h>
using namespace std;
int iterativeBinarySearch(vector<int> &nums,int tar){ //Time Complexity = O(log N) (base 2)
    int n = nums.size();
    int low = 0;
    int high = n-1;
    while(low <= high){
        // To prevent overflow codition (mid) either long long || below method
        int mid = low + (high-low)/2;
        if(nums[mid] == tar) return mid;
        else if(tar > nums[mid]){
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return -1;
}
int recursiveBinarySearch(vector<int> &nums,int low,int high,int tar){//Time Complexity = O(log N) (base 2)
    int mid = low + (high-low)/2;
    if(high < low){
        return -1;
    }
    if(nums[mid] == tar){
        return mid;
    }
    else if(tar > nums[mid]){
        return recursiveBinarySearch(nums,mid+1,high,tar);
    }
    else{
        return recursiveBinarySearch(nums,low,mid-1,tar);
    }
}

int main()
{
    vector<int> nums = {3,4,6,7,9,12,16,17};
    int ans = iterativeBinarySearch(nums,16);
    cout<<ans;
    return 0;
}