Tank Separating Axis Demo
=========================

A small demo of the Separating Axis Theorem in Tank
* wasd to move a polygon
* right click and drag to move viewport

To install and run:

    git clone git@github.com:Gazok/TankDemos.git
    cd TankDemos
    git checkout SAT
    git submodule init
    git submodule update
    mkdir build
    cd build
    cmake ..
    make
    ./test
