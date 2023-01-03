#!/usr/bin/env bash
echo "Installing required packages..."
sudo apt update --yes &&
sudo apt install git gdb gcc g++ cmake --yes
sudo apt install pkg-config libboost-all-dev doxygen graphviz --yes &&
sudo apt install --no-install-recommends libasio-dev --yes