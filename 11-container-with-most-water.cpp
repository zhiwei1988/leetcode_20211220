//
// Created by ZhiWei Tan on 1/1/22.
//

#include "playgroud.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxAreas = INT_MIN;
        while (left < right) {
            // 能装水的高度由小的一边决定
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = w * h;
            maxAreas = max(maxAreas, area);
            // 每次移动高度较小一边，因为高度是由较小的一边决定，且每次移动宽度都会减小
            // 如果移动高度较大的一边，面积可能会更小；只有移动高度较小的一边，如果遇到
            // 更大高度的边，面积才有可能变大
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxAreas;
    }
};

int main()
{
    vector<int> height = {4,3,2,1,4};
    auto ret = Solution().maxArea(height);
    cout << "ret = " << ret << endl;
    return 0;
}

