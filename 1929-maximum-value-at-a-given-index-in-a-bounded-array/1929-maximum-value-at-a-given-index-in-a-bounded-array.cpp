class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long rightSpaces = n - index - 1; // number of spaces req at right.
	long leftSpaces = index; //number of spaces req at left.
	
	long high = maxSum;
	long low = 1;
	long maxTillNow = 0;
	
	while(low<= high){
		long mid = low + (high- low) /2; // calculate mid. 
		long sum = mid; // for binary Search. 
		long sumAtLeft = 0; //store the sum of values at left.
		long sumAtRight = 0; //store the sum of values at right.
		long tempMid = mid -1; // to use the formula. 
		
		if(rightSpaces<= tempMid){
			sumAtRight = (tempMid * (tempMid  + 1) / 2) - (tempMid - rightSpaces ) * (tempMid - rightSpaces + 1) / 2;
		}else{
			sumAtRight = (tempMid * (tempMid  + 1) / 2) + 1 * (rightSpaces - tempMid);
		}
		
		if(leftSpaces <= tempMid){
			sumAtLeft = (tempMid * (tempMid  + 1) / 2) - (tempMid - leftSpaces ) * (tempMid - leftSpaces + 1) / 2;
		}else{
			sumAtLeft = (tempMid * (tempMid  + 1) / 2) + 1 * (leftSpaces - tempMid);
		}
		
		sum += sumAtLeft + sumAtRight;
		if(sum <= maxSum){
			maxTillNow = mid;
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return maxTillNow;
    }
};