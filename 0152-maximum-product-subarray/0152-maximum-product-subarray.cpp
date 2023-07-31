class Solution {
public:
    int maxProduct(vector<int>& a) {
        int crr_maxi=1,maxi=INT_MIN;
		//crr_max is assigned by 1 bcz we are multipliying all value by crr_max
		
        /*we can't assign any neg numberic value to maxi bcz if in
        any test case, any value below that is given then it will not
        give correct op*/
        /* for example if maxi=-10 is assigned and consider a
        test case [-80] then maxi will return max(maxi,crr_max)
        maxi ke andar -10 aur crr_maxi ke andar -80 aur -10 bada hy na ki 
        -80 so ans return hoga -10 aur ans return hona chiye tha -80
        */
		
        for(int i=0;i<a.size();i++)
        {
            crr_maxi*=a[i];
            maxi=max(maxi,crr_maxi);
            if(crr_maxi==0)
            {
                crr_maxi=1;
            }
        }
        //cheacking from the back
        /*
        checking from back is necessary kiyuki agar [-8,2,3,10]
        then agar aage se check krenge to max sub array aiga -8 aur agar peeche se
        check krenge to ans aiga 60 so 60 is max it will be returned
        */
        crr_maxi=1;
        for(int i=a.size()-1;i>=0;i--)
        {
            crr_maxi*=a[i];
            maxi=max(maxi,crr_maxi);
            if(crr_maxi==0)
            {
                crr_maxi=1;
            }
        }
        return maxi;
    }
};