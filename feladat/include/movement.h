#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "camera.h"
#include "texture.h"
#include "utils.h"
#include <obj/model.h>

typedef struct
{
	double sun_rotation;
}Rotate;


typedef struct
{
	float x;
	float y;
	float z;
	int move;
}Weapon;

void object_rotation(Rotate *rotate);
void move_weapon();
void camelMove(double time);
void mooveJeep(double time);

#endif /* MOVEMENT_H */