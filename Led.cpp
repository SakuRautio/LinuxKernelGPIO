#include <iostream>
#include <bits/stdc++.h>
#include <gpiod.h>
#include <thread>
#include <chrono>

#include "Led.hpp"

Led::Led() {
        chip = gpiod_chip_open(Led::CHIP_NAME.c_str());
        if (chip == nullptr) {
                std::cerr << "Could not open chip: " << Led::CHIP_NAME << std::endl;
        }
        line = gpiod_chip_get_line(chip, Led::PIN_NUM);
        if (line == nullptr) {
                std::cerr << "Could not get line: " << Led::PIN_NUM << std::endl;
        }
}

Led::~Led() {
	gpiod_line_release(line);
	gpiod_chip_close(chip);
}

Led::LedResult Led::setValue(unsigned int value, unsigned int seconds) {
	LedResult result;
	int status = 0;
        status = gpiod_line_request_output(line, Led::CONSUMER_NAME.c_str(), 0);
        if (status != 0) {
                std::cerr << "Error: Could not request line output!: " << status << std::endl;
                result.errorCode = Led::Errors::ERROR_LINE;
                return result;
        }
        status = gpiod_line_set_value(line, value);
        if (status < 0) {
                std::cerr << "Error: Could not set value!: " << status << std::endl;
                result.errorCode = Led::Errors::ERROR_VALUE;
                return result;
        }
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
        gpiod_line_release(line);

        result.value = status;
        result.errorCode = Led::Errors::OK;
        return result;
}

Led::LedResult Led::on(unsigned int seconds) {
	return setValue(1, seconds);
}

Led::LedResult Led::off(unsigned int seconds) {
	return setValue(0, seconds);
}

