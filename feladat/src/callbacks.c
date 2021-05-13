#include "callbacks.h"
#include "sun.h"
#include "weapon.h"
#include "camel.h"
#include "car.h"
#define VIEWPORT_RATIO (16.0 / 9.0)
#define VIEWPORT_ASPECT 50.0



Rotate rotate;
Weapon weapon;
Camel camel;
Car car;
int fogLevel = 0;

struct {
    int x;
    int y;
} mouse_position;

void display(void)
{
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&camera);
    draw_scene(&scene,&rotate,&weapon,&camel,&car);
	object_rotation(&rotate);
	
    glPopMatrix();
	
    if (is_help_visible) {
        show_helpmenu();
    }
	
    glutSwapBuffers();
}





void fog()
{
	float fogColor[] = {1.0, 0.7, 0.8};
	if (0 < fogLevel)
	{
		glEnable(GL_FOG);

		glHint(GL_FOG_HINT, GL_NICEST);
		if (1 == fogLevel)
		{
			glFogf(GL_FOG_DENSITY, 0.03);
			glFogi(GL_FOG_MODE, GL_EXP);
		}
		if (2 == fogLevel)
		{
			glFogf(GL_FOG_DENSITY, 0.07);
			glFogi(GL_FOG_MODE, GL_EXP2);
		}
		if (3 == fogLevel)
		{
			glFogf(GL_FOG_DENSITY, 0.1);
			glFogi(GL_FOG_MODE, GL_EXP2);
		}
		glFogf(GL_FOG_START, 1);
		glFogf(GL_FOG_END, 1000.0);
		glFogfv(GL_FOG_COLOR, fogColor);
	}
	else
	{
		glDisable(GL_FOG);
	}
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEWPORT_ASPECT, VIEWPORT_RATIO, 0.01, 10000.0);
}

void mouse(int button, int state, int x, int y)
{
    mouse_position.x = x;
    mouse_position.y = y;
}

void motion(int x, int y)
{
    rotate_camera(&camera, mouse_position.x - x, mouse_position.y - y);
    mouse_position.x = x;
    mouse_position.y = y;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y, int z)
{
    switch (key) {
	case 'W':
    case 'w':
        set_camera_speed(&camera, 6);
        break;
    case 'S':
	case 's':
        set_camera_speed(&camera, -6);
        break;
	case 'A':
    case 'a':
        set_camera_side_speed(&camera, 6);
        break;
	case 'D':
    case 'd':
        set_camera_side_speed(&camera, -6);
        break;
	case 'E':
	case 'e':
		set_camera_vertical_speed(&camera, 3);
		break;
	case 'x':
	case 'X':
			rotate.rotate_obj = !rotate.rotate_obj;
		break;
	case 'J':
	case 'j':
		weapon.move = TRUE;
		break;
	case 27:
		exit(0);
	case 'Q':
	case 'q':
		set_camera_vertical_speed(&camera, -3);
		break;
        case '+':
      ;
      GLfloat current_ambient[4], current_diffuse[4], current_specular[4];
      glGetLightfv( GL_LIGHT0, GL_AMBIENT, current_ambient );
      glGetLightfv( GL_LIGHT0, GL_DIFFUSE, current_diffuse );
      glGetLightfv( GL_LIGHT0, GL_SPECULAR, current_specular );

      if ( current_specular[3] < 1.0f ) {

        int i;
        for ( i = 0; i < 3; i++) {
          current_ambient[i] += 0.025f;
          current_diffuse[i] += 0.025f;
          current_specular[i] += 0.025f;
        }

        glLightfv( GL_LIGHT0, GL_AMBIENT, current_ambient );
        glLightfv( GL_LIGHT0, GL_DIFFUSE, current_diffuse );
        glLightfv( GL_LIGHT0, GL_SPECULAR, current_specular );
      }

      break;

    case '-':
      ;
      glGetLightfv( GL_LIGHT0, GL_AMBIENT, current_ambient );
      glGetLightfv( GL_LIGHT0, GL_DIFFUSE, current_diffuse );
      glGetLightfv( GL_LIGHT0, GL_SPECULAR, current_specular );

      if ( current_specular[3] > 0.0f ) {

        int i;
        for ( i = 0; i < 3; i++ ) {
          current_ambient[i] -= 0.025f;
          current_diffuse[i] -= 0.025f;
          current_specular[i] -= 0.025f;
        }

        glLightfv( GL_LIGHT0, GL_AMBIENT, current_ambient );
        glLightfv( GL_LIGHT0, GL_DIFFUSE, current_diffuse );
        glLightfv( GL_LIGHT0, GL_SPECULAR, current_specular );
      }

      break;
    case 'f':
	case 'F':
		if (3 == fogLevel)
		{
			fogLevel = 0;
			fog();
		}
		else
		{
			fogLevel++;
			fog();
		}
		break;
	break;
	  case 'K':
      case 'k':
        if(camel.ride == 0) {
            camel.ride = 1;
        } else {
            camel.ride = 0;
        }
        break;
	case 'T':
	case 't':
        if (is_help_visible) {
            is_help_visible = FALSE;
        }
        else {
            is_help_visible = TRUE;
        }
        break;
    }

    glutPostRedisplay();
}

void keyboard_up(unsigned char key, int x, int y, int z)
{
    switch (key) {
	case 'W':
    case 'S':
	case 'w':
    case 's':
        set_camera_speed(&camera, 0.0);
        break;
    case 'a':
    case 'd':
	case 'A':
	case 'D':
        set_camera_side_speed(&camera, 0.0);
        break;
	case 'q':
	case 'e':
	case 'E':
	case 'Q':
		set_camera_vertical_speed(&camera, 0.0);
		break;
	case 'j':
	case 'J':
		weapon.move = FALSE;
		break;
    }

    glutPostRedisplay();
}


void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;
    update_camera(&camera, elapsed_time);
    mooveJeep(&car,elapsed_time);
    if ( weapon.move == TRUE) {
		move_weapon();
	}
    if(camel.ride == 1) {
        camelMove(&camel,elapsed_time);
    }
    glutPostRedisplay();
}
