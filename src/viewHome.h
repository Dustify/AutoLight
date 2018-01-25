#ifndef VIEW_HOME_H
#define VIEW_HOME_H

#include "model.h"

class ViewHome {
public:
static void loop() {
	RtcDateTime now = rtc.GetDateTime();
	RtcTemperature temperature = rtc.GetTemperature();

	printWithLeading(now.Hour());
	display.print(":");
	printWithLeading(now.Minute());
	display.print(":");
	printWithLeading(now.Second());
	display.println();

	printWithLeading(now.Day());
	display.print("/");
	printWithLeading(now.Month());
	display.print("/");
	display.print(now.Year());
	display.println();

	display.print(temperature.AsFloat() * 1.8 + 32);
	display.print((char)248);
	display.print("F");
	display.println();

	display.print(STATE_LEFT);
	display.print(" ");
	display.print(STATE_SELECT);
	display.print(" ");
	display.print(STATE_RIGHT);
	display.println();

  // if (selectPressed()) {
  //   VIEW = 1;
  // }
}
};

#endif
