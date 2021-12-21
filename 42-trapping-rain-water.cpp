//
// Created by zhiwei on 12/21/2021.
//

#include "playgroud.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> s; // 构建单调递增栈
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int pre = s.top(); // 池底
                s.pop();
                if (s.empty()) {
                    break; // 没有左边的池壁了
                }

                int heightMin = min(height[s.top()], height[i]); // 左右池壁中取小的一边
                res += (heightMin - height[pre]) * (i - s.top() - 1);
            }

            s.push(i);
        }

        return res;
    }
};

int main()
{
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    auto result = Solution().trap(heights);
    std::cout << "ans = " << result << std::endl;
    return 0;
}

