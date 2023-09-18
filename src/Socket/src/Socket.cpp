/**
 * @copyright Copyright (c) 2023@file Socket.cpp
 * 
 * @author  Hugo Fernández Solís (hugofernandezsolis@gmail.com)
 * @file    Socket.cpp
 * 
 * @brief 
 */


#include <Socket.h>


namespace ipc {


/**
 * @brief Create a socket address object.
 * @param iIpAddr The IP address for the socket address (default is localhost).
 * @param iPort   The port number for the socket address (default is random).
 * @return The created socket address structure.
 */
addr_t create_addr(const ipAddr_t& iIpAddr, const port_t& iPort) {
  addr_t socketAddr;
  std::memset(&socketAddr, 0, sizeof(socketAddr));
  socketAddr.sin_family = AF_INET;
  socketAddr.sin_port = htons(iPort);
  inet_pton(AF_INET, iIpAddr.data(), &(socketAddr.sin_addr));
  return socketAddr;
}


/**
 * @brief Construct a new Socket object.
 * @param iAddr Address of the socket.
 */
Socket::Socket(const addr_t& iAddr) {
  set_fd(-1);
  set_addr(iAddr);
  set_status(STATUS_NOT_OPEN);
}

/**
 * @brief Get a const reference to the socket address structure.
 * @return A const reference to the socket address structure.
 */
const addr_t& Socket::get_addr(void) const {
  return addr_;
}

/**
 * @brief Get a const reference to the status of the socket.
 * @return A const reference to the status of the socket.
 */
const status_e& Socket::get_status(void) const {
  return status_;
}

/**
 * @brief Get the class information as a string
 * @return String with the class information. 
 */
std::string Socket::to_string(void) const {
  return (
    "Socket " + std::to_string(fd_) + " connected to " + std::string(get_ipAddr()) + ":" +
    std::to_string(get_port()) + "."
  );
}

/**
 * @brief Destructor for the Socket class, closing open sockets.
 */
Socket::~Socket() {
  close(fd_);
}

/**
 * @brief Get a copy of the ipAddr of the socket.
 * @return A copy of the ipAddr of the socket.
 */
ipAddr_t Socket::get_ipAddr(void) const {
  char ipStr[INET_ADDRSTRLEN];
  if (inet_ntop(AF_INET, &(addr_.sin_addr), ipStr, sizeof(ipStr)) != nullptr) {
    return std::string(ipStr);
  }
  else {
    return IP_NO_IP;
  }
}

/**
 * @brief Get a copy of the connection port of the socket.
 * @return A copy of the connection port of the socket.
 */
port_t Socket::get_port(void) const {
  return ntohs(addr_.sin_port);
}

/**
 * @brief Set the socket identifier.
 * @param iFd The socket identifier to set.
 */
void Socket::set_fd(const fd_t& iFd) {
  fd_ = iFd;
}

/**
 * @brief Set the socket address structure.
 * @param iAddr The socket address structure to set.
 */
void Socket::set_addr(const addr_t& iAddr) {
  addr_ = iAddr;
}

/**
 * @brief Set the status of the socket.
 * @param iStatus The status to set for the socket.
 */
void Socket::set_status(const status_e& iStatus) {
  status_ = iStatus;
}


} // namespace ipc