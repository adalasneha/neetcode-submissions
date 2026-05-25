class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        mp[0] = 1; // prefix sum 0 occurs once
        
        int prefixSum = 0;
        int count = 0;
        
        for(int num : nums) {
            prefixSum += num;
            
            // check if (prefixSum - k) exists
            if(mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }
            
            // store current prefix sum
            mp[prefixSum]++;
        }
        
        return count;
    }
};