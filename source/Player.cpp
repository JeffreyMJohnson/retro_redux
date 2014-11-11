#include "Player.h"

Player::Player(char* filePath, float a_width, float a_height)
{
	width = a_width;
	height = a_height;

	//sprites for shoot animation
	spriteID_A = CreateSprite(filePath, a_width, a_height, true);
	spriteID_B = CreateSprite("./images/player/galaxian_b2.png", 46.0f, 69.0f, true);
	spriteID = spriteID_A;
}

/*
test hooks
*/
Player::Player(char* filePath, float a_width, float a_height, bool underTest)
{
	width = a_width;
	height = a_height;

	spriteID_A = 100;
	spriteID_B = 101;
	spriteID = spriteID_A;
}

//initialize player with position, velocity, radius (collider),health, speed and alive
void Player::Init(Vector2 a_pos, Vector2 a_velocity, float a_radius, int a_health)
{
	position = a_pos;
	velocity = a_velocity;
	collider.radius = a_radius;
	health = a_health;

	speed = 50.0f;
	alive = true;

}

//input handling
void Player::Input()
{
	//start with 0 velocity
	velocity = Vector2();

	if (IsKeyDown(GLFW_KEY_A))
	{
		if (position.x <= 0)
		{
			position.x = 0;
			velocity.x = 0;
		}
		else
		{
			velocity.x = -1;
		}

	}

	if (IsKeyDown(GLFW_KEY_D))
	{
		if (position.x >= screenWidth - (height * 0.5f))
		{
			position.x = screenWidth - (height * 0.5f);
			velocity.x = 0;
		}
		else
		{
			velocity.x = 1;
		}

	}

	if (!BulletManager::playerBullet->alive && IsKeyDown(GLFW_KEY_SPACE))
	{
		Shoot();
	}
}

void Player::Input(bool leftKeyDown, bool rightKeyDown, bool shootKeyDown, bool playerBulletAlive)
{
	//start with 0 velocity
	velocity = Vector2();

	if (leftKeyDown)
	{
		if (position.x <= 0)
		{
			position.x = 0;
			velocity.x = 0;
		}
		else
		{
			velocity.x = -1;
		}

	}

	if (rightKeyDown)
	{
		if (position.x >= screenWidth - (height * 0.5f))
		{
			position.x = screenWidth - (height * 0.5f);
			velocity.x = 0;
		}
		else
		{
			velocity.x = 1;
		}

	}

	if (!playerBulletAlive && shootKeyDown)
	{
		//Shoot();
	}
}

//handle shooting
void Player::Shoot()
{
	BulletManager::SetBullet(PLAYER, Vector2(position.x, position.y + 20.0f), Vector2(0, 1), 300.0f, 1);
}

void Player::Update(float a_delta)
{
	if (alive)
	{
		Input();

		position.x += velocity.x * speed * a_delta;
		position.y += velocity.y * speed * a_delta;

		MoveSprite(spriteID, position.x, position.y);

		collider.center = position;
	}
	else
	{
		//move to original position
		position = Vector2(screenWidth * 0.5f, 100.0f);
		MoveSprite(spriteID, position.x, position.y);
		collider.center = position;
	}

}

void Player::Draw()
{
	//MoveSprite(spriteID, position.x, position.y);
	if (alive)
	{
		//shoot animation
		if (BulletManager::playerBullet->alive)
		{
			spriteID = spriteID_B;
		}
		else
		{
			spriteID = spriteID_A;
		}
		DrawSprite(spriteID);
	}

}

std::ostream& operator<<(std::ostream& out, const Player& p)
{
	out << "Player [";
	out << "width: " << p.width;
	out << " height: " << p.height;
	out << " spriteID: " << p.spriteID;
	out << " spriteID_A: " << p.spriteID_A;
	out << " spriteID_B: " << p.spriteID_B;
	out << " position: " << p.position;
	out << " velocity: " << p.velocity;
	out << " speed: " << p.speed;
	out << " health: " << p.health;
	out << " alive: " << p.alive;
	out << "]";
	return out;
}

Player::~Player()
{
}