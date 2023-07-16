#include "Base.hpp"

Base* generate() {
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return 0;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != 0) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != 0) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != 0) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    identify(&p);
}