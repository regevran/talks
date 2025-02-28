

#include <list>
#include <algorithm>

std::list<int>::iterator algo_phase_3(
    std::list<int>& the_list,
    std::list<int>::iterator it
) 
    post(ret: ret != the_list.end())  // #1
{
    // remove 3 even elemnts
    auto count = 0;

    while (it != the_list.end()) {
        if (*it % 2 == 0) {
            ++count;
            the_list.erase(it);
        }
        if (count == 3) {
            break;
        }
        ++it;
    }

    contract_assert(it != the_list.end());

    return it;
}

void foo()
{
    std::list<int> v;
    std::list<int>::iterator it = v.begin();
    std::list<int>::const_iterator const_it = v.end();

    if (it != const_it) {
        // do stuff
    }
}

