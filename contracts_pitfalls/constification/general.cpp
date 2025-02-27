

struct A {
	bool check(int) const;      // #1
	bool check(int);            // #2
    void foo();
};

bool A::check(int) const {
    std::cout << "const check";
    return true;
}

bool A::check(int) {
    std::cout << "non-const check";
    return true;
}

void foo()
   pre (check(x))              // calls #1
   post (check(x));            // calls #1
{
   contract_assert(check(x))   // calls #1
   if (check(x)) {...}         // surprise: calls #2
}

int main()
{
    A a;
    a.foo();
}
