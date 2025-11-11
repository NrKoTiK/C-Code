#ifndef LEETING_CPP
#define LEETING_CPP
#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> arr{};
        int it1 = 0;
        int it2 = it1 + 1;
        for(int it1 = 0; it1 < nums.size();)
        {
            if (nums[it1] + nums[it2] == target)
            {
                arr.push_back(it1);
                arr.push_back(it2);
                break;
            }
            else 
            {
                ++it2; // when it comes last index
            }
            if (it2 == nums.size()) // this function gets executed
            {
                ++it1;
				it2 = it1 + 1;
            }
        }
        return arr;
    }
};

int main()
{
	Solution sol;
	std::vector<int> nums = { 2, 7, 11, 15 };
	std::vector<int> nums2 = { 3,2,3 };
	std::vector<int> nums3 = { 3,3 };
	int target1 = 6;
    int target2 = 6;
	int target = 9;
	std::vector<int> result = sol.twoSum(nums, target);
	std::vector<int> result2 = sol.twoSum(nums2, target2);
	std::vector<int> result3 = sol.twoSum(nums3, target1);
	for (int index : result2)
	{
		std::cout << index << " ";
	}
	return 0;
}

#endif // !LEETING_CPP
