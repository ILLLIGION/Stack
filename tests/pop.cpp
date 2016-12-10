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
SCENARIO("when you try to pop an element from an empty stack count must stay 0 and throw an exception")
{
	GIVEN("Empty Stack")
	{
		Stack<int> stack2;
		WHEN("pop an elemet")
		{
			THEN("nothing really happens, count is still 0")
			{
				REQUIRE_THROWS_AS(stack2.pop(), l_error);
				REQUIRE(stack2.count() == 0);
			}
		}
	}
}

