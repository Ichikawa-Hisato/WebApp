# インストール手順
* apt installでインストール
    ```
    sudo apt install cmake
    ```
* C++のコンパイルをする場合はg++のインストールも必要になる。
    ```
    sudo apt install g++
    ```

---
以下間違い
* 参考
    * https://qiita.com/koara-local/items/9d01c6bb9dd93563b7c6
* 以下のコマンドを実行
```
wget https://cmake.org/files/v3.6/cmake-3.6.2.tar.gz
tar xvf cmake-3.6.2.tar.gz
```

# CMakeLists.txの参考
* 基本的な使い方
    * https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
* libraryのリンク方法
    * https://theolizer.com/cpp-school3/cpp-school3-4/