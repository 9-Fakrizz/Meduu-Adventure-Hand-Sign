#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(float p_x, float p_y,SDL_Texture* p_text)
:x(p_x),y(p_y),text(p_text)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 1600;
	currentFrame.h = 1024;
}

float Entity::getX() {
	return x;
}

float Entity::getY() {
	return y;
}

SDL_Texture* Entity::getText() {
	return text;
}

SDL_Rect Entity::getCurrentFrame() {
	return currentFrame;
}