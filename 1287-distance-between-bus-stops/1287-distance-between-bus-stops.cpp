class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total = accumulate(distance.begin(),distance.end(),0),clockwise=0,n=distance.size();
        int i = start;
        do{
            clockwise+=distance[i%n];
            i++;
        }while(i%n != destination);
        return min(clockwise,total-clockwise);
    }
};