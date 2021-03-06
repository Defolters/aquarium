#include "Field.h"

Field::Field(float scale_, RenderWindow& window_, Vector2f cameraPosition_, bool clearOutOfBounds_, Texture* background_, Vector2f backSize_)
{
	window = &window_;
	scale = scale_;
	clearOutOfBounds = clearOutOfBounds_;
	background = background_;
	backSize = backSize_;
	SetCameraPosition(cameraPosition_);
	CalculateDisplayedRect();
}

void Field::CalculateDisplayedRect()
{
	displayedRect = FloatRect(cameraPosition + ScreenToWorldPoint(Vector2f(SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2)) - Vector2f(SCREEN_HEIGHT *scale, SCREEN_WIDTH *scale), Vector2f(SCREEN_HEIGHT*scale, SCREEN_WIDTH*scale));
}

float Field::GetScale() const
{
	return scale;
}

Vector2f Field::GetCameraPosition()
{
	return cameraPosition;
}

void Field::SetCameraPosition(Vector2f cameraPosition_)
{
	cameraPosition = cameraPosition_;
	cameraPosition -= ScreenToWorldPoint(Vector2f(SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2));
}

Vector2f Field::WorldToScreenPoint(Vector2f point)
{
	return (point-cameraPosition) / scale;
}

Vector2f Field::ScreenToWorldPoint(Vector2f point)
{
	return point*scale-cameraPosition;
}

const RenderWindow * Field::GetWindow()
{
	return window;
}

Field::~Field()
{
}

Field MAIN_FIELD = Field(0.025, MAIN_WINDOW);