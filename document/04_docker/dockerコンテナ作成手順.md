# dockerコンテナ作成手順
* 基本的なdockerコマンド
    * https://weblabo.oscasierra.net/docker-ubuntu1604/
    * docker start コンテナ名
    * docker stop コンテナ名
    * docker rm コンテナ名
    * docker exec -it コンテナ名 bash
        * ※docker attach コンテナ名 とほとんど同じ。ただし、attachは他のコンソールからの操作は受け付けない。
    * 

# コンテナのIP設定方法
* 参考
    * https://zaki-hmkc.hatenablog.com/entry/2021/02/26/234357
* docker networkの作成
    * docker network create --subnet アドレス dockerネットワーク名
        * 例
            ```
            docker network create --subnet 10.254.253.0/24 fixed_container_network
            ```
    * docker runに以下の引数を追加
        * --network dockerネットワーク名
        * --ip IPアドレス

# dockerfileの作成
* 参考
    * https://knowledge.sakura.ad.jp/15253/
    * https://atmarkit.itmedia.co.jp/ait/articles/1407/08/news031.html
* sample
    ```
    FROM centos:7               # ①
    RUN yum install -y java     # ②
    ADD files/apache-tomcat-9.0.6.tar.gz /opt/  # ③
    CMD [ "/opt/apache-tomcat-9.0.6/bin/catalina.sh", "run" ]  # ④
    ```
    * ①のFROMは、ベースとするDockerイメージを指定
    * ②のRUNは、OSのコマンドのインストール
    * ③のADDは、用意したtar.gzファイルのコンテナへのコピーと、tarの展開
    * ④のCMDは、コンテナ起動時に実行するコマンドを記述

# docker buildコマンド
* docker build [-t ｛イメージ名｝:｛タグ名｝] [-f 使用するDockerfile名] ｛Dockerfileのあるディレクトリ｝
    * -f でファイル名を指定しない場合はデフォルトの"Dockerfile"が使用される。
