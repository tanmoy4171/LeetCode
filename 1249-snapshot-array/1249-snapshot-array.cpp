class SnapshotArray {
    vector<vector<pair<int, int>>> nums;
    int snapId = 0;
public:
    SnapshotArray(int length) {
        nums = vector<vector<pair<int, int>>>(length); //snapId, val
        for(int i=0; i<length; i++){
            nums[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        auto itr = nums[index].back();
        if(itr.first == snapId){
            nums[index].back().second = val;
        }else{
            nums[index].push_back({snapId, val});
        }
    }
    
    int snap() {
        snapId++;
        return (snapId - 1);
    }
    
    int get(int index, int snap_id) {
        auto itr = lower_bound(nums[index].begin(), nums[index].end(), make_pair(snap_id, INT_MIN));
        if(itr == nums[index].end() || itr->first > snap_id){
            itr--;
        }
        return itr->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */