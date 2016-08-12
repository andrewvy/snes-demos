#!/bin/bash

mkdir -p build
ca65 main.s -o build/main.o && ld65 -C lorom128.cfg -o build/my_game.smc build/main.o
