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


	//
	Cube cube_sensor(1,1,1);	
	sensor = App->physics->AddBody(cube_sensor, 0.0f);
	sensor->collision_listeners.add(this);
	sensor->SetAsSensor(true);	
	sensor->SetPos(0, 2, 20);


	

	//
	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	//Track
	Cube c1(2, 5, 200);
	cube = App->physics->AddBody(c1, 0);
	cube->SetPos(10, 3, -20);

	Cube c2(2, 5, 200);
	cube2 = App->physics->AddBody(c2, 0);
	cube2->SetPos(-10, 3, -20);

	Cube c3(2, 5, 200);
	c3.SetRotation(90, { 0,1,0 });
	cube3 = App->physics->AddBody(c3, 0);
	cube3->SetPos(-90, 3, 100);

	Cube c4(2, 5, 20);
	cube4 = App->physics->AddBody(c4, 0);
	cube4->SetPos(10, 3, 90);

	Cube c5(2, 5, 180);
	c5.SetRotation(90, { 0,1,0 });
	cube5 = App->physics->AddBody(c5, 0);
	cube5->SetPos(-100, 3, 80);

	Cube c6(2, 5, 200);
	cube6 = App->physics->AddBody(c6, 0);
	cube6->SetPos(-190, 3, -20);

	Cube c7(2, 5, 180);
	c7.SetRotation(90, { 0,1,0 });
	cube7 = App->physics->AddBody(c7, 0);
	cube7->SetPos(-100, 3, -120);

	Cube c8(2, 5, 20);
	cube8 = App->physics->AddBody(c8, 0);
	cube8->SetPos(10, 3, -130);

	Cube c9(2, 5, 200);
	c9.SetRotation(90, { 0,1,0 });
	cube9 = App->physics->AddBody(c9, 0);
	cube9->SetPos(-90, 3, -140);

	Cube c10(2, 5, 20);
	c10.SetRotation(90, { 0,1,0 });
	cube10 = App->physics->AddBody(c10, 0);
	cube10->SetPos(-200, 3, -140);

	Cube c11(2, 5, 20);
	c11.SetRotation(90, { 0,1,0 });
	cube11 = App->physics->AddBody(c11, 0);
	cube11->SetPos(-200, 3, 100);

	Cube c12(2, 5, 240);
	cube12 = App->physics->AddBody(c12, 0);
	cube12->SetPos(-210, 3, -20);
	
	

	/*PhysBody3D* cube1;
	Cube c1(1, 10, 200);
	cube1 = App->physics->AddBody(c1);
	cube1->body->setMassProps(0, { 0,0,0 });
	cube1->SetPos(5, 0, 0);
	


	PhysBody3D* cube2;
	Cube c2(1, 10, 80);
	cube2 = App->physics->AddBody(c2);
	cube2->body->setMassProps(0, { 0,0,0 });
	cube2->SetPos(-5, 0, 0);


	PhysBody3D* cube3;
	Cube c3(1, 10, 120);
	c3.SetRotation(90, vec3(0, -1, 0));
	cube3 = App->physics->AddBody(c3);
	cube3->body->setMassProps(0, { 0,0,0 });
	cube3->SetPos(-55, 0,100);

	PhysBody3D* cube4;
	Cube c4(1, 10, 100);
	c4.SetRotation(90, vec3(0, -1, 0));
	cube4 = App->physics->AddBody(c4);
	cube4->body->setMassProps(0, { 0,0,0 });
	cube4->SetPos(-65, 0, 70);
	/*
	PhysBody3D* cube5;
	Cube c5(1, 10, 5);
	c3.SetRotation(30, vec3(0, -1, 0));
	cube5 = App->physics->AddBody(c5);
	cube5->body->setMassProps(0, { 0,0,0 });
	cube5->SetPos(0, 10, 60);

	PhysBody3D* cube6;
	Cube c6(1, 10, 5);
	c3.SetRotation(30, vec3(0, -1, 0));
	cube6 = App->physics->AddBody(c6);
	cube6->body->setMassProps(0, { 0,0,0 });
	cube6->SetPos(0, 10, 60);

	PhysBody3D* cube7;
	Cube c7(1, 10, 5);
	c3.SetRotation(30, vec3(0, -1, 0));
	cube7 = App->physics->AddBody(c7);
	cube7->body->setMassProps(0, { 0,0,0 });
	cube7->SetPos(0, 10, 60);

	PhysBody3D* cube8;
	Cube c8(1, 10, 5);
	c3.SetRotation(30, vec3(0, -1, 0));
	cube8 = App->physics->AddBody(c8);
	cube8->body->setMassProps(0, { 0,0,0 });
	cube8->SetPos(0, 10, 60);*/
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
		LOG("Hit!");
	}
}

