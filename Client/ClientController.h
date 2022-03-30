#pragma once
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

class ClientController
{
private:
	std::string ip = "127.0.0.1";
	int port = 8080;

public:
	std::string ResiveData()
	{
			boost::asio::io_service io_server;
			boost::asio::ip::tcp::socket sock(io_server);
			boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::from_string(ip), port);
			sock.connect(ep);
			std::string msg = "get";
			msg.append("\n");
			sock.write_some(boost::asio::buffer(msg));
			boost::asio::streambuf buff;
			std::ostringstream copy;
			size_t bytes = read_until(sock, buff, '\n');
			copy.str("");
			copy << &buff;
			copy << &buff;
			std::string str_pat;
			std::string tmp;
			std::string list = copy.str();
			for (int i = 0; i < list.length(); i++) {
				while (list[i] != '\n'){
					tmp += list[i++];
				}
				str_pat = str_pat + "\n" + tmp;
				tmp = "";
				i++;
				while (list[i] != '\n'){
					tmp += list[i++];
				}
				str_pat = str_pat + "\n" + tmp;
				tmp = "";
				i++;
				
				tmp += list[i++];
				str_pat = str_pat + "\n" + tmp;
				tmp = "";
				}
			return str_pat;
	}
};
