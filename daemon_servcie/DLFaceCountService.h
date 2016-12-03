//
// Created by Archer Zhang on 2016-12-03.
//

#ifndef DONT_LOOK_DLFACECOUNTSERVICE_H
#define DONT_LOOK_DLFACECOUNTSERVICE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include "DLWorker.h"

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {

    tcp::socket socket_;
    enum {max_length = 2048};
    char data_[max_length];
    const DLWorker * worker;

public:
    Session(tcp::socket socket, const DLWorker * w)
            : socket_(std::move(socket)){
        this->worker = w;
    }

    void start() { do_read(); }

private:

    void do_read(){
        auto self (shared_from_this());
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
                                [this, self](boost::system::error_code ec, std::size_t length){
                                    if(!ec){
                                        do_write(length);
                                    }
                                });
    }

    void do_write(std::size_t length){
        auto self(shared_from_this());


        std::string str = std::to_string((int)(worker->getFaceCount())/2);

        str += "\n\0";


        std::cout << str;

        memset(data_, '\0', sizeof(data_));

        strcpy(data_, str.c_str());

        boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
                                [this, self](boost::system::error_code ec, std::size_t){
                                    if(!ec){
                                        do_read();
                                    }
                                });
    }

};

class DLFaceCountService {
    tcp::acceptor acceptor_;
    tcp::socket socket_;
    const DLWorker * w;

public:
    DLFaceCountService(boost::asio::io_service& io_service, short port, const DLWorker * worker)
            : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
              socket_(io_service){
        w = worker;
        do_accept();
    }

private:
    void do_accept(){
        acceptor_.async_accept(socket_,
        [this](boost::system::error_code ec){
            if(!ec){
                std::make_shared<Session>(std::move(socket_), std::move(w))->start();
            }

            do_accept();
        });
    }

};


#endif //DONT_LOOK_DLFACECOUNTSERVICE_H
