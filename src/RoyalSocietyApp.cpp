/**
 * @author David Griffith
 * @date 2012-09-17
 * @note This is homework for CSE 274. 
 *
 * @note This file is (c) 2012. It is licensed under the 
 * CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
 * which means you are free to use, share, and remix it as long as you
 * give attribution. Commercial uses are allowed.

 * @note Some of this code has been forked from Justin Ordway, https://github.com/ordwayjm/RoyalSociety
 */

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Node.h"
#include <Windows.h>
#include "cinder/Font.h"
#include "cinder/Text.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/gl/Texture.h"
#include <iostream>
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSocietyApp : public AppBasic {
  public:

	void setup();
	void mouseDown(MouseEvent event);
	void keyDown(KeyEvent event);
	void render();
	void update();
	void draw();


  private:
	
	Font default_font_;
	gl::Texture default_texture_font_;
	Vec2f default_size_;
	bool message_box;

	// Create the decoy node
	Node* sentinel_;			


	Vec2i mousePos_;
	bool leftClicked_;

	// Window method
	Window* window1;
	Window* window2;
	Window* window3;
};
	

void RoyalSocietyApp::setup()
{
	default_font_ = Font("Helvetica", 18);
	default_size_ = Vec2f(100, 100);
	render();

	sentinel_ = new Node();		// start cicular link list
	leftClicked_ = false;

	// Create three new rectangles
	window1 = new Window(Vec2i(50, 50), 200, 200, Color8u(0, 0, 255));
	window2 = new Window(Vec2i(100, 100), 250, 250, Color8u(0, 255, 0));
	window3 = new Window(Vec2i(150, 150), 300, 300, Color8u(255, 0, 0));

	// Adds the rectangles to the node linked list in the order as listed below.
	sentinel_->insertAfter(sentinel_, window1);
	sentinel_->insertAfter(sentinel_, window2);
	sentinel_->insertAfter(sentinel_, window3);
}
/*
This method does not work but it is designed to display a menu at the beginning 
of the program and explain the controls to the user.
*/
// @note The general idea of this method comes from marshast/TheRoyalSociety. 
void RoyalSocietyApp::render() {
	string message = "Welcome to my main menu ! \n 1) The ? displays or gets rid of the menu.";
	TextBox tbox = TextBox().alignment(TextBox::CENTER).font(default_font_).size(Vec2i(512, 511)).text(message);
	tbox.setColor(Color(1.0f, 1.0f, 1.0f));
	tbox.setBackgroundColor(ColorA(0.0, 0.0, 0.0));
	Vec2i sz = tbox.measure();
	console () << "Height: " << sz.y << endl;
	default_texture_font_ = gl::Texture(tbox.render());
	message_box = true;
}

void RoyalSocietyApp::mouseDown( MouseEvent event )
{
	mousePos_ = event.getPos();
	leftClicked_ = true;
}
/*
This method evaluates the users input and does a certain thing 
based on that input.
*/
void RoyalSocietyApp::keyDown( KeyEvent event) {
	if (event.getChar() == '?') {
		message_box = !(message_box);
	}

	message_box = true;
}

void RoyalSocietyApp::update()
{
}

void RoyalSocietyApp::draw()
{
	if (default_texture_font_ && message_box == true) {
		render();
		gl::draw(default_texture_font_);
	}
	Node* cur = sentinel_->next_;
	while(cur != sentinel_)
	{
		cur->window_->draw();

		// go to next node in list
		cur = cur->next_;
	}
	
}

CINDER_APP_BASIC(RoyalSocietyApp, RendererGl)
