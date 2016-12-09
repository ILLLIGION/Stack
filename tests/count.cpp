#include <catch.hpp>
#include <Stack.hpp>

SCENARIO("when you use count() it must return the number of elements in your stack")
{
        GIVEN("Stack")
        {
                Stack<int> stack1;
		Stack<int> stack2;
		stack2.push(1);
                WHEN("count()")
                {
                        THEN("number of elements in the first stack must be equal to 0, of the second - to 1")
                        {
                                REQUIRE(stack1.count() == 0);
				REQUIRE(stack2.count() == 1);
                        }
                }
        }
}

