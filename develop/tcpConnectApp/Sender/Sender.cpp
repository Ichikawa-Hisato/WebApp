#include <iostream> //�W�����o��
#include <sys/socket.h> //�A�h���X�h���C��
#include <sys/types.h> //�\�P�b�g�^�C�v
#include <arpa/inet.h> //�o�C�g�I�[�_�̕ϊ��ɗ��p
#include <unistd.h> //close()�ɗ��p
#include <cstring>
#include <string> //string�^

using namespace std;
 
int main(int argc, char *argv[])
{
    std::cout << "Start Send Massage" << std::endl;

    //�\�P�b�g�̐���
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //�A�h���X�h���C��, �\�P�b�g�^�C�v, �v���g�R��

    if(sockfd < 0){ //�G���[����
        std::cout << "Error socket:" << std::endl; //�W���o��
        exit(1); //�ُ�I��
    }

    //�A�h���X�̐���
    struct sockaddr_in addr; //�ڑ���̏��p�̍\����(ipv4)
    memset(&addr, 0, sizeof(struct sockaddr_in)); //memset�ŏ�����
    addr.sin_family = AF_INET; //�A�h���X�t�@�~��(ipv4)
    addr.sin_port = htons(12345); //�|�[�g�ԍ�,htons()�֐���16bit�z�X�g�o�C�g�I�[�_�[���l�b�g���[�N�o�C�g�I�[�_�[�ɕϊ�
    addr.sin_addr.s_addr = inet_addr("192.168.20.110"); //IP�A�h���X,inet_addr()�֐��̓A�h���X�̖|��

    //�\�P�b�g�ڑ��v��
    connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)); //�\�P�b�g, �A�h���X�|�C���^, �A�h���X�T�C�Y

    //�f�[�^���M
    char s_str[] = "HelloWorld!"; //���M�f�[�^�i�[�p
    send(sockfd, s_str, 12, 0); //���M
    std::cout << ("Send Massage [" + std::string(s_str) + "]") << std::endl;

    //�\�P�b�g�N���[�Y
    close(sockfd);

    return 0;
}
