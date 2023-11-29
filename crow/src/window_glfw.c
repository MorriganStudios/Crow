#include "crow/types.h"
#include "crow/window.h"
#include <malloc/_malloc.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

struct crow_window {
        GLFWwindow *glfw_window;
};

static bool glfw_initialized = false;

static unsigned int window_count = 0;

crow_window_t *crow_window_create(int width, int height, const char *title) {
        crow_window_t *crow_window =
            (crow_window_t *)malloc(sizeof(struct crow_window));
        if (!crow_window) return 0;

        if (!glfw_initialized) {
                if (!glfwInit()) return 0;
                glfw_initialized = true;
        }

        GLFWwindow *glfw_window = glfwCreateWindow(width, height, title, 0, 0);

        crow_window->glfw_window = glfw_window;
        ++window_count;

        return crow_window;
}

void crow_window_destroy(crow_window_t **window) {
        if (!window || !*window) return;

        if ((*window)->glfw_window) glfwDestroyWindow((*window)->glfw_window);

        free(*window);
        *window = NULL;

        --window_count;
        if (glfw_initialized && window_count <= 0) {
                glfwTerminate();
                glfw_initialized = false;
        }
}

bool crow_window_should_close(const crow_window_t *window) {
        return glfwWindowShouldClose(window->glfw_window);
}

void crow_window_poll() { glfwPollEvents(); }
