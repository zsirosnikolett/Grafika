#ifndef CAMEL_H
#define CAMEL_H

#include "camera.h"
#include "texture.h"
#include "utils.h"
#include <obj/model.h>

typedef struct
{
	double rideCamel;
	double ride;
}Camel;

void camelMove(Camel* camel ,double time);

#endif /* CAMEL_H */