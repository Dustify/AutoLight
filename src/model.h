#ifndef MODEL_H
#define MODEL_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RtcDS3231.h>

#define PIN_OLED_MOSI  9
#define PIN_OLED_CLK   10
#define PIN_OLED_DC    11
#define PIN_OLED_RESET 13

#define PIN_LEFT    2
#define PIN_SELECT  3
#define PIN_RIGHT   4

Adafruit_SSD1306 display(
	PIN_OLED_MOSI,
	PIN_OLED_CLK,
	PIN_OLED_DC,
	PIN_OLED_RESET,
	-1);

RtcDS3231<TwoWire> rtc(Wire);

uint8_t VIEW;

uint8_t STATE_LEFT;
uint8_t STATE_SELECT;
uint8_t STATE_RIGHT;

uint8_t STATE_LEFT_CHANGED;
uint8_t STATE_SELECT_CHANGED;
uint8_t STATE_RIGHT_CHANGED;

void printWithLeading(uint16_t value) {
	if (value < 10) {
		display.print(0);
	}

	display.print(value);
}

void updateInputs() {
	uint8_t STATE_LEFT_NEW = digitalRead(PIN_LEFT);
	uint8_t STATE_SELECT_NEW = digitalRead(PIN_SELECT);
	uint8_t STATE_RIGHT_NEW = digitalRead(PIN_RIGHT);

  if (STATE_LEFT_NEW != STATE_LEFT) {
    STATE_LEFT_CHANGED = 1;
  }

  if (STATE_SELECT_NEW != STATE_SELECT) {
    STATE_SELECT_CHANGED = 1;
  }

  if (STATE_RIGHT_NEW != STATE_RIGHT) {
    STATE_RIGHT_CHANGED = 1;
  }

	STATE_LEFT = STATE_LEFT_NEW;
	STATE_SELECT = STATE_SELECT_NEW;
	STATE_RIGHT = STATE_RIGHT_NEW;
}

uint8_t leftPressed() {
  if (STATE_LEFT == LOW && STATE_LEFT_CHANGED) {
    STATE_LEFT_CHANGED = 0;
    return 1;
  }

  return 0;
}

uint8_t selectPressed() {
  if (STATE_SELECT == LOW && STATE_SELECT_CHANGED) {
    STATE_SELECT_CHANGED = 0;
    return 1;
  }

  return 0;
}

uint8_t rightPressed() {
  if (STATE_RIGHT == LOW && STATE_RIGHT_CHANGED) {
    STATE_RIGHT_CHANGED = 0;
    return 1;
  }

  return 0;
}

#endif
