# docker�R���e�i�쐬�菇
* ��{�I��docker�R�}���h
    * https://weblabo.oscasierra.net/docker-ubuntu1604/
    * docker start �R���e�i��
    * docker stop �R���e�i��
    * docker rm �R���e�i��
    * docker exec -it �R���e�i�� bash
        * ��docker attach �R���e�i�� �ƂقƂ�Ǔ����B�������Aattach�͑��̃R���\�[������̑���͎󂯕t���Ȃ��B
    * 

# �R���e�i��IP�ݒ���@
* �Q�l
    * https://zaki-hmkc.hatenablog.com/entry/2021/02/26/234357
* docker network�̍쐬
    * docker network create --subnet �A�h���X docker�l�b�g���[�N��
        * ��
            ```
            docker network create --subnet 10.254.253.0/24 fixed_container_network
            ```
    * docker run�Ɉȉ��̈�����ǉ�
        * --network docker�l�b�g���[�N��
        * --ip IP�A�h���X

# dockerfile�̍쐬
* �Q�l
    * https://knowledge.sakura.ad.jp/15253/
    * https://atmarkit.itmedia.co.jp/ait/articles/1407/08/news031.html
* sample
    ```
    FROM centos:7               # �@
    RUN yum install -y java     # �A
    ADD files/apache-tomcat-9.0.6.tar.gz /opt/  # �B
    CMD [ "/opt/apache-tomcat-9.0.6/bin/catalina.sh", "run" ]  # �C
    ```
    * �@��FROM�́A�x�[�X�Ƃ���Docker�C���[�W���w��
    * �A��RUN�́AOS�̃R�}���h�̃C���X�g�[��
    * �B��ADD�́A�p�ӂ���tar.gz�t�@�C���̃R���e�i�ւ̃R�s�[�ƁAtar�̓W�J
    * �C��CMD�́A�R���e�i�N�����Ɏ��s����R�}���h���L�q

# docker build�R�}���h
* docker build [-t �o�C���[�W���p:�o�^�O���p] [-f �g�p����Dockerfile��] �oDockerfile�̂���f�B���N�g���p
    * -f �Ńt�@�C�������w�肵�Ȃ��ꍇ�̓f�t�H���g��"Dockerfile"���g�p�����B
