/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Functions.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const double radToDeg = 180 / M_PI;
const double degToRad = M_PI / 180;

void printVars(vector<vector<double> > tri, int row) {
    //Print set width constants
    const int VAR_INDENT = 5,
            EQUAL_INDENT = 3,
            VAL_INDENT = 10;
    
    cout << "Triangle " << (row + 1) << ":\n\n";
    //First, print a, b, and c
    for (int abc = 97, abcIndex = 0; abc < 100; abc++, abcIndex++)
        cout << setw(VAR_INDENT) << left << char(abc) << setw(EQUAL_INDENT) <<
                left << "=" << setw(VAL_INDENT) << left << tri[row][abcIndex] << endl;
    
    //Next, print A, B, and C
    for (int ABC = 65, ABCindex = 3; ABC < 68; ABC++, ABCindex++)
        cout << setw(VAR_INDENT) << left << char(ABC) << setw(EQUAL_INDENT) <<
                left << "=" << setw(VAL_INDENT) << left << tri[row][ABCindex] << endl;
    
    //Last, print area
    cout << setw(VAR_INDENT) << left << "Area" << setw(EQUAL_INDENT) <<
            left << "=" << setw(VAL_INDENT) << left << tri[row][6] << endl;
}
/* Function: printVars
 *
 * Input:
 * - 2D vector (triangles)
 * - int (row index)
 * 
 * Process:
 * 1. Initialize set width ints
 * 2. Print a, b, and c
 * 3. Print A, B, and C
 * 4. Print Area
 * 
 * Output:
 * - end void
 */

void findSolution(vector< vector<double> > &tri, int triNum) {
    int sideCount = 0,
            angleCount = 0,
            s,
            angle,
            side;
    for (int i = 0; i < tri[0].size(); i++)
        cout << tri[triNum - 1][i] << endl;
    
    //Count all the sides
    for (int i = 0; i < 3; i++)
        if (tri[triNum - 1][i] != 0)
            sideCount++;
    //Count all the angles
    for (int i = 3; i < 6; i++)
        if (tri[triNum - 1][i] != 0)
            angleCount++;
    //Choose the path
    if (sideCount == 3) { //SSS
        //LC to find A
        cout << pow(tri[triNum - 1][0], 2) << endl;
        cout << "cos-1(" << pow(tri[triNum - 1][1], 2) << " + " << pow(tri[triNum - 1][2], 2) << " - " << pow(tri[triNum - 1][0], 2) << "0/\n" <<
                2 << " * " << tri[triNum - 1][1] << " * " << tri[triNum - 2][1] << endl;
        tri[triNum - 1][3] = radToDeg * acos((pow(tri[triNum - 1][1], 2) + pow(tri[triNum - 1][2], 2) - pow(tri[triNum - 1][0], 2)) / (2 * tri[triNum - 1][1] * tri[triNum - 1][2]));
        //LS to find B
        cout << tri[triNum - 1][1] << " * " << sin(tri[triNum - 1][1] * degToRad) << " / " << tri[triNum - 1][0] << endl;
        tri[triNum - 1][4] = radToDeg * asin((tri[triNum - 1][1] * sin(tri[triNum - 1][3]) * degToRad) / (tri[triNum - 1][0]));
        //180- to find C
        tri[triNum - 1][5] = 180 - tri[triNum - 1][3] - tri[triNum - 1][4];
        s = ((tri[triNum - 1][0] + tri[triNum - 1][1] + tri[triNum - 1][2]) / 2);
        tri[triNum - 1][6] = sqrt(s * (s - tri[triNum - 1][0]) * (s - tri[triNum - 1][1]) * (s - tri[triNum - 1][2]));
    }
    else if (sideCount == 1) { //SAA
        //Find the missing angle
        for (int i = 3; i < tri[0].size(); i++)
            if (tri[triNum - 1][i] == 0)
                angle = i;
        switch (angle) {
            case 3:
                tri[triNum - 1][3] = 180 - tri[triNum - 1][4] - tri[triNum - 1][5];
                break;
            case 4:
                tri[triNum - 1][4] = 180 - tri[triNum - 1][3] - tri[triNum - 1][5];
                break;
            case 5:
                tri[triNum - 1][5] = 180 - tri[triNum - 1][4] - tri[triNum - 1][3];
                break;
        }
        //Find the current side and then solve
        for (int i = 0; i < 3; i++)
            if (tri[triNum - 1][i] != 0)
                side = i;
        switch (side) {
            case 0:
                tri[triNum - 1][1] = (tri[triNum - 1][0] * sin(degToRad * tri[triNum - 1][4]) / sin(degToRad * tri[triNum - 1][3]));
                tri[triNum - 1][2] = (tri[triNum - 1][0] * sin(degToRad * tri[triNum - 1][5]) / sin(degToRad * tri[triNum - 1][3]));
                break;
            case 1:
                tri[triNum - 1][0] = (tri[triNum - 1][1] * sin(degToRad * tri[triNum - 1][3]) / sin(degToRad * tri[triNum - 1][4]));
                tri[triNum - 1][2] = (tri[triNum - 1][0] * sin(degToRad * tri[triNum - 1][5]) / sin(degToRad * tri[triNum - 1][3]));
                break;
            case 2:
                tri[triNum - 1][0] = (tri[triNum - 1][2] * sin(degToRad * tri[triNum - 1][3]) / sin(degToRad * tri[triNum - 1][5]));
                tri[triNum - 1][1] = (tri[triNum - 1][0] * sin(degToRad * tri[triNum - 1][4]) / sin(degToRad * tri[triNum - 1][3]));
                break;
        }
        //Find the area
        s = ((tri[triNum - 1][0] + tri[triNum - 1][1] + tri[triNum - 1][2]) / 2);
        tri[triNum - 1][6] = sqrt(s * (s - tri[triNum - 1][0]) * (s - tri[triNum - 1][1]) * (s - tri[triNum - 1][2]));
    }
    else { //SSA
        bool lawSin;
        int LSside,
                LSangle,
                LSsideNoAngle;
        //Find out whether to use LS
        for (int i = 0; i < 3; i++) {
            if (tri[triNum - 1][i] != 0 && tri[triNum - 1][i + 3] != 0) {
                lawSin = true;
                LSside = i;
                LSangle = i + 3;
                for (int j = 0; j < 3; j++)
                    if (tri[triNum - 1][j] != 0 && tri[triNum - 1][i + 3] == 0)
                        LSsideNoAngle = j;
            }
        }
        //If lawSin is true, Law of Sines will be used first
        if (lawSin) {
            //Determine which angle to find based on which side doesn't match an angle
            for (int i = 0; i < 3; i++) {
                if (tri[triNum - 1][i] == 0)
                    tri[triNum - 1][LSsideNoAngle + 3] = radToDeg * asin((tri[triNum - 1][LSsideNoAngle] * sin(tri[triNum - 1][LSangle] * degToRad)) / tri[triNum - 1][LSside]);
            }
            //SSAA--find the last angle
            for (int i = 3; i < tri[0].size(); i++)
                if (tri[triNum - 1][i] == 0)
                    tri[triNum - 1][i] = 180 - tri[triNum - 1][LSsideNoAngle + 3] - tri[triNum - 1][LSangle];
            //SSAAA--find the last side
            for (int i = 0; i < 3; i++)
                if (tri[triNum - 1][i] == 0)
                    tri[triNum - 1][i] = (tri[triNum - 1][LSside] * sin((tri[triNum - 1][i] + 3) * degToRad)) / sin(tri[triNum - 1][LSangle] * degToRad);
            //SSSAAA--find area
            s = ((tri[triNum - 1][0] + tri[triNum - 1][1] + tri[triNum - 1][2]) / 2);
            tri[triNum - 1][6] = sqrt(s * (s - tri[triNum - 1][0]) * (s - tri[triNum - 1][1]) * (s - tri[triNum - 1][2]));
        }
        else { //Law of Cosines is used first
            int LCside1,
                    LCside2,
                    LCangle,
                    LCnoSide,
                    LCnoAngle1,
                    LCnoAngle2;
            //Find the elements that match the variables
            
            //LCside1
            for (int i = 0; i < 3; i++)
                if (tri[triNum - 1][i] != 0)
                    LCside1 = i;
            //LCside2
            for (int i = 0; i < 3; i++)
                if (tri[triNum - 1][i] != 0 && i != LCside1)
                    LCside2 = i;
            //LCnoSide
            for (int i = 0; i < 3; i++)
                if (tri[triNum - 1][i] == 0)
                    LCnoSide = i;
            //LCangle1
            for (int i = 3; i < 6; i++)
                if (tri[triNum - 1][i] != 0)
                    LCangle = i;
            //LCnoAngle1
            for (int i = 3; i < 6; i++)
                if (tri[triNum - 1][i] == 0)
                    LCnoAngle1 = i;
            //LCnoAngle2
            for (int i = 3; i < 6; i++)
                if (tri[triNum - 1][i] == 0 && i != LCnoAngle1)
                    LCnoAngle2 = i;
            
            //Find LCnoSide
            tri[triNum - 1][LCnoSide] = sqrt(pow(tri[triNum - 1][LCside1], 2) + pow(tri[triNum - 1][LCside2], 2) - 2 * tri[triNum - 1][LCside1] * tri[triNum - 1][LCside2] * cos(degToRad * tri[triNum - 1][LCangle]));
            //Find LCnoAngle1
            switch (LCnoAngle1) {
                case 3:
                    tri[triNum - 1][LCnoAngle1] = radToDeg * acos((pow(tri[triNum - 1][1], 2) + pow(tri[triNum - 1][2], 2) - pow(tri[triNum - 1][0], 2)) / (2 * tri[triNum - 1][1] * tri[triNum - 1][2]));
                    break;
                case 4:
                    tri[triNum - 1][LCnoAngle1] = radToDeg * acos((pow(tri[triNum - 1][0], 2) + pow(tri[triNum - 1][2], 2) - pow(tri[triNum - 1][1], 2)) / (2 * tri[triNum - 1][0] * tri[triNum - 1][2]));
                    break;
                case 5:
                    tri[triNum - 1][LCnoAngle1] = radToDeg * acos((pow(tri[triNum - 1][1], 2) + pow(tri[triNum - 1][0], 2) - pow(tri[triNum - 1][2], 2)) / (2 * tri[triNum - 1][1] * tri[triNum - 1][0]));
                    break;
            }
            //Find LCnoAngle2
            tri[triNum - 1][LCnoAngle2] = 180 - tri[triNum - 1][LCnoAngle1] - tri[triNum - 1][LCangle];
            //Find Area
            s = ((tri[triNum - 1][0] + tri[triNum - 1][1] + tri[triNum - 1][2]) / 2);
            tri[triNum - 1][6] = sqrt(s * (s - tri[triNum - 1][0]) * (s - tri[triNum - 1][1]) * (s - tri[triNum - 1][2]));
        }
    }
}

