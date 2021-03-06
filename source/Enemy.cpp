#include "Enemy.h"


int Enemy::activeEnemyCount = 0;

//Instantiate enemy with sprite
Enemy::Enemy(const char* filePath, float a_width, float a_height)
{
	width = a_width;
	height = a_height;
	spriteID = CreateSprite(filePath, a_width, a_height, true);


	activeEnemyCount++;
	isAttacking = false;
	//in radians so convert!
	attackAngle =JMath::DegreeToRadians(90.0f);
	attackRadius = 30.0f;
	attackState = MOVE;
	attackExitPoint = Vector2();
	attackExitChosen = false;
	attackSlope = 0.0f;
	attackYIntercept = 0.0f;
	attackVelocity = Vector2();


	attackSpeed = 40.0f;
	shootMaxTime = .75f;
	shootTimer = shootMaxTime;

	player = nullptr;
}

/*
returns true if this position is equal to the other position else returns false
*/
bool Enemy::operator==(Enemy& other)
{
	return position == other.position;
}

/*
returns true if this position is not equal to the other position else returns false
*/
bool Enemy::operator!=(Enemy& other)
{
	return !(*this == other);
}

//Initialize enemy with position, velocity, collider radius, health, speed, colIndex, rowIndex and alive
void Enemy::Init(Vector2 a_pos, Vector2 a_velocity, float a_radius, int a_health, float a_speed, int a_colIndex, int a_rowIndex)
{
	position = a_pos;
	velocity = a_velocity;
	collider.radius = a_radius;
	health = a_health;
	speed = a_speed;
	alive = true;
	colPositionIndex = a_colIndex;
	rowPositionIndex = a_rowIndex;
}

//standard update done with enemy group control in GameState.cpp
void Enemy::Update(float a_delta)
{

}

//overridden to give GameState handle for accessing position grid
void Enemy::Update(float delta, GameState* gameState)
{

	//std::cout << GetEnemyGroupPosition(0, 0).x << std::endl;
	if (isAttacking && alive)
	{
		//go through attack phases
		Attack(delta, gameState);

	}
	//set collider center after each update to sync to position.;
	collider.center = position;
}

/*
in order to go negative direction when the circle reaches 0 degrees it will reset to 360 and fail existing test.
solution is an equality test for 270 degrees, but with float math will need to use epsilon - (fabs(result - expectedResult) > epsilon)
*/
void Enemy::Attack(float timeDelta, GameState* gameState)
{
	float epsilon = .01;

	switch (attackState)
	{
	case WAIT:
		//waiting to be sent on attack
		break;
	case MOVE:
		//if (position.y < returnPosition.y + attackRadius)
		if (position.y < gameState->GetEnemyGroupPosition(colPositionIndex, rowPositionIndex).y + attackRadius)
		{
			position.y += attackSpeed * attackVelocity.y * timeDelta;
		}
		else
		{
			attackState = CIRCLE;
		}
		break;
	case CIRCLE:
		/*points gotten by using parametric circle equation - given the center point of a circle a,b and the diameter d
		the points on the circumference given an angle from a previous point on circle theta:
		x = a + d * cos(theta)
		y = a + d * sin(theta)
		*/
		//attackAngle is in radians convert to be in degrees
		if (fabs((attackAngle - JMath::DegreeToRadians(270.0f))) > epsilon)
		{
			Vector2 returnPosition = gameState->GetEnemyGroupPosition(colPositionIndex, rowPositionIndex);
			float x = (returnPosition.x + (attackRadius * cos(attackAngle)));
			float y = (returnPosition.y + (attackRadius * sin(attackAngle)));

			
			attackAngle = attackAngle + JMath::DegreeToRadians(.05f) * attackVelocity.x * attackSpeed;
			if (JMath::RadiansToDegrees(attackAngle) <= 0)
			{
				attackAngle = JMath::DegreeToRadians(360.0f);
			}

			position = Vector2(x, y);
		}
		else
		{
			attackAngle = 90.0f;
			attackState = ATTACK;
			//change velocity to downward y for return phase
			attackVelocity = Vector2(attackVelocity.x, -1);
		}
		break;
	case ATTACK:
		//need player to calculate exit point
		assert(player != nullptr && player != 0);


		if (!attackExitChosen)
		{
			if (position.x < player->position.x)
			{
				//pick to right of player
				attackVelocity = Vector2(1, 1);
			}
			else//enemy to right or equal of player so go left
			{
				attackVelocity = Vector2(-1, 1);
			}
			attackExitPoint = Vector2(player->position.x + 100.0f * attackVelocity.x, 0);
			attackExitChosen = true;

			//slope formula -> m = (y1 -y2) / (x1 - x2)
			float m = GetSlopeOfLine(position, attackExitPoint);
			attackSlope = m;

			//point-slope formula -> y - y1 = m * (x - x1) choose any point on line as (x1, y1)
			//b = y - m * x
			//y = m * x + b
			float b = position.y - (m * position.x);
			attackYIntercept = b;
		}

		if (shootTimer <= 0)
		{
			BulletManager::SetBullet(ENEMY, position, Vector2(0, -1), 300.0f, 1);
			shootTimer = shootMaxTime;

		}
		else
		{
			shootTimer -= timeDelta;
		}


		//increment x
		if (position.y > attackExitPoint.y)
		{
			float x = position.x + attackSpeed * attackVelocity.x * timeDelta;
			float y = (attackSlope * x) + attackYIntercept;
			position = Vector2(x, y);
		}
		else
		{
			attackExitChosen = false;

			//set enemy x to original position and y to screen height
			position = Vector2(gameState->GetEnemyGroupPosition(colPositionIndex, rowPositionIndex).x, MNF::SCREEN_HEIGHT);
			attackState = RETURN;

		}

		break;
	case RETURN:
		attackVelocity = Vector2(attackVelocity.x, -1);
		if (position.y > gameState->GetEnemyGroupPosition(colPositionIndex, rowPositionIndex).y)
		{
			position = Vector2(gameState->GetEnemyGroupPosition(colPositionIndex, rowPositionIndex).x, 
						position.y + (attackSpeed * attackVelocity.y * timeDelta));
		}
		else
		{
			position = gameState->GetEnemyGroupPosition(colPositionIndex, rowPositionIndex);
			isAttacking = false;
			attackState = MOVE;
			attackAngle = 0.0f;
			attackExitChosen = false;
			attackExitPoint = Vector2();
			attackSlope = 0.0f;
			attackYIntercept = 0.0f;
			attackVelocity = Vector2();
		}



		break;
	}
}

float Enemy::GetSlopeOfLine(Vector2 point1, Vector2 point2)
{
	return (point1.y - point2.y) / (point1.x - point2.x);

}

void Enemy::setMovementExtremes(unsigned int a_leftExtreme, unsigned int a_rightExtreme)
{
	leftMovementExtreme = a_leftExtreme;
	rightMovementExtreme = a_rightExtreme;
}

//draw the enemy
void Enemy::Draw()
{
	if (alive)
	{
		MoveSprite(spriteID, position.x, position.y);
		DrawSprite(spriteID);
	}

}

/*
check all collisions and apply effects:
IsCollidedLeftWall - flip speedX and add a speed to speedY else speedY = 0
IsCollideRighttWall - flip speedX and add a speed to speedY else speedY = 0
params:
a_speedY: Speed to set speedY variable to make enemy move along Y axis. Should
be negative so enemy moves 'down'.
*/
void Enemy::CheckCollisions()
{
	if (IsCollidedLeftWall() || IsCollidedRightWall())
	{
		velocity.x *= -1;
		position.y -= height / 2;
		MoveSprite(spriteID, position.x, position.y);
	}
}

// SETTERS / GETTERS

void Enemy::SetLeftMoveExtreme(unsigned int a_leftExtreme)
{
	leftMovementExtreme = a_leftExtreme;
}

unsigned int Enemy::GetLeftMoveExtreme()
{
	return leftMovementExtreme;
}

void Enemy::SetRightMoveExtreme(unsigned int a_righttExtreme)
{
	rightMovementExtreme = a_righttExtreme;
}

unsigned int Enemy::GetRightMoveExtreme()
{
	return rightMovementExtreme;
}

void Enemy::SetScoreValue(int a_scoreValue)
{
	scoreValue = a_scoreValue;
}

int Enemy::GetScoreValue()
{
	return scoreValue;
}

void Enemy::SetAttackAngle(float a_angle)
{
	attackAngle = a_angle;
}

float Enemy::GetAttackAngle()
{
	return attackAngle;
}

void Enemy::SetAttackRadius(float a_radius)
{
	attackRadius = a_radius;
}

float Enemy::GetAttackRadius()
{
	return attackRadius;
}

void Enemy::SetAttackState(attackStates a_state)
{
	attackState = a_state;
}

attackStates Enemy::GetAttackState()
{
	return attackState;
}

void Enemy::SetAttackExitPoint(Vector2 a_point)
{
	attackExitPoint = a_point;
}

Vector2 Enemy::GetAttackExitPoint()
{
	return attackExitPoint;
}


Enemy::~Enemy()
{
}


//PRIVATE FUNCTIONS

/*
check if collided with right extreme (wall) and return true, otherwise return false
*/
bool Enemy::IsCollidedRightWall()
{
	if (position.x >= rightMovementExtreme)
	{
		position.x = rightMovementExtreme;
		return true;
	}
	return false;
}

/*
check if collided with left extreme (wall) and return true, otherwise return false
*/
bool Enemy::IsCollidedLeftWall()
{
	if (position.x <= leftMovementExtreme)
	{
		position.x = leftMovementExtreme;
		return true;
	}
	return false;
}