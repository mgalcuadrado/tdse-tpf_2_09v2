#include "frame_buffer.h"

int frameBufferUpdate_llamadas = 0;

void frameBufferUpdate(Matriz_t* matriz) {
    (void)matriz;
    frameBufferUpdate_llamadas++;
}
