

#define BOOST_TEST_MODULE My Test 
#include <boost/test/included/unit_test.hpp> 

bool mitigation_1(int min, int max, int x) {
    return x > min and x < max;
}

void the_function_to_test_its_contracts(int x) noexcept
    pre(x > 0)
    pre(x < 10) {
//    std::cout << "body of tested function\n";
}

BOOST_AUTO_TEST_CASE(mitigation_test) 
{
    BOOST_CHECK(
        not mitigation_1(0, 10, 11)
    );
}


BOOST_AUTO_TEST_CASE(first_test) 
{
    BOOST_CHECK_THROW(
        the_function_to_test_its_contracts(11),
        std::logic_error
    );
}


BOOST_AUTO_TEST_CASE(second_test) 
{
    BOOST_CHECK_NO_THROW(
        the_function_to_test_its_contracts(5)
    );
}


