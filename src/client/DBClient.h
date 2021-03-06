//
// Created by wonder on 2021/10/9.
//

#pragma once

#include <string>

class DBClient {
public:
    DBClient(int port, std::string ip = "127.0.0.1");

    ~DBClient();

    void Connect();

    void Close();

    void Send(const std::string &buf);

    void Recv(char *buf);

    void parseCmd();

    void handleRequest(const std::string &buf);

private:
    std::string ip_;
    int port_;
    int connfd_;
};

const std::string helpTxt = "String: set,get\r\nList: rpush,rpop\r\n"
                            "Hash: hset,hget,hgetall\r\nSet: sadd,smembers\r\n"
                            "HSet: zadd,zcard,zrange,zcount,zgetall\r\n";