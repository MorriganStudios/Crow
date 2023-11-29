#ifndef _CROW_WINDOW_H_
#define _CROW_WINDOW_H_

#include "crow/types.h"

typedef struct crow_window crow_window_t;

crow_window_t *crow_window_create(int width, int height, const char *title);
void crow_window_destroy(crow_window_t **window);
bool crow_window_should_close(const crow_window_t *window);
void crow_window_poll();

#endif /* ifndef _CROW_WINDOW_H_ */
