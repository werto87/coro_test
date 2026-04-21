#include "hello.hxx"
#include <print>

boost::asio::awaitable<void>
helloWorldEvery10Seconds (boost::asio::io_context &io_context)
{
  while (true)
    {
      auto timer = boost::asio::steady_timer (io_context, boost::asio::chrono::seconds (5));
      co_await timer.async_wait (boost::asio::use_awaitable);
      timer.expires_after (boost::asio::chrono::seconds (5));
      std::println ("Hello World!");
    }
}

void
printSomething (boost::asio::io_context &io_context)
{
  boost::asio::co_spawn (io_context, helloWorldEvery10Seconds (io_context), boost::asio::detached);
}
