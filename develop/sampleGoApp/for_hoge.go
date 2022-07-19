package main

import "fmt"

func main() {
	// for 初期値; 条件式; 変化式
	for i := 0; i < 10; i++ {
		// 処理を記述
		fmt.Printf("i: %d \n", i)
	}

	// 変数宣言での多重代入を用いることで複数の宣言を使ったループが可能
	for i, j := 0, 1; i < 9 && j < 10; i, j = i+1, j+1 {
		fmt.Printf("i: %d, j: %d \n", i, j)
	}
}
