#include <iostream> //標準入出力
#include <sys/socket.h> //アドレスドメイン
#include <sys/types.h> //ソケットタイプ
#include <arpa/inet.h> //バイトオーダの変換に利用
#include <unistd.h> //close()に利用
#include <cstring>
#include <string> //string型

using namespace std;
 
int main(int argc, char *argv[])
{
    std::cout << "Start Send Massage" << std::endl;

    //ソケットの生成
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //アドレスドメイン, ソケットタイプ, プロトコル

    if(sockfd < 0){ //エラー処理
        std::cout << "Error socket:" << std::endl; //標準出力
        exit(1); //異常終了
    }

    //アドレスの生成
    struct sockaddr_in addr; //接続先の情報用の構造体(ipv4)
    memset(&addr, 0, sizeof(struct sockaddr_in)); //memsetで初期化
    addr.sin_family = AF_INET; //アドレスファミリ(ipv4)
    addr.sin_port = htons(12345); //ポート番号,htons()関数は16bitホストバイトオーダーをネットワークバイトオーダーに変換
    addr.sin_addr.s_addr = inet_addr("192.168.20.110"); //IPアドレス,inet_addr()関数はアドレスの翻訳

    //ソケット接続要求
    connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)); //ソケット, アドレスポインタ, アドレスサイズ

    //データ送信
    char s_str[] = "HelloWorld!"; //送信データ格納用
    send(sockfd, s_str, 12, 0); //送信
    std::cout << ("Send Massage [" + std::string(s_str) + "]") << std::endl;

    //ソケットクローズ
    close(sockfd);

    return 0;
}
