# 情報
* Windows＋WSL2でDocker環境を用意しよう
    * https://www.kagoya.jp/howto/cloud/container/wsl2_docker/
* !!!重要!!!
    * docker0のブリッジネットワークがWindows版をインストールするとwslに作成されない。
    * 以下のサイトでdockerをインストールする。
        * https://www.softek.co.jp/SID/support/sidfmvm/guide/install-docker-ubuntu1804.html
            * systemctlコマンドが使用できず、インストールできない。

# インストール手順
* wsl2の適用 インストール手順
    * https://docs.microsoft.com/ja-jp/windows/wsl/install-manual#step-4---download-the-linux-kernel-update-package
        * Ubuntu 18.04をインストール
* Linux GUIのために以下の手順を実施
    * https://docs.microsoft.com/ja-jp/windows/wsl/tutorials/gui-apps
        * この機能にアクセスするには、ビルド 22000 以降Windows 11上にある必要があります。
        * Windows 10では動作しない。
    * windows terminalのインストール
        * wslを使ってLinux GUIは起動しない。

# 注意
* Windows版dockerをインストールした場合、WindowsでDocker Desktopを起動しないと、wslでdockerコマンドを使えない。
