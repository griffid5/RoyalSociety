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

using namespace ci;
using namespace ci::app;
using namespace std;

class RoyalSocietyApp : public AppBasic {
  public:

	void setup();
	void mouseDown(MouseEvent event);	
	void update();
	void draw();
	void MessageBox();

  private:
	
	Node* sentinel_;			// Empty node
	
	Vec2i mousePos_;
	bool leftClicked_;

	Window* window1;
	Window* window2;
	Window* window3;
};
	
void RoyalSocietyApp::setup()
{
	sentinel_ = new Node();		// start cicular link list
	leftClicked_ = false;

	window1 = new Window(Vec2i(50, 50), 200, 200, Color8u(0, 0, 255));
	window2 = new Window(Vec2i(100, 100), 250, 250, Color8u(0, 255, 0));
	window3 = new Window(Vec2i(150, 150), 300, 300, Color8u(255, 0, 0));
	


	// Adds the rectangles to the node linked list in the order as listed below.
	sentinel_->insertAfter(sentinel_, window1);
	sentinel_->insertAfter(sentinel_, window2);
	sentinel_->insertAfter(sentinel_, window3);
}


void RoyalSocietyApp::mouseDown( MouseEvent event )
{
	mousePos_ = event.getPos();
	leftClicked_ = true;
}

void RoyalSocietyApp::update()
{
	
}

void RoyalSocietyApp::draw()
{
	Node* cur = sentinel_->next_;
	while(cur != sentinel_)
	{
		cur->window_->draw();

		// go to next node in list
		cur = cur->next_;
	}
}

CINDER_APP_BASIC(RoyalSocietyApp, RendererGl)
