#pragma once

#include <string>
#include <gpiod.h>

class Led {
public:
	enum Errors {
		ERROR_UNKNOWN = -4,
		ERROR_VALUE = -3,
		ERROR_CHIP = -2,
		ERROR_LINE = -1,
		OK = 0
	};

	class LedResult {
	public:
		Errors errorCode = Errors::ERROR_UNKNOWN;
		int value = -1;
	};

	std::string CHIP_NAME = "/dev/gpiochip0";
	std::string CONSUMER_NAME = "Blinker";
	unsigned int PIN_NUM = 17;

	Led();
	~Led();

	LedResult on(unsigned int seconds);
	LedResult off(unsigned int seconds);
private:
	struct gpiod_chip* chip = nullptr;
	struct gpiod_line* line = nullptr;
	LedResult setValue(unsigned int value, unsigned int seconds);
};
