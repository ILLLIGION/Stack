#include <catch.hpp>
#include <Stack.hpp>

SCENARIO("when you pop an element count decreases")
{
        GIVEN("Stack")
        {
                Stack<int> stack1;
		stack1.push(1);
		stack1.push(2);
                WHEN("pop an element")
                {
                        int a = stack1.pop();
                        THEN("the number of elements must be equal to 1")
                        {
                                REQUIRE(stack1.count() == 1);
				REQUIRE(a == 2);
                        }
                }
        }
}

