# LinuxKernelGPIO

[![Build Status](http://ec2-13-49-39-27.eu-north-1.compute.amazonaws.com/buildStatus/icon?job=LinuxKernelGPIO%2FBuild+and+run)](http://ec2-13-49-39-27.eu-north-1.compute.amazonaws.com/job/LinuxKernelGPIO/job/Build%20and%20run/)

LED-Blinker on a linux kernel level running on a RaspberryPi 4.

Requires [libgpiod][].

Build command: `g++ -Wall -Og Led.cpp Blinker.cpp /usr/lib/arm-linux-gnueabihf/libgpiod.a -o Blinker.exe`.

Running the program: `./Blinker`.

---

Saku Rautio
2020

[libgpiod]: https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/about/
