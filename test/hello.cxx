#include "coro_test/hello.hxx"
#include <catch2/catch_test_macros.hpp>

TEST_CASE ("hello", "[hello]") { 
  boost::asio::io_context io_context;
  coro_test::printSomething (io_context);
  io_context.run ();
}