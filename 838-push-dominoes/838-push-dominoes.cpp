class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);
        int temp = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(dominoes[i] == 'R')
                temp = n;
            else if(dominoes[i] == 'L')
                temp = 0;
            else
                temp = max(temp - 1, 0);
            forces[i] += temp;
        }
        temp = 0;
        for(int i = n - 1;i >= 0; i--)
        {
            if(dominoes[i] == 'L')
                temp = n;
            else if(dominoes[i] == 'R')
                temp = 0;
            else 
                temp = max(temp - 1, 0);
            forces[i] -= temp;
        }
        string ans = "";
        for(int i = 0 ; i < forces.size(); i++)
        {
            if(forces[i] > 0)
                ans += 'R';
            else if(forces[i] < 0)
                ans += 'L';
            else 
                ans += '.';
        }
        return ans;
    }
};