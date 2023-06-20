class Solution {
public:
    int solve(int num1, int num2, int cnt)
    {
        if(num1 == num2)
            return cnt;
        
        if(num1 >= num2)
        {
            num1 = num1-num2;
            cnt++;
            return solve(num1, num2, cnt);
        }

        else{
            num2 = num2-num1;
            cnt++;
            return solve(num1, num2, cnt);
        }

        return -1;
    }

    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0)
            return 0;
            
        int cnt = 1;

        return solve(num1, num2, cnt);
    }
};