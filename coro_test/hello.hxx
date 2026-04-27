#pragma once

#include <memory>
#include <thread>

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
  ~CoroTest ();

  void printSomething ();
  void shutdown ();

  std::unique_ptr<std::thread> thread;
  std::unique_ptr<boost::asio::io_context> ioContext;
};
}
