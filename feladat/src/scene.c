#include "scene.h"
#include "callbacks.h"
#include "sun.h"
#include "weapon.h"
#include "camel.h"
#include "car.h"
#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>






Rotate rotate;
Weapon weapon;
void init_scene(Scene* scene)
{
    load_model(&(scene->sand), "assets/models//sand.obj");
    load_model(&(scene->skyBox), "assets/models//sky.obj");
    load_model(&(scene->jeep), "assets/models//humvee.obj");
    load_model(&(scene->camel), "assets/models//horse.obj");
	load_model(&(scene->pyramid), "assets/models//WoodHouse.obj");
	load_model(&(scene->sun), "assets/models//sun.obj");
	load_model(&(scene->palm), "assets/models//palm.obj");
	load_model(&(scene->cactus), "assets/models//axeinwood.obj");
	load_model(&(scene->gun), "assets/models//gun.obj");
	load_model(&(scene->male), "assets/models//male.obj");
	load_model(&(scene->stone), "assets/models//trunkwood.obj");
    
	scene->tsand = load_texturer("assets/textures//desert.jpg");
	scene->tpyramid = load_texture("assets/textures//house.png");
	scene->tsky = load_texture("assets/textures//sky.jpg");
	scene->tjeep = load_texture("assets/textures//humvee.jpg");
	scene->tcamel = load_texture("assets/textures//camel.jpg");
    scene->help = load_texture("assets//help.png");
	scene->tsun = load_texture("assets/textures//sun.jpg");
	scene->tpalm = load_texture("assets/textures//palm.png");
	scene->tcactus = load_texture("assets/textures//Axe.png");
	scene->tgun = load_texture("assets/textures//gun.png");
	scene->tmale = load_texture("assets/textures//male.png");
	scene->tstone = load_texture("assets/textures//trunkwood.png");
   

  scene->material.ambient.red = 0.8;
  scene->material.ambient.green = 0.8;
  scene->material.ambient.blue = 0.8;

  scene->material.diffuse.red = 1;
  scene->material.diffuse.green = 1;
  scene->material.diffuse.blue = 1;

  scene->material.specular.red = 0.6;
  scene->material.specular.green = 0.6;
  scene->material.specular.blue = 0.6;
    
	scene->material.shininess = 20.0;

	set_lighting(scene);
    
}

void set_lighting()
{
  float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  float diffuse_light[] = { 0.7f, 0.7f, 0.7f, 0.7f };
  float specular_light[] = { 0.7f, 0.7f, 0.7f, 0.7f };
  float position[] = { 0.0f, 0.0f, 15.0f, 1.0f };
  
  float pos[4] = {0.f,5.f,1.f,100.f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    //glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT1, GL_POSITION, pos);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}



void mooveJeep(Car* car,double time) {
    car->jeepX-=time/15;
    car->jeepY+=time/15;
    car->jeepMove+=time*15;
}

void camelMove(Camel * camel,double time) {
    camel->rideCamel+=time/2;
}

void move_weapon() {
	
	
	if(abs(camera.position.x) < 100 && abs(camera.position.y) < 100)
	{
		if (abs((int)(camera.position.x - weapon.x)) < 5 && abs((int)(camera.position.y - weapon.y)) < 5 && camera.position.z < 5)
			{
				weapon.x = camera.position.x +0.5 ;
				weapon.y = camera.position.y -3;	
			}	
	}
}

void object_rotation(Rotate *rotate)
{
	if (rotate->rotate_obj == TRUE)
	{
		rotate->sun_rotation += 0.1;
	}
}

void draw_scene(const Scene* scene, Rotate* rotate,Weapon* weapon,Camel * camel,Car* car)
{
		set_material(&(scene->material));
		
		
		
        glPushMatrix();
		glTranslatef(0, 0, 0);
		glBindTexture(GL_TEXTURE_2D,scene->tsand);
		draw_model(&(scene->sand));
		glPopMatrix();
       
		glPushMatrix();
		glTranslatef(30, 50, 30);
		glRotatef(rotate->sun_rotation, 1, 1, 1);
		glBindTexture(GL_TEXTURE_2D,scene->tsun);
		draw_model(&(scene->sun));
		glPopMatrix();	
		
		glPushMatrix();
		glTranslatef(0,0,0);
		glBindTexture(GL_TEXTURE_2D,scene->tsky);
		draw_model(&(scene->skyBox));
		glPopMatrix();
			
        glPushMatrix();        
		glTranslatef(20, 16-camel->rideCamel, 0.55);
		glRotatef(-90.0,0.0,0.0,1.0);
		glBindTexture(GL_TEXTURE_2D,scene->tcamel);
		draw_model(&(scene->camel));
		glPopMatrix();
		
        glPushMatrix();
	    glRotatef(70+car->jeepMove, 0, 0, 1);
		glTranslatef(-25-car->jeepX, -25-car->jeepY, 0.5);
		glBindTexture(GL_TEXTURE_2D,scene->tjeep);
		draw_model(&(scene->jeep));
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-14, 12, 0.1);
		glBindTexture(GL_TEXTURE_2D,scene->tpyramid);
		draw_model(&(scene->pyramid));
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(-18, -8, 0.3);
		glBindTexture(GL_TEXTURE_2D,scene->tpalm);
		draw_model(&(scene->palm));
		glPopMatrix();
		
		
		glPushMatrix();
		glTranslatef(18, -10, 0.3);
		glBindTexture(GL_TEXTURE_2D,scene->tpalm);
		draw_model(&(scene->palm));
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(0, -22, 0.3);
		glBindTexture(GL_TEXTURE_2D,scene->tstone);
		draw_model(&(scene->stone));
		glPopMatrix();
		
		glPushMatrix();
		
		glBindTexture(GL_TEXTURE_2D,scene->tcactus);
		glTranslatef(0, -22, 1.0);
		glRotatef(-90.0,0.0,0.0,1.0);
		draw_model(&(scene->cactus));
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(weapon->x, 5+weapon->y, 0.4);
		glBindTexture(GL_TEXTURE_2D,scene->tgun);
		draw_model(&(scene->gun));
		glPopMatrix();
		
		glPushMatrix();
		glBindTexture(GL_TEXTURE_2D,scene->tmale);
		glTranslatef(20, 16-camel->rideCamel, 2.4);
		draw_model(&(scene->male));
		glPopMatrix();
		
		glBindTexture(GL_TEXTURE_2D,scene->help); 
		
		
}
		
		
        

		
	