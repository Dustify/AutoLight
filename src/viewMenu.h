#ifndef VIEW_MENU_H
#define VIEW_MENU_H

#include "model.h"

class ViewMenu {
public:
static void loop() {
	display.print("MENU");
	display.println();

	if (selectPressed()) {
    VIEW = 0;
  }
}
};

#endif
