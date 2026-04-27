#include "coro_test/hello.hxx"
#include <print>

int
main ()
{
  coro_test::CoroTest coro_test;
  coro_test.printSomething ();
  while (1)
    ;
  return 0;
}