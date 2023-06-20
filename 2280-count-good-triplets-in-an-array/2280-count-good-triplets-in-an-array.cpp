class SegmentTree {
    long long* st;

public: 
    SegmentTree(int size){
        st = (long long*)calloc(4*size, sizeof(long long));
    }

    void pushUp(int node){
        st[node] = st[2*node+1] + st[2*node+2];
    }

    void update(int index, long long value, int node, int l, int r){
        if( l == r ){
            st[node] += value;
            return;
        }

        int mid = (l + r) / 2;
        if( index <= mid )
            update(index, value, 2*node+1, l, mid);
        else
            update(index, value, 2*node+2, mid+1, r);

        pushUp(node);
    }

    long long query(int qL, int qR, int node, int l, int r){
        if( qL <= l && r <= qR )
            return st[node];

        int mid = (l + r) / 2;
        long long ans = 0;
        if( qL <= mid )
            ans += query(qL, qR, 2*node+1, l, mid);
        if( mid < qR )
            ans += query(qL, qR, 2*node+2, mid+1, r);

        return ans;        
    }

};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> val2_idx;
        for( int i = 0 ; i < nums2.size() ; i++ )
            val2_idx[nums2[i]] = i; // distinct

        unordered_map<int, int> idx1_2;
        for( int i = 0 ; i < nums1.size() ; i++ )
            idx1_2[i] = val2_idx[nums1[i]];
        
        // O(NlogN), find ever smaller than me, first second: count
        SegmentTree* first = new SegmentTree(nums1.size());
        SegmentTree* second = new SegmentTree(nums1.size());

        long long ans = 0;
        int l = 0, r = nums1.size();
        for( int i = 0 ; i < nums1.size() ; i++ ){
            // printf("i: %d, idx1_2: %d\n", i, idx1_2[i]);
            if( idx1_2[i] != 0 ){
                ans += second->query(0, idx1_2[i]-1, 0, l, r);
                long long can_be_i = first->query(0, idx1_2[i]-1, 0, l, r);
                second->update(idx1_2[i], can_be_i, 0, l, r);
            }

            first->update(idx1_2[i], 1, 0, l, r);
        }
        return ans;
        
        // O(N^2)
        // vector<int> end_at(nums1.size(), 0);
        // for( int i = 0 ; i < nums1.size() ; i++ ){
        //     for( int j = i+1 ; j < nums1.size() ; j++ ){
        //         if( idx1_2[i] < idx1_2[j] )
        //             end_at[j]++;
        //     }
        // }
        // long long ans = 0;
        // for( int j = 0 ; j < nums1.size() ; j++ ){
        //     for( int k = j+1 ; k < nums1.size() ; k++ ){
        //         if( idx1_2[j] < idx1_2[k] )
        //             ans += end_at[j];
        //     }
        // }

        // return ans;
    }
};