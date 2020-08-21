package main

import "fmt"

func twoSum(nums []int, target int) []int {
     hash := make(map[int]int)
     ret := make([]int, 0)
     for i := 0; i < len(nums); i++ {
        hash[nums[i]] = i
     }
     for i := 0; i < len(nums); i++ {
         ind, exists := hash[target-nums[i]]
         if exists && i!=ind {
            ret = append(ret,ind)
            ret = append(ret,i)
            break
         }
     }

    return ret
}

func main(){
    arg := []int{2,7,11,15}
    ret := twoSum(arg,9)
    fmt.Println(ret)
    arg = []int{3,2,4}
    ret = twoSum(arg,6)
    fmt.Println(ret)
}

