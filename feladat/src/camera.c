#include "camera.h"
#include <GL/glut.h>

#include <math.h>
#include "sun.h"
#include "weapon.h"
#include "callbacks.h"

#define UPDATE_SPEED 15 
Weapon weapon;
void init_camera(Camera* camera)
{
    camera->position.x = 0.0;
    camera->position.y = 0.0;
    camera->position.z = 1.1;
    camera->rotation.x = 0.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 0.0;
    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;

    is_help_visible = FALSE;
}

void update_camera(Camera* camera, double time)
{
    double angle;
    double side_angle;
	double vert_angle;

	if (camera->position.x >= 39.5) {
		camera->position.x += -UPDATE_SPEED * time;
	}
	else if (camera->position.x <= -39.5) {
		camera->position.x += UPDATE_SPEED * time;
	}

	if (camera->position.y >= 39.5) {
    	camera->position.y += -UPDATE_SPEED * time;
	}
	else if (camera->position.y <= -39.5) {
    	camera->position.y += UPDATE_SPEED * time;
	}
	
    
	if (camera->position.z <= 0.7) {
    	camera->position.z += UPDATE_SPEED * time;
	}
	
    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);
	vert_angle = degree_to_radian(camera->rotation.y + 90.0);
	
    camera->position.x += cos(angle) * camera->speed.y * time;
    camera->position.y += sin(angle) * camera->speed.y * time;
    camera->position.x += cos(side_angle) * camera->speed.x * time;
    camera->position.y += sin(side_angle) * camera->speed.x * time;
	camera->position.z += cos(vert_angle) * camera->speed.z * time;
	camera->position.z += sin(vert_angle) * camera->speed.z * time;
	
	
	
}

void set_view(const Camera* camera)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
}

void rotate_camera(Camera* camera, double horizontal, double vertical)
{
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}

void set_camera_vertical_speed(Camera* camera, double speed)
{
	camera->speed.z = speed;
}

void show_helpmenu()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, -3);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -3);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, -3);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
}

