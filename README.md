# LinuxKernelGPIO
[![Build Status](https://jenkins.rautio.me/job/LinuxKernelGPIO/job/Build%20and%20run/badge/icon)](https://jenkins.rautio.me/job/LinuxKernelGPIO/job/Build%20and%20run/)

LED-Blinker on a linux kernel level running on a RaspberryPi 4.

Requires [libgpiod][].

Build command: `g++ -Wall -Og Led.cpp Blinker.cpp /usr/lib/arm-linux-gnueabihf/libgpiod.a -o Blinker.exe`.

Running the program: `./Blinker.exe`.

---

Saku Rautio
2020

[libgpiod]: https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/about/
