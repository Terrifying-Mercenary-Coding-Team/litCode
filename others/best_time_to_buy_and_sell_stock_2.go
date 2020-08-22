package main

import (
    "fmt"
    "math"
)

func maxProfit(prices []int) int {
    ret := 0
    for i:=0;i<len(prices)-1;i++ {
        ret += int(math.Max(0,float64(prices[i+1]-prices[i])))
    }
    return ret
}

func main(){
    t1 := []int{7,1,5,3,6,4}
    t2 := []int{1,2,3,4,5}
    t3 := []int{7,6,4,3,1}
    fmt.Println(maxProfit(t1))
    fmt.Println(maxProfit(t2))
    fmt.Println(maxProfit(t3))
}
