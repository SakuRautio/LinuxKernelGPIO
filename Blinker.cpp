#include <iostream>

#define MAX_BLINKS (5)
#define SECONDS_TO_HOLD_STATE (2)

#include "Led.hpp"
int main(int argc, char* argv[]) {
	int successes = 0;

	for (int i = 0; i < MAX_BLINKS; i++) {
		std::cout << "-----------------------" << std::endl;
		std::cout << "Round " << (i + 1) << "/" << MAX_BLINKS << std::endl;

		Led* led = new Led();
		std::cout << "Turning LED on" << std::endl;
		Led::LedResult result = led->on(SECONDS_TO_HOLD_STATE);
		if (result.errorCode) {
			std::cerr << "Error: " << result.errorCode << std::endl;
			continue;
		}

		std::cout << "Turning LED off" << std::endl;
		result = led->off(SECONDS_TO_HOLD_STATE);
		if (result.errorCode) {
			std::cerr << "Error: " << result.errorCode << std::endl;
			continue;
		}

		delete led;
		successes++;
	}

	return (successes == MAX_BLINKS) ? 0 : successes;
}
