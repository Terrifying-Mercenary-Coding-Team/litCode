/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let tmp=[]
    nums.forEach((val,ind) => tmp.push([val, ind]));
    nums = tmp;
    nums.sort((a,b) => a[0]-b[0]);
    let i=0,j=nums.length-1,ret=[];
    while(i<j){
        let tmp=nums[i][0]+nums[j][0];
        if(tmp==target){
            ret.push(nums[i][1]);
            ret.push(nums[j][1]);
            i++;
            j--;
        } else if(tmp<target){
            i++;
        } else{
            j--;
        }
    }
    ret.sort((a,b) => a-b);
    return ret;
};
console.log(twoSum([2,7,11,15],9));
console.log(twoSum([3,2,4],6));
