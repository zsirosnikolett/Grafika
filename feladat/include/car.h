#ifndef CAR_H
#define CAR_H

#include "camera.h"
#include "texture.h"
#include "utils.h"
#include <obj/model.h>

typedef struct
{
	double jeepX;
	double jeepY;
	double jeepMove;
}Car;




void mooveJeep(Car* car,double time);

#endif /* CAR_H */