/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#include "Connection.hpp"
#include "EventManager.h"
namespace Pixy {

  Connection::Connection(boost::asio::io_service& io_service)
    : base_connection(io_service),
      resolver_(io_service),
      host_(""),
      port_(""),
      connected_(false)
  {
    //message_handler_.bind(message_id::ping, this, &Connection::on_ping);

  }

  Connection::~Connection() {
    std::cout << "A Connection has been destroyed\n";
  }

  bool Connection::connect(std::string host, std::string port) {
    if (connected_) {
      std::cerr << "already connected!\n";
      return true;
    }

    host_ = host;
    port_ = port;

    tcp::resolver::query query(host_, port_);

    // Start a synchronous resolve
    boost::system::error_code ec;
    tcp::resolver::iterator endpoint = resolver_.resolve(query);
    socket_.connect(*endpoint, ec);

    if (ec) {
      std::cerr << "couldn't connect to server " << host_ << ":" << port_ << ", aborting\n";
      return false;
    }

    connected_ = true;

    // set KEEPALIVE to true
    socket_.set_option(boost::asio::socket_base::keep_alive(true));
    std::cout << "connected!\n";

    dispatcher_.bind(EventUID::Ping, this, &Connection::onPing);

    return connected_;
  }

  bool Connection::isConnected() {
    return connected_;
  }
  void Connection::disconnect() {
    send(Event(EventUID::Logout));
    stop();
  }

  void Connection::start() {
    base_connection::start();
  }
  void Connection::stop() {
    base_connection::stop();
    EventManager::getSingleton().hook(Event(EventUID::Disconnected));
  }

  /*void Connection::on_ping(const message &msg) {
    std::cout<<"got PINGED!\n";
    send(message(message_id::pong));
  }*/

  void Connection::onPing(const Event& evt) {
    std::cout<<"got PINGED!\n";
    send(Event(EventUID::Pong));
  }

} // namespace http
