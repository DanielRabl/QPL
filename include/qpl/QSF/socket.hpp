#ifndef QSF_SOCKET_HPP
#define QSF_SOCKET_HPP
#pragma once

#include <qpl/qpldeclspec.hpp>
#include <qpl/vardef.hpp>
#include <SFML/Network.hpp>
#include <string>

namespace qsf {
	struct socket {
		QPLDLL void set_address(sf::IpAddress address, qpl::u32 port);
		QPLDLL void set_address_connect(sf::IpAddress address, qpl::u32 port);
		QPLDLL void connect();
		QPLDLL void connect_until_connected();
		QPLDLL void send(std::string data);
		QPLDLL std::string receive();
		QPLDLL void disable_blocking();
		QPLDLL void enable_blocking();
		QPLDLL bool is_blocking_enabled() const;
		QPLDLL bool is_connected() const;

		bool connected = false;
		bool address_set = false;
		sf::TcpSocket socket;
		sf::TcpListener listener;

		qpl::u32 port = 0u;
		sf::IpAddress ip_address = sf::IpAddress::LocalHost;
	};
}

#endif