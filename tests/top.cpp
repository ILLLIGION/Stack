#include "catch.hpp"
#include <Stack.hpp>

SCENARIO("returns the last element of stack")
{
    GIVEN("stack")
    {
        Stack<int> stack1;
        stack1.push(1);
        WHEN("top")
        {
            int topped_element = stack1.top();
            THEN("must return 1")
            {
                REQUIRE(topped_element == 1);
            }
        }
    }
}

SCENARIO("if stack is empty, top method must throw an exception")
{
    GIVEN("empty stack")
    {
        Stack<int> stack2;

        WHEN("top")
        {
            THEN("return nullptr")
            {
                REQUIRE_THROWS_AS(stack2.top(), std::underflow_error&);
            }
        }
    }
}
