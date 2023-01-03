#!/usr/bin/env bash
echo "Installing required packages..."
sudo apt update --yes &&
sudo apt install gdb gcc
sudo apt install g++ --yes
sudo apt install pkg-config libboost-all-dev doxygen graphviz --yes &&
sudo apt install --no-install-recommends libasio-dev --yes