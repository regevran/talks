
#include <iostream>

struct A {
	bool check(int) const;      // #1
	bool check(int);            // #2
    void foo(const int x)
       pre (check(x))              // calls #1
       post (check(x));            // calls #1
};

bool A::check(int) const {
    std::cout << "const check\n";
    return true;
}

bool A::check(int) {
    std::cout << "non-const check\n";
    return true;
}

void A::foo(const int x)
{
   contract_assert(check(x));  // calls #1
   if (check(x)) {}            // surprise: calls #2
}

int main()
{
    A a;
    a.foo(5);
}
