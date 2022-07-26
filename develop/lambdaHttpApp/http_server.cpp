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

using namespace std;

#include "PrintLog.h"

// Instance generation
PrintLog printLog;

// Define lambda
auto response_code = []() {
    auto body = std::string("Hello World!");
    auto response = std::string("");
    std::ostringstream oss;

    oss << "Content-Length: " << 20 << "\r\n";

    response.append("HTTP/1.1 200 OK\r\n");
    response.append("Content-Type: text/html; charset=UTF-8\r\n");
    response.append(oss.str());
    response.append("Connection: Keep-Alive\r\n");
    response.append("\r\n");
    response.append(body);      // ブラウザに表示される文字

    return response;
};

auto send_response = [](int sock) {
    auto response = response_code();
    printLog.print_string_cout(("response:" + response));

    char inbuf[2048];

    while (true) {
        auto connfd = accept(sock, nullptr, nullptr);
        if (connfd < 0) {
            printLog.print_string_cout("Failed to accept.");
            break;
        }

        memset(inbuf, 0, sizeof(inbuf));
        recv(connfd, inbuf, sizeof(inbuf), 0);
        if (send(connfd, response.c_str(), response.length(), 0) == -1) {
            printLog.print_string_cout("Failed to send.");
        }
    }
};

/////////////////////////////////////////////
////        main                         ////
/////////////////////////////////////////////

int main()
{
    auto sock = socket(AF_INET, SOCK_STREAM, 0);

    if (!sock) {
        printLog.print_string_cout("Failed to initialize a socket.");
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
        printLog.print_string_cout("Failed to setsocket");
        close(sock);
        return 1;
    }

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        printLog.print_string_cout("Failed to bind. error:", strerror(errno));
        close(sock);
        return 1;
    }

    if (listen(sock, 5) != 0) {
        printLog.print_string_cout("Failed to listen. error:", to_string(errno));
        close(sock);
        return 1;
    }

    send_response(sock);

    close(sock);

    return 0;
}
