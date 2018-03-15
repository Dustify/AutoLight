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

	if (SUNRISE_NEXT == 1) {
		display.print("SR ");
		printWithLeading(SR_HOUR);
		display.print(":");
		printWithLeading(SR_MINUTE);
		display.println();
	} else {
		display.print("SS ");
		printWithLeading(SS_HOUR);
		display.print(":");
		printWithLeading(SS_MINUTE);
		display.println();
	}

	display.print(TEMPERATURE);
	display.print((char)248);
	display.print(TEMP_IN_CELCIUS ? "C" : "F");
	display.println();

  if (selectPressed()) {
    VIEW = 1;
  }
}
};

#endif
