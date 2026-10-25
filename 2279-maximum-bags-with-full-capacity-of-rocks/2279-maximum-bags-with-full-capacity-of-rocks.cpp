class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
      vector<int>diff;
        int r = rocks.size();
        int count = 0;

        for(int i=0; i<r; i++){
           diff.push_back(capacity[i] - rocks[i]);
        }
        sort(diff.begin(), diff.end());
        for(int i=0; i<r; i++){
            if(diff[i] <= additionalRocks){
                additionalRocks = additionalRocks - diff[i];
                count++;
            }
        }
        return count;
    }
};