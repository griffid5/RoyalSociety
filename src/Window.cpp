#include "Window.h"

Window::Window(Vec2i pos, int width, int height, Color8u color) 
{
	pos_ = pos;
	width_ = width;
	height_ = height;
	color_ = color;
	
}

Window::Window(void)
{

}

void Window::draw()
{
	gl::drawSolidRect(Rectf(pos_.x,pos_.y,pos_.x+width_,pos_.y+height_));
	gl::color(color_);
}