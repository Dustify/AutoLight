#ifndef MODEL_H
#define MODEL_H

#include "config.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RtcDS3231.h>
#include <TimeLord.h>

Adafruit_SSD1306 display(
	PIN_OLED_MOSI,
	PIN_OLED_CLK,
	PIN_OLED_DC,
	PIN_OLED_RESET,
	-1);

RtcDS3231<TwoWire> rtc(Wire);

TimeLord timeLord;

void modelInit() {
	pinMode(PIN_LEFT, INPUT_PULLUP);
	pinMode(PIN_SELECT, INPUT_PULLUP);
	pinMode(PIN_RIGHT, INPUT_PULLUP);

	display.begin(SSD1306_SWITCHCAPVCC);
	display.setTextColor(WHITE);

	rtc.Begin();

	display.setTextSize(2);

	timeLord.TimeZone(TIMEZONE * 60);
	timeLord.Position(LONGITUDE, LATITUDE);
}

uint8_t VIEW;

uint8_t STATE_LEFT;
uint8_t STATE_SELECT;
uint8_t STATE_RIGHT;

uint8_t STATE_LEFT_CHANGED;
uint8_t STATE_SELECT_CHANGED;
uint8_t STATE_RIGHT_CHANGED;

uint8_t HOUR;
uint8_t MINUTE;
uint8_t SECOND;
uint8_t DAY;
uint8_t MONTH;
uint16_t YEAR;

float TIME;

float SR_HOUR;
float SR_MINUTE;
float SUNRISE;

float SS_HOUR;
float SS_MINUTE;
float SUNSET;

void printWithLeading(uint16_t value) {
	if (value < 10) {
		display.print(0);
	}

	display.print(value);
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

void modelUpdate() {
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

	RtcDateTime now = rtc.GetDateTime();
	// RtcTemperature temperature = rtc.GetTemperature();

	HOUR = now.Hour();
	MINUTE = now.Minute();
	SECOND = now.Second();
	DAY = now.Day();
	MONTH = now.Month();
	YEAR = now.Year();

	TIME = HOUR + (MINUTE / 60);

	byte nowArray[] = { SECOND, MINUTE, HOUR, DAY, MONTH, YEAR };

	timeLord.SunRise(nowArray);
	SR_MINUTE = nowArray[1];
	SR_HOUR = nowArray[2];

	SUNRISE = SR_HOUR + (SR_MINUTE / 60);

	timeLord.SunSet(nowArray);
	SS_MINUTE = nowArray[1];
	SS_HOUR = nowArray[2];

	SUNSET = SS_HOUR + (SS_MINUTE / 60);
}

#endif
