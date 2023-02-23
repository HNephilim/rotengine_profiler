#include "first_app.hpp"
#include "GLFW/glfw3.h"
#include <profiler.hpp>
#include <window.hpp>

namespace rot {
void FirstApp::run() {
    PROF_SCOPED(PROF_LVL_ALL, __func__);
    while (!rotWindow.shouldClose()) {
        PROF_SCOPED(PROF_LVL_ALL, "Frame");
        glfwPollEvents();
    }
}
} // namespace rot
