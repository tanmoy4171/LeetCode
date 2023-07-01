class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double tax = 0,d;
		// first case
        if (income > brackets[0][0])
            tax += (brackets[0][0] * brackets[0][1]) / 100.00000;
        else
            tax += (income * brackets[0][1]) / 100.00000;
			// all other case
        for (int i = 1; i < brackets.size(); i++)
        {
            if (brackets[i][0] < income)
            {
               d = brackets[i][0] - brackets[i - 1][0];
                if (d < 0) d = 0;
                tax += (d*brackets[i][1]) / 100.00000;
            }
            else
            {
                 d = income - brackets[i - 1][0];
                if (d < 0) d = 0;
                tax += (d*brackets[i][1]) / 100.00000;
            }
        }
        return tax;
    }
};