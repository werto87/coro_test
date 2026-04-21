#include "src/hello.hxx"
#include <print>

int
main ()
{
  boost::asio::io_context io_context;
  printSomething (io_context);
  io_context.run ();
  return 0;
}