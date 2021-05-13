#ifndef WEAPON_H
#define WEAPON_H

#include "camera.h"
#include "texture.h"
#include "utils.h"
#include <obj/model.h>

typedef struct
{
	float x;
	float y;
	float z;
	int move;
}Weapon;

void move_weapon();




#endif /* WEAPON_H */