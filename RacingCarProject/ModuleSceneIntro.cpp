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

	Cube cube_sensorLevel3(20, 1, 1);
	sensorLevel3 = App->physics->AddBody(cube_sensorLevel3, 0.0f);
	sensorLevel3->collision_listeners.add(this);
	sensorLevel3->SetAsSensor(true);
	sensorLevel3->SetPos(50, 10, 35);

	//Sensor level 4
	Cube cube_sensorLevel4(40, 1, 1);
	sensorLevel4 = App->physics->AddBody(cube_sensorLevel4, 0.0f);
	sensorLevel4->collision_listeners.add(this);
	sensorLevel4->SetAsSensor(true);
	sensorLevel4->SetPos(80, 2, -85);

	/*Cube cube_sensorLevel2(30, 1, 1);
	sensorLevel2 = App->physics->AddBody(cube_sensorLevel2, 0.0f);
	sensorLevel2->collision_listeners.add(this);
	sensorLevel2->SetAsSensor(true);
	sensorLevel2->SetPos(25, 2, 20);*/

	//SpeedCube
	Cube speed_cube(2, 2, 2);
	speedCube = App->physics->AddBody(speed_cube, 0.0f);
	speedCube->collision_listeners.add(this);
	speedCube->SetAsSensor(true);
	speedCube->SetPos(0, 2, -50);

	Cube speed_cube2(2, 2, 2);
	speedCube2 = App->physics->AddBody(speed_cube2, 0.0f);
	speedCube2->collision_listeners.add(this);
	speedCube2->SetAsSensor(true);
	speedCube2->SetPos(55, 10, 30);

	Cube speed_cube3(2, 2, 2);
	speedCube3 = App->physics->AddBody(speed_cube3, 0.0f);
	speedCube3->collision_listeners.add(this);
	speedCube3->SetAsSensor(true);
	speedCube3->SetPos(95, 2, 100);

	Cube speed_cube4(2, 2, 2);
	speedCube4 = App->physics->AddBody(speed_cube4, 0.0f);
	speedCube4->collision_listeners.add(this);
	speedCube4->SetAsSensor(true);
	speedCube4->SetPos(70, 2, 300);

	Cube speed_cube5(2, 2, 2);
	speedCube5 = App->physics->AddBody(speed_cube5, 0.0f);
	speedCube5->collision_listeners.add(this);
	speedCube5->SetAsSensor(true);
	speedCube5->SetPos(90, 2, 500);


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
	Cube c6(2, 70, 270);
	cube6 = App->physics->AddBody(c6, 0);
	cube6->SetPos(40, 3, 20);

	Cube c7(2, 5, 270);
	cube7 = App->physics->AddBody(c7, 0);
	cube7->SetPos(15, 3, 20);

	Cube c8(2, 7, 2);
	cube8 = App->physics->AddBody(c8, 0);
	cube8->SetPos(25, 3, 100);
	cube8->collision_listeners.add(this);

	Cube c9(2, 5, 30);
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

	Cube c19(2, 10, 2);
	cube19 = App->physics->AddBody(c19, 0);
	cube19->SetPos(57, 10, 80);
	cube19->collision_listeners.add(this);

	Cube c20(2, 70, 1200);
	cube20 = App->physics->AddBody(c20, 0);
	cube20->SetPos(60, 4, 490);

	Cube c21(2, 70, 20);
	c21.SetRotation(90, { 0,1,0 });
	cube21 = App->physics->AddBody(c21, 0);
	cube21->SetPos(50, 15, 90);

	Cube c22(2, 70, 20);
	c22.SetRotation(90, { 0,1,0 });
	cube22 = App->physics->AddBody(c22, 0);
	cube22->SetPos(50, 30, -95);

	//Level 4
	Cube c23(2, 10, 1200);
	cube23 = App->physics->AddBody(c23, 0);
	cube23->SetPos(100, 4, 490);

	Cube c24(2, 70, 48);
	c24.SetRotation(90, { 0,1,0 });
	cube24 = App->physics->AddBody(c24, 0);
	cube24->SetPos(75, 30, -110);

	Cube c25(40, 80, 2);
	c25.SetRotation(80, { 1,0,0 });
	cube25 = App->physics->AddBody(c25, 0);
	cube25->SetPos(75, 0, 600);

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
	/*Plane p(0, 1, 0, 0);
	p.axis = true;
	p.color = White;
	p.Render();*/

	Cube cube_sensor(20, 1, 1);
	cube_sensor.SetPos(0, 2, 20);
	cube_sensor.color = Blue;
	cube_sensor.Render();

	Cube cube_sensorLevel2(30, 1, 1);
	cube_sensorLevel2.SetPos(25, 2, 20);
	cube_sensorLevel2.color = Blue;
	cube_sensorLevel2.Render();

	Cube cube_sensorLevel3(20, 1, 1);
	cube_sensorLevel3.SetPos(50, 10, 35);
	cube_sensorLevel3.color = Blue;
	cube_sensorLevel3.Render();


	Cube c1(2, 5, 270);
	c1.SetPos(10, 4, 20);
	c1.color = White;
	c1.Render();

	Cube c2(2, 5, 270);
	c2.SetPos(-10, 4, 20);
	c2.color = White;
	c2.Render();

	Cube c4(2, 5, 20);
	c4.SetRotation(90, { 0,1,0 });
	c4.SetPos(0, 4, 120);
	c4.color = White;
	c4.Render();

	Cube c5(2, 5, 20);
	c5.SetRotation(90, { 0,1,0 });
	c5.SetPos(0, 4, -115);
	c5.color = White;
	c5.Render();

	Cube c6(2, 70, 270);
	c6.SetPos(40, 4, 20);
	c6.color = White;
	c6.Render();

	Cube c7(2, 5, 270);
	c7.SetPos(15, 4, 20);
	c7.color = White;
	c7.Render();

	Cube c9(2, 10, 30);
	c9.SetRotation(90, { 0,1,0 });
	c9.SetPos(25, 4, 120);
	c9.color = White;
	c9.Render();

	Cube c10(2, 5, 30);
	c10.SetRotation(90, { 0,1,0 });
	c10.SetPos(25, 3, -115);
	c10.color = White;
	c10.Render();

	Cube c11(1, 5, 1);
	c11.SetRotation(90, { 0,1,0 });
	c11.SetPos(25, 3, 95);
	c11.color = White;
	c11.Render();

	Cube c12(2, 5, 8);
	c12.SetRotation(45, { 0,1,0 });
	c12.SetPos(20, 3, 100);
	c12.color = Black;
	c12.Render();


	Cube c3(2, 7, 2);
	c3.SetPos(0, 3, 100);
	c3.color = Red;
	c3.Render();
	

	Cube c8(2, 7, 2);
	c8.SetPos(25, 3, 100);
	c8.color = Red;
	c8.Render();
	

	Cube c19(2, 10, 2);
	c19.SetPos(57, 10, 80);
	c19.color = Red;
	c19.Render();
	
	Cube speed_cube(2, 0.2f, 4);
	speed_cube.SetPos(0, 0, -50);
	speed_cube.color = Green;
	speed_cube.Render();

	Cube c13(20, 30, 35);
	c13.SetPos(50, 15, -85);
	c13.color = White;
	c13.Render();

	Cube c14(20, 50, 2);
	c14.SetRotation(125, { 1,0,0 });
	c14.SetPos(50, 15, -47);
	c14.color = White;
	c14.Render();

	Cube c15(20, 80, 2);
	c15.SetRotation(90, { 1,0,0 });
	c15.SetPos(50, 2, 11);
	c15.color = White;
	c15.Render();

	Cube c16(20, 20, 2);
	c16.SetRotation(70, { 1,0,0 });
	c16.SetPos(50, 5, 30);
	c16.color = White;
	c16.Render();

	Cube c17(20, 20, 20);
	c17.SetPos(50, 0, 80);
	c17.color = White;
	c17.Render();

	Cube c18(2, 20, 270);
	c18.SetRotation(90, { 0,0,1 });
	c18.SetPos(0, 7, 20);
	c18.color = White;
	c18.Render();

	Cube c20(2, 30, 270);
	c20.SetRotation(90, { 0,0,1 });
	c20.SetPos(25, 7, 20);
	c20.color = White;
	c20.Render();

	Cube c21(0, 25, 270);
	c21.SetRotation(90, { 0,0,1 });
	c21.SetPos(0, 0, 20);
	c21.color = White;
	c21.Render();

	Cube c22(0, 30, 270);
	c22.SetRotation(90, { 0,0,1 });
	c22.SetPos(25, 0, 20);
	c22.color = White;
	c22.Render();

	Cube speed_cube2(2, 2, 2);
	speed_cube2.SetPos(55, 10, 30);
	speed_cube2.color = Green;
	speed_cube2.Render();

	Cube c23(2, 70, 1200);
	c23.SetPos(60, 4, 490);
	c23.color = White;
	c23.Render();

	Cube c24(2, 70, 20);
	c24.SetRotation(90, { 0,1,0 });
	c24.SetPos(50, 15, 90);
	c24.color = White;
	c24.Render();

	Cube c25(2, 30, 270);
	c25.SetRotation(90, { 0,0,1 });
	c25.SetPos(50, 40, 20);
	c25.color = White;
	c25.Render();

	Cube c26(2, 70, 20);
	c26.SetRotation(90, { 0,1,0 });
	c26.SetPos(50, 30, -95);
	c26.color = White;
	c26.Render();

	//Level 4
	/*Cube c27(2, 10, 300);
	c27.SetPos(100, 4, 40);
	c27.color = White;
	c27.Render();

	Cube c28(2, 70, 48);
	c28.SetRotation(90, { 0,1,0 });
	c28.SetPos(75, 30, -110);
	c28.color = White;
	c28.Render();*/

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
	if (body1 == speedCube && body2 == (PhysBody3D*)App->player->vehicle || body1 == speedCube2 && body2 == (PhysBody3D*)App->player->vehicle || body1 == speedCube3 && body2 == (PhysBody3D*)App->player->vehicle || body1 == speedCube4 && body2 == (PhysBody3D*)App->player->vehicle || body1 == speedCube5 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->speedCube = true;

	}
	if (body1 == sensor && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->stop = true;
	}
	if (body1 == cube3 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->stop = false;
		App->player->nextLevel = true;
		App->player->vehicle->SetPos(25, 0, -100);
		if (App->player->vehicle->body->getLinearVelocity() != 0)
		{
			App->player->vehicle->body->setAngularVelocity({ 0,0,0 });
		}
		if (App->player->vehicle->GetKmh() != 0)
			App->player->vehicle->body->setLinearVelocity({ 0,0,0 });
		
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
		if (App->player->vehicle->body->getLinearVelocity() != 0)
		{
			App->player->vehicle->body->setAngularVelocity({ 0,0,0 });
		}
		if (App->player->vehicle->GetKmh() != 0)
			App->player->vehicle->body->setLinearVelocity({ 0,0,0 });

	}
	if (body1 == sensorStop2 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->nextLevel = false;
		App->player->level2 = false;
		App->player->level3 = true;
	}
	if (body1 == sensorLevel4 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->nextLevel = false;
		App->player->level3 = false;
		App->player->level4 = true;
	}
	if (body1 == cube19 && body2 == (PhysBody3D*)App->player->vehicle)
	{
		App->player->stop = false;
		App->player->nextLevel = true;
		App->player->vehicle->SetPos(70, 0, -85);
		if (App->player->vehicle->body->getLinearVelocity() != 0)
		{
			App->player->vehicle->body->setAngularVelocity({ 0,0,0 });
		}
		if (App->player->vehicle->GetKmh() != 0)
			App->player->vehicle->body->setLinearVelocity({ 0,0,0 });

	}


}

