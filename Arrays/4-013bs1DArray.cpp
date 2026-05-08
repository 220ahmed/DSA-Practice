#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums,int x){
    int ans = nums.size();
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid  + 1; 
        }
    }
    return ans;
}
int upperBound(vector<int> &nums,int x){
    int ans = nums.size();
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
}
pair<int,int> firstLastOccurrence(vector<int> &nums,int k){ //T.C = 2*O(logN)
    int n = nums.size();
    int first = lowerBound(nums,k);
    if(nums[first] != k || first == n) return {-1,-1};
    int last = upperBound(nums,k) - 1;
    return {first,last};
}
int bsFirstOccurrence(vector<int> &nums,int k){
    int n = nums.size();
    int fO = -1;
    int low  = 0;
    int high  = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == k){
            fO = mid;
            high = mid - 1;
        }
        else if(nums[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return fO;
}
int bsLastOccurrence(vector<int> &nums,int k){
    int n = nums.size();
    int lO = -1;
    int low  = 0;
    int high  = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == k){
            lO = mid;
            low = mid + 1;
        }
        else if(nums[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return lO;
}
pair<int,int> bsFirstLastOccurrence(vector<int> &nums,int k){ //T.C = 2*O(logN)
    pair<int,int> ans;
    ans.first = bsFirstOccurrence(nums,k);
    if(ans.first == -1) return {-1,-1}; 
    ans.second = bsLastOccurrence(nums,k);
    return ans; 
}
int noOfOccurrences(vector<int> &nums, int k){
    pair<int,int> ans = bsFirstLastOccurrence(nums,k);
    if(ans.first == -1) return -1;
    return ans.second - ans.first + 1;
}
int main()
{
    vector<int> nums = {2,4,6,8,8,11,13};
    int x = 2;
    // pair<int,int> ans = firstLastOccurrence(nums,x);
    // pair<int,int> ans1 = bsFirstLastOccurrence(nums,x);
    // cout<< ans.first <<" " <<ans.second;
    // cout<<endl;
    // cout<< ans1.first <<" " <<ans1.second;
    int ans = noOfOccurrences(nums,x);
    cout<<ans;
    return  0;
}