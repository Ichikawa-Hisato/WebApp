package main

import ( "fmt"
		 "flag"
)

func getFoo()(int) {
	s := flag.Int("s", 0, "Int flag")		// 変数名 = flag.Int("オプション名", "デフォルト値", "このフラグの説明"))
	flag.Parse()
	return *s
}

func main() {
	// if, else if, else を用いる
	var hoge int = 10
	if hoge < 0 {
		fmt.Println("hogeは負の値です")
	} else if hoge < 10 {
		fmt.Println("hogeは10未満です")
	} else {
		fmt.Println("hogeは10以上です")
	}

	// ifの中にifを書くことも出来ます
	if hoge < 10 {
		fmt.Println("hogeは10未満です")
		if hoge < 0 {
			fmt.Println("hogeは負の値です")
		}
	}

	// hogeの値を取得して表示しています
	// なお、この変数はこのif文の中のみで有効なので注意
	if foo := getFoo(); foo < 0 {
		fmt.Println("fooは負の値です")
	} else {
		fmt.Println("fooは正の値です")
	}
}
