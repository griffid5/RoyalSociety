#include "Window.h"
/*
@param pos start position of the rectangle
@param width width of the recantangle
@param height height of the rectangle
@param color color of the the rectangle
*/
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