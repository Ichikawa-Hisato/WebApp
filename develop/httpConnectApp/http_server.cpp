#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
    auto sock = socket(AF_INET, SOCK_STREAM, 0);

    if (!sock) {
        std::cout << "Failed to initialize a socket." << std::endl;
        return 1;
    }

    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));

    int port = 5000;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int optval = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        std::cout << "Failed to setsocket" << std::endl;
        close(sock);
        return 1;
    }

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        std::cout << "Failed to bind. error:" << strerror(errno) << std::endl;
        close(sock);
        return 1;
    }

    if (listen(sock, 5) != 0) {
        std::cout << "Failed to listen. error:" << errno << std::endl;
        close(sock);
        return 1;
    }

    auto body = std::string("Hello World!");
    auto response = std::string("");
    std::ostringstream oss;

    oss << "Content-Length: " << 20 << "\r\n";

    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: text/html; charset=UTF-8\r\n");
    response.append(oss.str());
    response.append("Connection: Keep-Alive\r\n");
    response.append("\r\n");
    response.append(body);

    std::cout << "response:" << response << std::endl;

    char inbuf[2048];

    while (true) {
        auto connfd = accept(sock, nullptr, nullptr);
        if (connfd < 0) {
            std::cout << "Failed to accept." << std::endl;
            break;
        }

        memset(inbuf, 0, sizeof(inbuf));
        recv(connfd, inbuf, sizeof(inbuf), 0);

        if (send(connfd, response.c_str(), response.length(), 0) == -1) {
            std::cout << "Failed to send." << std::endl;
        }
    }

    close(sock);

    return 0;
}
