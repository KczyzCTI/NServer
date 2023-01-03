#!/usr/bin/env bash
echo "Installing required packages..."
sudo apt update --yes &&
sudo apt install pkg-config cmake libboost-all-dev dot doxygen pthreads --yes &&
sudo apt install --no-install-recommends libasio-dev --yes

