#include "Turret.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include <Math.h>


Turret::Turret(int x, int y) : Enemy(x, y)
{
	spritesheet = 2;
}

void Turret::MoveShoot()
{}