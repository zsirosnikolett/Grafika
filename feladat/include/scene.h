#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "sun.h"
#include "car.h"
#include "weapon.h"
#include "camel.h"

#include <obj/model.h>

typedef struct Scene
{
    Camera camera;
	Model sand;
    Model skyBox;
    Model jeep;
	Model camel;
	Model pyramid;
	Model sun;
	Model palm;
	Model cactus;
	Model gun;
	Model male;
	Model stone;
    Material material;
	GLuint tsand;
	GLuint fu;
	GLuint tsky;
	GLuint tjeep;
	GLuint tcamel;
    GLuint help;
	GLuint tpyramid;
	GLuint tsun;
	GLuint tpalm;
	GLuint tcactus;
	GLuint tgun;
	GLuint tmale;
	GLuint tstone;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene,Rotate* rotate,Weapon* weapon,Camel* camel,Car* car);




#endif /* SCENE_H */
