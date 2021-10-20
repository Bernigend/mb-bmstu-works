package main

import (
	"fmt"
	"sync"
)

func main() {
	var cnt int64

	wg := sync.WaitGroup{}
	sm := sync.Mutex{}

	for i := 0; i < 1000; i++ {
		wg.Add(1)

		go func(wg *sync.WaitGroup, sm *sync.Mutex) {
			sm.Lock()
			cnt++
			sm.Unlock()

			wg.Done()
		}(&wg, &sm)
	}

	wg.Wait()

	fmt.Println(cnt)
}