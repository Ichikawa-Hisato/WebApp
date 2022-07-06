* docker間の通信を行おうとしたが以下のエラーが表示された。
    ```
    root@1e0ba9047de4:~/build# ./Receiver
    Error bind:Cannot assign requested address
    ```
    * 要求されたアドレスを割り当てることができません
* IPアドレスとポート番号は以下を使用した。
    * skeleton
        * IP
            * 192.168.20.120
        * port
            * 24
            * 1234
            * 36000
    * proxy
        * IP
            * 192.168.20.110
        * port
            * 24
            * 1234
            * 36000
