#include <cstdlib>
#include <exception>
#include <first_app.hpp>
#include <iostream>
#include <iterator>
#include <profiler.hpp>

int main(int argc, char *argv[]) {
    PROF_INIT_PROC("Initializing App");
    rot::FirstApp app{};

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    PROF_DUMP_TRACE();

    return 0;
}
