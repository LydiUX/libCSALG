#!/bin/bash

GREEN='\033[0;32m';
CLEAR='\033[0m';
sudo g++ -v -c CSALG.cpp;
sudo ar -v -rcs libCSALG.a CSALG.o;
sudo cp -v CSALG.hpp /usr/local/include;
sudo mv -v libCSALG.a /usr/local/lib;
sudo rm -v CSALG.o;
echo -e "${GREEN}Compilation Succeeded${CLEAR}"

