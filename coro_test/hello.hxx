#pragma once

#include <memory>

namespace std
{
class thread;
}

namespace boost::asio
{
class io_context;
}

namespace coro_test
{

class CoroTest
{
public:
  CoroTest ();

  void printSomething ();

  std::unique_ptr<std::thread> thread{};
  std::unique_ptr<boost::asio::io_context> ioContext{};
};
}
