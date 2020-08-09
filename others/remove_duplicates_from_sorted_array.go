package main

import "fmt"

func removeDuplicates(nums []int) int {
    if len(nums) == 0 {
        return 0
    }

    i := 0
    for j := 1; j < len(nums); j++ {
        if nums[i] != nums[j] {
            nums[i+1] = nums[j]
            i++
        }
    }
    nums = nums[:i+1]
    return len(nums)
}

func main(){
    test1 := []int{0,0,1,1,1,2,2,3,3,4}
    ret := removeDuplicates(test1)
    for _, val := range test1 {
        fmt.Println(val)
    }
    fmt.Println(ret)
}
