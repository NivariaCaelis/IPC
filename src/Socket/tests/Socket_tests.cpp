/**
 * @copyright Copyright (c) 2023@file Socket_tests.cpp
 * 
 * @author  Hugo Fernández Solís (hugofernandezsolis@gmail.com)
 * @file    Socket_tests.cpp
 * 
 * @brief 
 */


#include <gtest/gtest.h>

#include <Socket.h>


namespace ipc {


TEST(Socket, BasicTest) {
  const port_t port = 42354;
  const ipAddr_t ipAddr = IP_LOCAL_HOST;
  addr_t addr = create_addr(ipAddr, port);
  Socket sock(addr);
  
  EXPECT_EQ(sock.get_status(), 32);
}


} // namespace ipc