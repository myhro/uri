package main

import "fmt"

type score struct {
	judgement string
	time      int
}

func main() {
	var j string
	var l string
	var n int
	var t int

	for {
		scores := make(map[string][]score)
		fmt.Scan(&n)
		if n == 0 {
			break
		}

		for i := 0; i < n; i++ {
			fmt.Scan(&l, &t, &j)
			tmp := score{
				judgement: j,
				time:      t,
			}
			scores[l] = append(scores[l], tmp)
		}

		s := 0
		p := 0
		for i := range scores {
			correct := false
			incorrect := 0
			for _, problem := range scores[i] {
				if problem.judgement == "correct" {
					correct = true
					p += problem.time + (incorrect * 20)
				} else {
					incorrect++
				}
			}
			if correct {
				s++
			}
		}
		fmt.Println(s, p)
	}
}
