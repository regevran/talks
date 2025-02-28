

#define BOOST_TEST_MODULE My Test 
#include <boost/test/included/unit_test.hpp> 

void the_function_to_test_its_contracts(int x) noexcept
    pre(x > 0)
    pre(x < 10) {

    // when the body of this function 
    // is empty, the result is:
    // the thrown exception from the handler _crosses_
    // the noexcpt and propegates to the caller
    // (thus the test passes)

    // std::cout << "body of tested function\n";
}

BOOST_AUTO_TEST_CASE(first_test) 
{
    BOOST_CHECK_THROW(
        the_function_to_test_its_contracts(11),
        std::logic_error
        //std::bad_alloc
    );
}

BOOST_AUTO_TEST_CASE(second_test) 
{
    BOOST_CHECK_NO_THROW(
        the_function_to_test_its_contracts(5)
    );
}

bool mitigation_1(int min, int max, int x) {
    return x > min and x < max;
}


BOOST_AUTO_TEST_CASE(mitigation_test) 
{
    BOOST_CHECK(
        not mitigation_1(0, 10, 11)
    );
}

