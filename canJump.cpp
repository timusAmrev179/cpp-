/*
#programming #coding #interviewquestion
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.

*/

#include<bits/stdc++.h>
using namespace std; 



bool jumpPossible(vector<int>& nums, int d, int i=0){
	if(nums[i] >= d)
		return true; 

	for(int k=nums[i]; k>=1; k--){
		if((i+k< nums.size()-1) && jumpPossible(nums, d-k, i+k) == true)
			return true;  
	}

	return false; 
}
// this is basically we are calling jumpPossible which using back tracking method to find the path. takes o(2^n) It gives TLE. 
bool canJump1(vector<int>& nums){
	if(nums.size() == 0)
		return true; 

	return jumpPossible(nums, nums.size()-1); 
}

// a bottom up approach better and much faster takes O(n)
bool canJump(vector<int>& nums){
	int lastGoodIndex = nums.size()-1; 
	
	for(int i = lastGoodIndex; i>=0; i-- ){
		if(i+nums[i]>=lastGoodIndex)
			lastGoodIndex = i; 
	}

	return (lastGoodIndex == 0); 
}

int main(){

	vector<int> nums; 
	
	int n; 
	cin>>n; 

	while(n--){
		int x ; cin>>x; 
		nums.push_back(x); 
	}	

	cout<< canJump(nums)<<endl; 
	
	return 0; 
}
