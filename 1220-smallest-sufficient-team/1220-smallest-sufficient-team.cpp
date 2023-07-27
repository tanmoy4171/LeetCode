class Solution {
public:

   vector<int>temp;

   void func(int i,vector<string>& req_skills, vector<int>pep_skill,int mask,vector<int>&ans,int n,vector<vector<int>> &dp)
   {
      if(i==pep_skill.size())
      {
          if(mask == (1<<n)-1) // all bits are 1
          {
            if(temp.size()==0 || temp.size()>ans.size()) // prev store array is bigger 
            {
               temp=ans;
            }
          }
          return ;
      }
      if(dp[i][mask]!=-1) 
      {
          if(dp[i][mask] <= ans.size()) return;
      }




      func(i+1,req_skills,pep_skill,mask,ans,n,dp);  // notTake condition
 
      ans.push_back(i);
      func(i+1,req_skills,pep_skill,(mask | pep_skill[i]),ans,n,dp); // take condition
      ans.pop_back();

      dp[i][mask] = ans.size();

   }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
       
       int n=req_skills.size();
       int m=people.size();

       vector<int>pep_skill;

       for(int i=0;i<m;i++)
       {
           int skill=0;
           for(int j=0;j<people[i].size();j++)
           {
               for(int k=0;k<n;k++)
               {
                  if(people[i][j]==req_skills[k])
                  {
                      skill=skill | (1<<k);  // setting the mask for each people skills
                  }
               }
           }
           pep_skill.push_back(skill);

       }
        vector<int>ans;

        int target=pow(2,n); 

        vector<vector<int>> dp(m, vector<int>(target, -1));  // [index][target]  because 00 can to to max to 11 or 2^n 

        func(0,req_skills,pep_skill,0,ans,n,dp);
        return temp;

    }

};