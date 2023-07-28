class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        int curr;
        for (int i=0; i<asteroids.size(); i++) {
            curr = asteroids[i];
            
            // if curr goes right or stack top goes left - stack stays stable when added
            if ((curr > 0) || (stack.empty()) || (stack.back() < 0))
                stack.push_back(curr);
            
            // if curr is negative, stack top is positive and values are equal - both will explode
            else if (abs(curr) == stack.back()) {
                stack.pop_back();
                continue;
            }
            
            // if curr is negative, stack top is positive and curr > stack top - stack top will explode
            else if (abs(curr) > stack.back()) {
                stack.pop_back();
                i--;
            }
        }
        return stack;
    }
};