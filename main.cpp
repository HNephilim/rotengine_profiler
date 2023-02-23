#include <app/first_app.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <iterator>
#include <profiler/profiler.hpp>

int main(int argc, char *argv[]) {
    PROF_INIT_PROC("Initializing App");
    rot::FirstApp app{};

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    auto start = std::chrono::steady_clock::now();
    PROF_DUMP_TRACE();
    auto end = std::chrono::steady_clock::now();

    auto time = end - start;

    std::cout << "Time to save = " << time.count() << '\n';

    return 0;
}
