

struct resource {
    bool is_valid() const {
        return false;
    }

    unsigned char memory[1'234'567];
};


resource* aquire_resource()
{
    resource* ret = new resource();
    
    contract_assert(ret->is_valid()); // #1
          
    if (not ret->is_valid()) {
        delete ret;                  // #2
        ret = nullptr;
    }

    return ret;
}

void release_resource(resource* r) {
    delete r;
}


// to see the leak, run with leaks detector:
// valgrind ex_leak
int main()
{
    try {
        resource* r = aquire_resource();
    } catch (...) {
    }  
}

