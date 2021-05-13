#ifndef SUN_H
#define SUN_H

#include "camera.h"
#include "texture.h"
#include "utils.h"
#include <obj/model.h>

typedef struct
{
	double sun_rotation;
	GLboolean rotate_obj;
}Rotate;

void object_rotation(Rotate *rotate);


#endif /* SUN_H */