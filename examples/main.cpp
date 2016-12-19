#include <Stack.hpp>
#include <iostream>

int main()
{
    Stack<int> stack1;
    std::cout << stack1.count() << std::endl;

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    std::cout << stack1.count() << std::endl;

    //int a = stack1.pop();
    //std::cout << "poped number must be 3: " << a << std::endl;
    std::cout << stack1.count() << std::endl;
    return 0;
}
