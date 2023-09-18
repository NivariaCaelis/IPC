/**
 * @copyright Copyright (c) 2023@file Socket.h
 * 
 * @author  Hugo Fernández Solís (hugofernandezsolis@gmail.com)
 * @file    Socket.h
 * 
 * @brief 
 */


#ifndef SOCKET_H
#define SOCKET_H


#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include <cstring>
#include <iostream>


namespace ipc {   // Inter-Process Communication


/**
 * Define socket-related types.
 */
typedef int                 fd_t;           // File descriptor of a Socket.
typedef int                 port_t;         // Port number for socket connection
typedef std::string         message_t;      // Message to be sent
typedef std::string_view    ipAddr_t;       // IP address of the socket
typedef struct sockaddr_in  addr_t;         // Socket address structure

enum status_e {   // Connection status of the socket
  STATUS_NOT_OPEN   = 0,      // Socket is in an undefined status
  STATUS_OPEN       = 1,      // Socket is open but not connected 
  STATUS_CONNECTED  = 2       // Socket is open and connected (Only TCP)
};


/**
 * Define IPC Socket-related constants
 */
constexpr port_t  PORT_RANDOM = 0;    // Special value to assign a random port

constexpr size_t  BUFFER_SIZE = 4096;   // Max size, in bytes, of a message.

constexpr ipAddr_t  IP_NO_IP      = "0.0.0.0";      // Special value to assign no IP to the socket
constexpr ipAddr_t  IP_LOCAL_HOST = "127.0.0.1";    // Special value to assign socket to local address


/**
 * @brief Create a socket address object.
 * @param iIpAddr The IP address for the socket address (default is localhost).
 * @param iPort   The port number for the socket address (default is random).
 * @return The created socket address structure.
 */
addr_t create_addr(const ipAddr_t& iIpAddr = IP_LOCAL_HOST, const port_t& iPort = PORT_RANDOM);


/**
 * @class Socket
 * @brief A base class providing basic socket functionality for IPC.
 */
class Socket {
  public:
    /**
     * @brief Construct a new Socket object.
     * @param iAddr Address of the socket.
     */
    Socket(const addr_t& iAddr);

    /**
     * @brief Get a const reference to the socket address structure.
     * @return A const reference to the socket address structure.
     */
    [[nodiscard]] const addr_t& get_addr(void) const;

    /**
     * @brief Get a const reference to the status of the socket.
     * @return A const reference to the status of the socket.
     */
    [[nodiscard]] const status_e& get_status(void) const;

    /**
     * @brief Get the class information as a string
     * @return String with the class information. 
     */
    [[nodiscard]] std::string to_string(void) const;

    /**
     * @brief Destructor for the Socket class, closing open sockets.
     */
    ~Socket();
  
  protected:

    /**
     * @brief Get a copy of the ipAddr of the socket.
     * @return A copy of the ipAddr of the socket.
     */
    [[nodiscard]] ipAddr_t get_ipAddr(void) const;

    /**
     * @brief Get a copy of the connection port of the socket.
     * @return A copy of the connection port of the socket.
     */
    [[nodiscard]] port_t get_port(void) const;

  /**
   * @brief Set the socket identifier.
   * @param iFd The socket identifier to set.
   */
  void set_fd(const fd_t& iFd);

  /**
   * @brief Set the socket address structure.
   * @param iAddr The socket address structure to set.
   */
  void set_addr(const addr_t& iAddr);

  /**
   * @brief Set the status of the socket.
   * @param iStatus The status to set for the socket.
   */
  void set_status(const status_e& iStatus);


  private:
    fd_t      fd_;          // Socket file descriptor
    addr_t    addr_;        // Socket address
    status_e  status_;      // Status of the socket


  friend std::ostream& operator<<(std::ostream& os, const Socket& iSocket) {
    os << iSocket.to_string();
    return os;
  }
};


} // namespace ipc


#endif // SOCKET_H