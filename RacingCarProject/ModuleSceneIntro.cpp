#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;


	//Sensor Level 1
	Cube cube_sensor(20,1,1);	
	sensor = App->physics->AddBody(cube_sensor, 0.0f);
	sensor->collision_listeners.add(this);
	sensor->SetAsSensor(true);	
	sensor->SetPos(0, 2, 20);

	//Sensor Level 2
	Cube cube_sensorStop(30, 1, 1);
	sensorStop = App->physics->AddBody(cube_sensorStop, 0.0f);
	sensorStop->collision_listeners.add(this);
	sensorStop->SetAsSensor(true);
	sensorStop->SetPos(25, 2, -100);

	Cube cube_sensorLevel2(30, 1, 1);
	sensorLevel2 = App->physics->AddBody(cube_sensorLevel2, 0.0f);
	sensorLevel2->collision_listeners.add(this);
	sensorLevel2->SetAsSensor(true);
	sensorLevel2->SetPos(25, 2, 20);

	//Sensor Level 3
	Cube cube_sensorStop2(20, 1, 1);
	sensorStop2 = App->physics->AddBody(cube_sensorStop2, 0.0f);
	sensorStop2->collision_listeners.add(this);
	sensorStop2->SetAsSensor(true);
	sensorStop2->SetPos(50, 32, -85);


	

	//Camera
	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	//Level 1
	Cube c1(2, 5, 270);
	cube = App->physics->AddBody(c1, 0);
	cube->SetPos(10, 3, 20);

	Cube c2(2, 5, 270);
	cube2 = App->physics->AddBody(c2, 0);
	cube2->SetPos(-10, 3, 20);

	Cube c3(2, 7, 2);
	cube3 = App->physics->AddBody(c3, 0);
	cube3->SetPos(0, 3, 100);
	cube3->collision_listeners.add(this);

	Cube c4(2, 5, 20);
	c4.SetRotation(90, { 0,1,0 });
	cube4 = App->physics->AddBody(c4, 0);
	cube4->SetPos(0, 3, 120);

	Cube c5(2, 5, 20);
	c5.SetRotation(90, { 0,1,0 });
	cube5 = App->physics->AddBody(c5, 0);
	cube5->SetPos(0, 3, -115);

	//Level 2
	Cube c6(2, 5, 270);
	cube6 = App->physics->AddBody(c6, 0);
	cube6->SetPos(40, 3, 20);

	Cube c7(2, 5, 270);
	cube7 = App->physics->AddBody(c7, 0);
	cube7->SetPos(15, 3, 20);

	Cube c8(2, 7, 2);
	cube8 = App->physics->AddBody(c8, 0);
	cube8->SetPos(25, 3, 100);
	cube8->collision_listeners.add(this);

	Cube c9(2, 5, 20);
	c9.SetRotation(90, { 0,1,0 });
	cube9 = App->physics->AddBody(c9, 0);
	cube9->SetPos(25, 3, 120);

	Cube c10(2, 5, 30);
	c10.SetRotation(90, { 0,1,0 });
	cube10 = App->physics->AddBody(c10, 0);
	cube10->SetPos(25, 3, -115);

	Cube c11(1, 5, 1);
	c11.SetRotation(90, { 0,1,0 });
	cube11 = App->physics->AddBody(c11, 0);
	cube11->SetPos(25, 3, 95);

	Cube c12(2, 5, 8);
	c12.SetRotation(45, { 0,1,0 });
	cube12 = App->physics->AddBody(c12, 0);
	cube12->SetPos(20, 3, 100);

	//Level 3
	Cube c13(20, 30, 35);
	cube13 = App->physics->AddBody(c13, 0);
	cube13->SetPos(50, 15, -85);

	Cube c14(20, 50, 2);
	c14.SetRotation(125, { 1,0,0 });
	cube14 = App->physics->AddBody(c14, 0);
	cube14->SetPos(50, 15, -47);

	Cube c15(20, 80, 2);
	c15.SetRotation(90, { 1,0,0 });
	cube15 = App->physics->AddBody(c15, 0);
	cube15->SetPos(50, 2, 11);

	Cube c16(20, 20, 2);
	c16.SetRotation(70, { 1,0,0 });
	cube16 = App->physics->AddBody(c16, 0);
	cube16->SetPos(50, 5, 30);

	Cube c17(20, 20, 20);
	cube17 = App->physics->AddBody(c17, 0);
	cube17->SetPos(50, 0, 80);

	Cube c19(2, 7, 2);
	cube19 = App->physics->AddBody(c19, 0);
	cube19->SetPos(57, 10, 80);
	cube19->collision_listeners.add(this);



	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	//Plane
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	Cube c3(2, 7, 2);
	c3.SetPos(0, 3, 100);
	c3.color = Red;
	c3.Render();
	

	Cube c8(2, 7, 2);
	c8.SetPos(25, 3, 100);
	c8.color = Red;
	c8.Render();
	

	Cube c19(2, 7, 2);
	c19.SetPos(57, 10, 80);
	c19.color = Red;
	c19.Render();
	
	GLDebugDrawString(xStart, yStart, text);

	/*
	//Track
	Cube c1(1, 10, 50);
	c1.SetPos(5, 0, 0);
	c1.Render();

	Cube c2(1, 10, 60);
	c2.SetPos(-5, 0, 0);
	c2.Render();

	Cube c3(1, 10, 5);
	c3.SetPos(-5, 0, 50);
	c3.SetRotation(30,vec3(0,-1,0));
	c3.Render();*/



	

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
	if (body1 == sensor && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->stop = true;
	}
	if (body1 == cube3 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->stop = false;
		App->player->nextLevel = true;
		App->player->vehicle->SetPos(25, 0, -100);
		
	}
	if (body1 == sensorStop && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->nextLevel = false;
		App->player->level1 = false;
		App->player->level2 = true;

	}
	if (body1 == sensorLevel2 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->stop = true;
	}
	if (body1 == cube8 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->stop = false;
		App->player->nextLevel = true;
		App->player->vehicle->SetPos(50, 30, -85);

	}
	if (body1 == sensorStop2 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		/*App->player->nextLevel = false;
		App->player->level2 = false;
		App->player->level3 = true;*/
	}

}

