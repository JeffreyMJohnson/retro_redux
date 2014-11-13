#include "Bullet.h"

Bullet::Bullet(const char* filePath, float a_width, float a_height)
{
	width = a_width;
	height = a_height;
	alive = false;
	spriteID = CreateSprite(filePath, a_width, a_height, true);
		
	//Init(Vector2(), Vector2(), 100, 15, 1);
	Init(Vector2(), Vector2(), MNF::BULLET_SPEED, 15, 1);
}

/*
constructor to use for unit tests
*/
Bullet::Bullet(const char* filePath, float a_width, float a_height, bool underTest)
{
	width = a_width;
	height = a_height;
	alive = false;
	spriteID = 100;
	Init(Vector2(0, 0), Vector2(0, 0), 100, 15, 1);	
}

void Bullet::Init(Vector2 a_pos, Vector2 a_velocity, float a_speed, float a_radius, int a_health)
{
	position = a_pos;
	velocity = a_velocity;
	speed = a_speed;
	collider.radius = a_radius;
	health = a_health;
}

//move this bullet to given position with velocity, speed and health
void Bullet::Spawn(Vector2 a_pos, Vector2 a_velocity, float a_speed, int a_health)
{
	position = a_pos;
	velocity = a_velocity;
	speed = a_speed;

	health = a_health;
	alive = true;
}

void Bullet::Update(float a_delta)
{

	//position.x += velocity.x * speed * a_delta;
	//position.y += velocity.y * speed * a_delta;
	position += velocity * speed * a_delta;
	collider.center = position;

	MoveSprite(spriteID, position.x, position.y);

	if (position.y > MNF::SCREEN_HEIGHT + (height * 0.5f))
	{
		alive = false;
	}
}

/*
test hook function
*/
void Bullet::Update(float a_delta, bool underTest)
{
	position.x += velocity.x * speed * a_delta;
	position.y += velocity.y * speed * a_delta;
	collider.center = position;

	if (position.y > MNF::SCREEN_HEIGHT + (height * 0.5f))
	{
		alive = false;
	}
}

void Bullet::Draw()
{
	if (alive)
	{
		DrawSprite(spriteID);
	}

}

std::ostream& operator<<(std::ostream& out, const Bullet& b)
{
	out << "Bullet [";
	out << "width: " << b.width;
	out << " height: " << b.height;
	out << " spriteID: " << b.spriteID;
	out << " position: " << b.position;
	out << " velocity: " << b.velocity;
	out << " speed: " << b.speed;
	out << " health: " << b.health;
	out << " alive: " << b.alive;
	out << "]";
	return out;
}

Bullet::~Bullet()
{
}