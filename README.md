# LinuxKernelGPIO

LED-Blinker on a linux kernel level running on a RaspberryPi 4.

Requires [libgpiod][].

Build command: `g++ -Wall -Og Led.cpp Blinker.cpp /usr/lib/arm-linux-gnueabihf/libgpiod.a -o Blinker`.

Running the program: `./Blinker`.

---

Saku Rautio
2020

[libgpiod]: https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/about/
