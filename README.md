# WebApp
2022/07/01  
自主学習のため、Linuxを使った通信系のアプリを作成する。  
* キーワード
  * docker
  * tcp通信
  * webサービス

# セットアップ手順
## Windowsの環境構築
1. Ubuntu ISOファイルのダウンロード
    * 以下のサイトから『Desktop image』をダウンロード
        * https://releases.ubuntu.com/18.04/

2. VirtualBoxのインストール
    * 以下のサイトでVirtualBoxをダウンロード
        * https://www.virtualbox.org/wiki/Downloads
            * VirtualBox 6.1.34
    * 以下のページ沿ってインストールを行う。
        * https://qiita.com/HirMtsd/items/225c20b77a7cd5194834
            * ※『VirtualBoxのメニューバー-[デバイス]-[光学ドライブ]-[ホストドライブ'D']を選択』の手順は行わない。

## 仮想環境(Ubuntu)の環境構築
1. Gitのインストール
    * sudo apt install git

2. VSCodeのインストール
    * 以下のサイトに沿ってVSCodeのダウンロードとインストールを行う。
        * https://self-development.info/linux%EF%BC%88ubuntu%E3%83%BBdebian%EF%BC%89%E3%81%B8%E3%81%AEvscode%E3%81%AE%E3%82%A4%E3%83%B3%E3%82%B9%E3%83%88%E3%83%BC%E3%83%AB/
    * 以下のサイトに沿ってGUIの表示を日本語化する。
        * https://www.javadrive.jp/vscode/install/index4.html
    * 空白文字の設定
        1. 『ファイル』タブ > 『ユーザ設定』 > 『設定』から設定ファイルを開く
        1. Tab Size を『4』にする。
        1. Render Whitespace を『all』にする。
        1. Detect Indentationのチェックを外す。
        1. 状況に応じて『Encoding』を変更する。
            * このプロジェクトは基本的に『SJIS』でテキストを作成している。

3. CMakeのインストール
    * sudo apt install cmake

4. C++のインストール
    * sudo apt install g++

5. dockerのインストール
    * 以下のサイトに沿ってインストールを行う。
        * https://www.softek.co.jp/SID/support/sidfmvm/guide/install-docker-ubuntu1804.html
    * sudoなしでdockerコマンドを実行できるように設定する。
        ```
        # (もし無ければ)dockerグループを作る
        $ sudo groupadd docker

        # ユーザをdockerグループに追加
        $ sudo usermod -aG docker $USER

        # 再起動する。
        $ reboot
        ```
        * 参考サイト：
            * https://qiita.com/tkomagata/items/198a3fac14aadf37244c
