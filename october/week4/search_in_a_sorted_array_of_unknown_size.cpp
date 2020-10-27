/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int st=0, ed=10000;
        while(st<=ed){
            int mid = (st+ed)/2;
            int cur = reader.get(mid);
            if(target == cur)   return mid;
            else if(target < cur)   ed = mid -1;
            else    st = mid + 1;
        }
        return -1;
    }
};
