#ifndef VIEW_MENU_H
#define VIEW_MENU_H

#include "model.h"

class ViewMenu {
public:
static int8_t selectedIndex;

static void markSelected(uint8_t index) {
	if (selectedIndex == index) {
		display.print(">");
		return;
	}

	display.print(" ");
}

static void fixSelected() {
	if (selectedIndex > 2) {
		selectedIndex = 0;
		return;
	}

	if (selectedIndex < 0) {
		selectedIndex = 2;
		return;
	}
}

static void loop() {
	display.print("Menu");
	display.println();

	markSelected(0);
	display.print("Set time");
	display.println();

	markSelected(1);
	display.print("Set date");
	display.println();

	markSelected(2);
	display.print("Exit");
	display.println();

	if (leftPressed()) {
		selectedIndex--;
	}

	if (selectPressed()) {
    VIEW = 0;
  }

	if (rightPressed()) {
		selectedIndex++;
	}

	fixSelected();
}
};

int8_t ViewMenu::selectedIndex;

#endif
