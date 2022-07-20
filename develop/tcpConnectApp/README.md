# tcpConnectApp 動作方法
tcpConnectAppのSender, Receiverの動作方法を記載する。

# docker images, networkの作成
以下の手順を実施する。
* 『docker_script』フォルダの以下のスクリプトを実行する。
    ```
    cd WebApp/develop/docker_script
    ./create_images.sh
    ./create_network.sh
    ```

# docker container (proxy, skeleton)の作成
* 『tcpConnectApp』フォルダの以下のスクリプトを実行し、コンテナを作成する。
    ```
    cd WebApp/develop/tcpConnectApp
    ./create_container.sh
    ```

# アプリのビルドとデプロイ
* テストアプリをビルドする。
    ```
    mkdir build
    cd build
    cmake ..
    make
    ```
* テストアプリをデプロイする。
    ```
    cd -
    ./copy_app.sh
    ```

# アプリ実行
* コンソールを2つ立ち上げる。
    * コンソール1で以下をReceiverアプリを起動する。
        ```
        docker exec -it proxy bash
        /root/Receiver/Receiver
        ```
    * コンソール2で以下をSenderアプリを起動する。
        ```
        docker exec -it skeleton bash
        /root/Sender/Sender
        ```
* 起動後に以下のコメントがコンソールに出力される。
    * Receiverアプリ側の出力
        ```
        Start Receive Massage
        HelloWorld!
        ```
    * Senderアプリ側の出力
        ```
        Start Send Massage
        Send Massage [HelloWorld!]
        ```