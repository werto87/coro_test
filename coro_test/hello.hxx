#pragma once
#include <boost/asio.hpp>
#include <string>

namespace coro_test
{
    boost::asio::awaitable<void> helloWorldEvery5Seconds ();
    void printSomething (boost::asio::io_context &io_context);
}
