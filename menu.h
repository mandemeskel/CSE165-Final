#pragma once
#include "MyCode.h"
#include "App.h"


enum MenuClick {

	NO_BTN = 0,
	START_GAME = 1,
	SHOW_SCOREBOARD = 2

};


class Menu {

private:
	const int NUM_BUTTONS = 2;
	Button * start_btn;
	Button * scoreboard_btn;
	// Button * quit;
	// list of buttons in menu
	Button * buttons;
	// the actual menu, the border and background
	Rect * menu;
	void (App::*starBtnClick)();
	bool hidden;

public:
	Menu() {

		hidden = false;
		start_btn = new Button(-0.25, 0.3, 0.50, 0.3, "start");
		// this->start_btn = new Button( -0.6, 0.3, 0.50, 0.3, "start" );
		// this->scoreboard_btn = new Button( 0.1, 0.3, 0.50, 0.3, "score" );
		menu = new Rect(-0.75, 0.48, 1.50, 0.7);

	}

	~Menu() {

	}

	// draws each button by calling the button's draw method
	void draw() const {
		if (this != NULL)
		if (!hidden) {

			start_btn->draw();
			// this->scoreboard_btn->draw();
			menu->draw();

		}

	}

	// checks if the menu is clicked, if true passes the
	// mouse cords to buttons to see if they were clicked
	MenuClick contains(float x, float y) {
		if (this != NULL) {
			// can't click on something invisible
			if (hidden) return NO_BTN;

			// check position of clickwas inside of menu
			if (!menu->contains(x, y)) return NO_BTN;

			// start game
			if (start_btn->contains(x, y))

				return START_GAME;

			// open online scorebaord, how???
			// } else if( this->scoreboard_btn ) {

			//     return SHOW_SCOREBOARD;

			// }

			return NO_BTN;
		}
	}

	// the onclick callback for the start game button
	// void startBtnOnClick( void (App::*callback)() ) {

	//     this->starBtnClick = callback;

	// }

	void toggle(bool hide = true) {
		if (this != NULL) {

			if (hide)

				this->hidden = true;

			else

				this->hidden != this->hidden;
		}
	}

};