#include <iostream>
#include <fstream>
#include <vector>
//#include <conio.h>
#include <windows.h>
#include <cstring>
#include "renderArt.hpp"
#include "readArt.hpp"
#include "terminalHelpers.hpp"
#include "textBox.hpp"
#include "inputListener.hpp"
#include "startScreen.hpp"
#include "optionsBox.hpp"
#include "oscarRoom.hpp"
#include "lachlanRoom.hpp"
#include "anthonyRoom.hpp"
#include "callumRoom.hpp"
#include "introRoom.hpp"
//#include <mmsystem.h>

// comment to make pipeline run
// Room set up
const int numWalls = 4;

//Intro room
/*
-------------------------------------------------------------------------------------
ALL OF THIS ART STILL NEEDS TO BE REPLACED
IN THE INTRO ROOM ONLY
-------------------------------------------------------------------------------------
*/
const std::string room0[numWalls] = {"art/intro/W1.txt", "art/intro/W2.txt", "art/intro/W4.txt", "art/intro/W3.txt"};  
const std::string room0ZOOMED[numWalls] = {"art/intro/zoomed/W1Zoom.txt", "", "art/intro/zoomed/keypadZoom.txt", ""};
bool room0VIEWED[numWalls] = {false, false, false, false};
bool room0ZOOMEDVIEWED[numWalls] = {false, false, false, false};

//Oscars room
const std::string room1[numWalls] = {"art/room1/W1.txt", "art/room1/W2.txt", "art/room1/W3.txt", "art/room1/W4.txt"};  
const std::string room1ZOOMED[numWalls] = {"art/room1/zoomed/W1Zoom.txt", "", "art/room1/zoomed/W3Zoom.txt", ""};
bool room1VIEWED[numWalls] = {false, false, false, false};
bool room1ZOOMEDVIEWED[numWalls] = {false, false, false, false};

// Lachlans Room
const std::string room2[numWalls] = {"art/room2/W1.txt", "art/room2/W2.txt", "art/room2/W3.txt", "art/room2/W4.txt"}; 
const std::string room2ZOOMED[numWalls] = {"art/room1/zoomed/W1Zoom.txt", "", "art/room1/zoomed/W3Zoom.txt", ""};
bool room2VIEWED[numWalls] = {false, false, false, false};
bool room2ZOOMEDVIEWED[numWalls] = {false, false, false, false};

// Anthonys Room
const std::string room3[numWalls] = {"art/room3/W1.txt", "art/room3/W2.txt", "art/room3/W3.txt", "art/room3/W4.txt"};
const std::string room3ZOOMED[numWalls] = {"art/room3/zoomed/W1Zoom.txt", "art/room3/zoomed/W2Zoom.txt", "", "art/room3/zoomed/W4Zoom.txt"};
bool room3VIEWED[numWalls] = {false, false, false, false};
bool room3ZOOMEDVIEWED[numWalls] = {false, false, false, false};

// Callum Room
const std::string room4[numWalls] = {"art/room4/W1.txt", "art/room4/W2.txt", "art/room4/W3.txt", "art/room4/W4.txt"}; 
bool room4VIEWED[numWalls] = {false, false, false, false};
bool room4ZOOMEDVIEWED[numWalls] = {false, false, false, false};


std::string listenerType = "RoomLeftRight";
int roomNumber = 1;
int currentWallIndex = 0;
char** art = nullptr;
int artWidth = 0, artHeight = 0;
int totalConsoleHeight = 0;
int totalConsoleWidth = 0;
int  fullScreenTextBoxHeight = 0;
char input = ' ';
bool running = true;
bool zoomed = false;

std::vector<std::string> currentWall;

int main(int argc, char* argv[]) {

// Terminal setups
    enableUTF8Console();
    setFullScreen();
    getFullScreenDimensions();
    hideCursor();
    clearWholeScreen();

    
    
    startScreen(); // Display Start Screen for input
    if (running == false) {
        clearWholeScreen();
        std::string output = "Thank you for playing Escape Owheo Beta :)";            
        renderBox(0, totalConsoleWidth, 0, totalConsoleHeight, output, false, false, false);
        return 0;
    }
    clearWholeScreen();
    runIntro();
    runAnthony();
    runOscar();
    //runLachlan(); 
    //runCallum();
    clearWholeScreen();
    std::string output = "Thank you for playing Escape Owheo Beta :)";            
    renderBox(0, totalConsoleWidth, 0, totalConsoleHeight, output, false, false, false);

    return 0;
}
