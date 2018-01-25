#include "model.h"
#include "viewHome.h"
#include "viewMenu.h"

void setup() {
	pinMode(PIN_LEFT, INPUT_PULLUP);
	pinMode(PIN_SELECT, INPUT_PULLUP);
	pinMode(PIN_RIGHT, INPUT_PULLUP);

	display.begin(SSD1306_SWITCHCAPVCC);
	display.setTextColor(WHITE);

	rtc.Begin();

	display.setTextSize(2);
	display.setCursor(0, 0);
}

void loop() {
	updateInputs();

	display.clearDisplay();

	switch (VIEW) {
	case 0: ViewHome::loop(); break;
	case 1: ViewMenu::loop(); break;
	}

	display.display();
}
