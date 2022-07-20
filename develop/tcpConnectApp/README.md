# tcpConnectApp ������@
tcpConnectApp��Sender, Receiver�̓�����@���L�ڂ���B

# docker images, network�̍쐬
�ȉ��̎菇�����{����B
* �wdocker_script�x�t�H���_�̈ȉ��̃X�N���v�g�����s����B
    ```
    cd WebApp/develop/docker_script
    ./create_images.sh
    ./create_network.sh
    ```

# docker container (proxy, skeleton)�̍쐬
* �wtcpConnectApp�x�t�H���_�̈ȉ��̃X�N���v�g�����s���A�R���e�i���쐬����B
    ```
    cd WebApp/develop/tcpConnectApp
    ./create_container.sh
    ```

# �A�v���̃r���h�ƃf�v���C
* �e�X�g�A�v�����r���h����B
    ```
    mkdir build
    cd build
    cmake ..
    make
    ```
* �e�X�g�A�v�����f�v���C����B
    ```
    cd -
    ./copy_app.sh
    ```

# �A�v�����s
* �R���\�[����2�����グ��B
    * �R���\�[��1�ňȉ���Receiver�A�v�����N������B
        ```
        docker exec -it proxy bash
        /root/Receiver/Receiver
        ```
    * �R���\�[��2�ňȉ���Sender�A�v�����N������B
        ```
        docker exec -it skeleton bash
        /root/Sender/Sender
        ```
* �N����Ɉȉ��̃R�����g���R���\�[���ɏo�͂����B
    * Receiver�A�v�����̏o��
        ```
        Start Receive Massage
        HelloWorld!
        ```
    * Sender�A�v�����̏o��
        ```
        Start Send Massage
        Send Massage [HelloWorld!]
        ```