class Solution {
public:
    int shortestSequence(vector<int> &rolls, int k) {
        // support variables
        bool unused[++k];
        int res = 1, counter = 1, fillSize = k * sizeof(bool);
        memset(unused, true, fillSize);
        for (int n: rolls) {
            // considering only first appearances in this iteration
            if (unused[n]) {
                unused[n] = false;
                counter++;
                // iteration complete
                if (counter == k) {
                    res++;
                    counter = 1;
                    memset(unused, true, fillSize);
                }
            }
        }
        return res;
    }
};