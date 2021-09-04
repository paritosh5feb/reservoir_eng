# reservoir_eng
A  simple QT C++ based Desktop Application for Reservoir Engineering for Exploration and Production in the Oil and Gas Industry. This Application can be used for 2 phase relative permeability calculations and effective phase saturation calculations.

### Project Structure
1. The main.cpp is the main app containing the QT C++ template code.
2. The main.cpp executes the mainwindow, which inturn loads its corresponding UI File, its components and their corresponding action functions defined in mainwindow.h
3. Subsequently, one of the two dialog boxes is loaded depending upon the action taken by the user in MainWindow.

![Imgur](https://i.imgur.com/JX8dmFO.png)

### Building
The project has been written on Linux (Debian) 64 bit, and is cross compiled for Windows 64 bit.
To build this project:
1. Open the terminal
2. ```cd ~/```
3. ```git clone https://github.com/paritosh5feb/reservoir_eng.git```
4. For the "build.sh" to run successfully, you will need to clone and build [https://github.com/mxe/mxe](MXE Cross compiler) tool-chain.
5. Run ```./build.sh```
6. On Windows, the project can be simply opened in QT Creator by double clicking on the "reservoir.pro" file.
