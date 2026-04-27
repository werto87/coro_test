#include "hello.hxx"
#include <boost/asio.hpp>
#include <print>
#include <spdlog/spdlog.h>

namespace coro_test
{

boost::asio::awaitable<void>
helloWorldEvery5Seconds ()
{
  spdlog::info ("while (true)");
  while (true)
    {
      spdlog::info ("auto timer = boost::asio::steady_timer (io_context, boost::asio::chrono::seconds (5));");
      auto ex = co_await boost::asio::this_coro::executor;
      auto timer = boost::asio::steady_timer (ex, boost::asio::chrono::seconds (5));
      spdlog::info ("co_await timer.async_wait (boost::asio::use_awaitable);");
      co_await timer.async_wait (boost::asio::use_awaitable);
      timer.expires_after (boost::asio::chrono::seconds (5));
      spdlog::info ("Hello World!");
    }
}

CoroTest::CoroTest () : ioContext{ std::make_unique<boost::asio::io_context> () } {}

void
CoroTest::printSomething ()
{
  thread = std::make_unique<std::thread> ([this] () { ioContext->run (); });
  spdlog::info ("boost::asio::co_spawn (*ioContext.get (), helloWorldEvery5Seconds (), boost::asio::detached);");
  boost::asio::co_spawn (*ioContext.get (), helloWorldEvery5Seconds (), boost::asio::detached);
}
}