#!/bin/bash

sudo g++ -c CSALG.cpp;
sudo ar -rcs libCSALG.a CSALG.o;
sudo cp -i CSALG.hpp /usr/local/include;
sudo mv libCSALG.a /usr/local/lib;
sudo rm CSALG.o
