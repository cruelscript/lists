#include <iostream>

#include "QueueArray.hpp"
#include "QueueList.hpp"

int main()
{
  try
  {
    QueueArray<int> queue;

    queue.enQueue(4);
    queue.enQueue(7);
    queue.enQueue(33);
    queue.enQueue(765);

    queue.out(std::cout);
    std::cout << "\n___________________________\n";
    std::cout << queue.deQueue() << " ";
    std::cout << queue.deQueue() << " ";
    std::cout << queue.deQueue();
    std::cout << "\n___________________________\n";

    queue.out(std::cout);

    //reaching borders of the array
    for(int i = 0; i < 99; i++)
    {
      queue.enQueue(i);
    }
    queue.deQueue();
    queue.enQueue(777);
    queue.out(std::cout);


    std::cout << "\n___________________________\n";

    QueueList<int> queueList;

    queueList.enQueue(44);
    queueList.enQueue(32);
    queueList.enQueue(75);
    queueList.enQueue(76);

    queueList.out(std::cout);

    std::cout << queueList.deQueue() << " ";
    std::cout << queueList.deQueue() << " ";
    std::cout << queueList.deQueue();

    queueList.out(std::cout);

  }
  catch(const std::exception& e)
  {
    std::cerr << e.what();
  }
  return 0;
}
