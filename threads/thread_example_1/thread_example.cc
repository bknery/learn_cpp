// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
  std::cout << "Foo started running" << std::endl;
  for(int i = 0; i < 10; i++)
  {
    std::cout << "Foo " << i << std::endl;
  }
}

void bar(int x)
{
  std::cout << "Bar started running" << std::endl;
  for(int i = 0; i < 10; i++)
  {
    std::cout << "Bar " << i << std::endl;
  }
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  std::cout << "first join." << std::endl;
  second.join();               // pauses until second finishes
  std::cout << "second join." << std::endl;

  std::cout << "foo and bar completed.\n";

  return 0;
}
