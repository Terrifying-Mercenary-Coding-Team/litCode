/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let ret=0,cur=0,tmp=0
    for(let i=prices.length-1;i>=0;i--){
        if(prices[i]>cur){
            cur = prices[i]
        }
        else{
            ret += cur-prices[i]
            cur = prices[i]
        }
    }
    return ret
};
console.log(maxProfit([7,1,5,3,6,4]))
console.log(maxProfit([1,2,3,4,5]))
console.log(maxProfit([7,6,4,3,1]))
