// This file is just a helper to know how to use the Singleton class.

#include "Singleton.hpp"

#include <iostream>
#include <cassert>

class TestClass {
    public:
        std::int32_t value = 0;
};

int main()
{
    TestClass& instance1 = RayTracer::Shared::Singleton<TestClass>::getInstance();
    TestClass& instance2 = RayTracer::Shared::Singleton<TestClass>::getInstance();

    instance1.value = 42;

    assert(&instance1 == &instance2);
    assert(instance2.value == 42);

    std::cout << "Singleton test passed!" << std::endl;
    return 0;
}
