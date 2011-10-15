/*
 * Copyright (C) Shroom Studios, Inc - All Rights Reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Ahmad Amireh <ahmad@shroom-studios.com>, September 2011
 */

#ifndef H_PixyNet_Connection_H
#define H_PixyNet_Connection_H

#include "BaseConnection.hpp"

namespace Pixy {

  using Net::BaseConnection;
  /// Represents a single Connection from a client.
  class Connection : public BaseConnection
  {

  public:
    /// Construct a Connection with the given io_service.
    explicit Connection(boost::asio::io_service&);
    virtual ~Connection();

    bool connect(std::string host, std::string port);
    bool isConnected();
    void disconnect();

    virtual boost::shared_ptr<Connection> shared_from_this() {
      return boost::static_pointer_cast<Connection>(BaseConnection::shared_from_this());
    }

    virtual void start();
    virtual void stop();

  protected:
    //void on_ping(const message &);
    void onPing(const Event&);

    tcp::resolver resolver_;
    std::string host_, port_;
    bool connected_;

    void handle_resolve(const boost::system::error_code& err,
        tcp::resolver::iterator endpoint_iterator);
    void handle_connect(const boost::system::error_code& err,
        tcp::resolver::iterator endpoint_iterator);

  };

  typedef boost::shared_ptr<Connection> Connection_ptr;

} // namespace Pixy

#endif // H_PixyNet_Connection_H
