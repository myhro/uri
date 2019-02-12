package main

import (
	"fmt"
	"strings"
)

type student struct {
	name      string
	frequency string
}

func main() {
	var t int
	var n int
	fmt.Scan(&t)
	for t != 0 {
		fmt.Scan(&n)
		students := make([]student, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&students[i].name)
		}
		for i := 0; i < n; i++ {
			fmt.Scan(&students[i].frequency)
		}
		first := true
		for _, s := range students {
			medical := strings.Count(s.frequency, "M")
			present := float64(strings.Count(s.frequency, "P"))
			total := float64(len(s.frequency) - medical)
			if (present / total) < float64(0.75) {
				if !first {
					fmt.Printf(" ")
				}
				first = false
				fmt.Printf(s.name)
			}
		}
		fmt.Println()
		t--
	}
}
