#include <catch.hpp>
#include <Stack.hpp>

SCENARIO("when you push an element count increases")
{
	GIVEN("Stack")
	{
		Stack<int> stack1;
		WHEN("push an element")
		{
			stack1.push(1);
			THEN("the number of elements must be equal to 1")
			{
				REQUIRE(stack1.count() == 1);
			}
		}
	}
}
