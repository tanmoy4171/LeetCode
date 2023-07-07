class Solution
{
    private:
    int count(string &s, int k, char c)
    {
        int N = s.size(), cnt = 0, i = 0, ans = 0;
        for (int j = 0; j < N; ++j)
        {
            cnt += s[j] == c;
            while (cnt > k)
                cnt -= s[i++] == c; 
            ans = max(ans, j - i + 1);
        }
        return ans;
    }

public:
    int maxConsecutiveAnswers(string s, int k)
    {
        return max(count(s, k, 'T'), count(s, k, 'F'));
    }
};