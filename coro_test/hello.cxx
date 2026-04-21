#include "hello.hxx"
#include <print>
#include <spdlog/spdlog.h>

namespace coro_test
{

boost::asio::awaitable<void>
helloWorldEvery10Seconds (boost::asio::io_context &io_context)
{
  spdlog::info ("while (true)");
  while (true)
    {
      spdlog::info ("auto timer = boost::asio::steady_timer (io_context, boost::asio::chrono::seconds (5));");
      auto timer = boost::asio::steady_timer (io_context, boost::asio::chrono::seconds (5));
      spdlog::info ("co_await timer.async_wait (boost::asio::use_awaitable);");
      co_await timer.async_wait (boost::asio::use_awaitable);
      timer.expires_after (boost::asio::chrono::seconds (5));
      spdlog::info ("Hello World!");
    }
}

void
printSomething (boost::asio::io_context &io_context)
{
  spdlog::info ("boost::asio::co_spawn (io_context, helloWorldEvery10Seconds (io_context), boost::asio::detached);");
  boost::asio::co_spawn (io_context, helloWorldEvery10Seconds (io_context), boost::asio::detached);
}
}