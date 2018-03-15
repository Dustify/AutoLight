#ifndef VIEW_HOME_H
#define VIEW_HOME_H

#include "model.h"

class ViewHome {
public:
static void loop() {
	printWithLeading(HOUR);
	display.print(":");
	printWithLeading(MINUTE);
	display.print(":");
	printWithLeading(SECOND);
	display.println();

	printWithLeading(DAY);
	display.print("/");
	printWithLeading(MONTH);
	display.print("/");
	display.print(YEAR);
	display.println();

	// display.print(temperature.AsFloat() * 1.8 + 32);
	// display.print((char)248);
	// display.print("F");
	// display.println();

	display.print(SUNRISE);
	display.println();

	display.print(SUNSET);
	display.println();

  if (selectPressed()) {
    VIEW = 1;
  }
}
};

#endif
