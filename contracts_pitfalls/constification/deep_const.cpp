


void foo(int* p, int x) 
    // pre (++x)    // error
    pre (++*p)      // ok
{}

void goo() {
   int i = 41;
   foo(&i, i);

   contract_assert(i==41); // violation
}

int main() {
    goo();
    return 0;
}
