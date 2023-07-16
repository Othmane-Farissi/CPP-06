#include "Base.hpp"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Base* instance = generate();
    identify(instance);

    delete instance;

    return 0;
}
