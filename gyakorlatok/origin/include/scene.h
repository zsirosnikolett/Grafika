#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

typedef struct Scene
{
    Camera camera;
} Scene;


/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void update_scene(Scene* scene, double time);

#endif /* SCENE_H */

