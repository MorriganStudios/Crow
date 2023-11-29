#include "crow/crow.h"
#include "crow/window.h"

int main(int argc, char *argv[]) {
        crow_window_t *windows[4] = {
            crow_window_create(640, 480, "Crow Window 1"),
            crow_window_create(300, 300, "Crow Window 2"),
            crow_window_create(512, 128, "Crow Window 3"),
            crow_window_create(960, 720, "Crow Window 4"),
        };

        unsigned int window_count = 4;

        int i = 0;
        while (window_count) {
                crow_window_poll();

                for (i = 0; i < 4; i++) {
                        if (!windows[i]) continue;
                        if (!crow_window_should_close(windows[i])) continue;

                        crow_window_destroy(&windows[i]);
                        --window_count;
                }
        }

        return 0;
}
