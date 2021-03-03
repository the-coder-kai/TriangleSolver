/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TriangleSolver.cpp
 * Author: riankaicorcino
 *
 * Created on February 2, 2021, 12:10 PM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <float.h>
#include "Functions.h"

/*
 * Notes
 * 
 * General:
 * - Entire program is repeating--encased in while loop--unless userInput is 0
 * 
 * Menus:
 * - Main menu
 *   0) Quit
 *   1) View triangle
 *   2) Clear triangle slot
 *   3) Add triangle slot
 * - Triangle edit options (coming soon...)
 * 
 * Triangle measurements:
 * - set to 0 by default
 * - use for loops to determine which measurements are empty
 * 
 */

using namespace std;

void printTriList(vector< vector<double> > tri) {
    int dataTotal;
    //Print list of all triangles
    for (int i = 0; i < tri.size(); i++) {
        dataTotal = 0;
        //First, the triangle number
        cout << (i + 1) << ") Triangle " << (i + 1) << " - ";
        for (int j = 0; j < tri[0].size(); j++)
            //Next, the number of measurements
            if (tri[i][j] != 0)
                dataTotal++;
        //Finish it off...
        cout << dataTotal << " measurements\n";
    }
}
/* Function: printTriList
 *
 * Input:
 * - 2D vector (triangles)
 * 
 * Process:
 * 1. Initialize total data counts var
 * 2. Count/print every triangle while counting/printing the total data for each triangle
 * 
 * Output:
 * - end void
 */

void verifyResponse(double uInput, double min, double max) {
    while (uInput < min || uInput > max) {
        cout << "Invalid response. Please try again\n";
        cin >> uInput;
    }
}
/* Function: verifyResponse
 * 
 * Input:
 * - int (userInput)
 * - int (min number choice)
 * - int (max number choice)
 * 
 * Process:
 * 1. Check whether the response was within the constraints (min and max)
 * 2. If the response wasn't, print the error, and repeat 1 and 2
 * 
 * Output:
 * - end void
 */

int dataCompatability(vector< vector<double> > tri, int triNum) {
    int dataCount = 0,
            angleCount = 0;
    /* return int defs:
     * 1 - Solved
     * 2 - Can't be solved
     * 3 - Ready to solve
     * 4 - Too many angles (AAA)
     */
    
    printVars(tri, triNum - 1);
    cout << endl;
    //Count the total data
    for (int i = 0; i < tri[0].size(); i++)
        if (tri[triNum - 1][i] != 0)
            dataCount++;
    //Count the total angles
    for (int i = 3; i < tri[0].size() - 1; i++)
        if (tri[triNum - 1][i] != 0)
            angleCount++;
    //Determine compatability
    if (dataCount < 3) { //Not enough data -- dataCount < 3
        cout << "Triangle " << triNum << " does not have enough measurements to be solved.\n" <<
                (3 - dataCount) << " more measurement(s) are needed to solve the triangle.\n" <<
                "You can change Triangle " << triNum << "'s measurements in the Edit Measurements section of this triangle\n\n";
        return 2;
    }
    else if (dataCount == 3 && angleCount < 3) { //Ready to solve -- dataCount == 3
        cout << "Triangle " << triNum << " has enough measurements and is ready to be solved!\n\n";
        //if (user == 0)
        //else
        return 3;
    }
    else if (dataCount == 3 && angleCount == 3) {
        cout << "Triangle " << triNum << " has too many angles for its starter measurements " <<
                "and needs at least one side. You can replace one or more angles in the Edit Measurements section.\n\n";
        return 4;
    }
    else if (dataCount == 7) {
        cout << "Triangle " << triNum << " has already been solved. The final measurements are:\n\n";
        printVars(tri, triNum - 1);
        return 1;
    }
}
/* Function: dataCompatability:
 * 
 * Input:
 * - 2D vector (triangles)
 * - int (row index)
 * 
 * Process:
 * 1. Initialize data counter
 * 2. Count the total data in the row
 * 3. Count the total angles in the row
 * 4. If count < 3, notify user of insufficient data and return 2
 * 5. If count == 3 AND angleCount < 3, notify user of sufficient data and return 3
 * 6. If count == 3 AND angleCount == 3, notify user of too many angles and return 4
 * 6. If count == 7, notfiy user that triangle is solved and return 1
 * 
 * Output:
 * - int (determines sufficiency of data)
 */



string verifyEditString(string var) {
    bool invalid = true;
    string user = var;
    while (invalid) {
        if (user == "a")
            invalid = false;
        else if (user == "b")
            invalid = false;
        else if (user == "c")
            invalid = false;
        else if (user == "A")
            invalid = false;
        else if (user == "B")
            invalid = false;
        else if (user == "C")
            invalid = false;
        else if (user == "0")
            invalid = false;
        
        if (invalid) {
            cout << "Invalid response. Please try again.\n";
            cin >> user;
        }
    }
    return user;
}

int editMeasurements(vector< vector<double> > &tri, int triNum) {
    string userLetter;
    double user;

    while (userLetter != "0") {
        //Menu and User input
        cout << "Which measurement would you like to edit? (Enter case-sensitive variable name\n" <<
                "as shown above)\n\n" <<
                "0 - Return to Triangle " << triNum << " Menu\n";
        cin >> userLetter;
        userLetter = verifyEditString(userLetter);
        
        //Edit value
        if (userLetter == "a") {
            cout << "Enter a value for variable 'a':";
            cin >> user;
            verifyResponse(user, 0, DBL_MAX);
            
            tri[triNum - 1][0] = user;
            cout << "tri" << (triNum - 1) << " " << 0 << " = " << user << endl;
            printVars(tri, triNum - 1);
        }
        else if (userLetter == "b") {
            cout << "Enter a value for variable 'b':";
            cin >> user;
            verifyResponse(user, 0, DBL_MAX);
            
            tri[triNum - 1][1] = user;
            cout << "tri" << (triNum - 1) << " " << 1 << " = " << user << endl;
            printVars(tri, triNum - 1);
        }
        else if (userLetter == "c") {
            cout << "Enter a value for variable 'c':";
            cin >> user;
            verifyResponse(user, 0, DBL_MAX);
            
            tri[triNum - 1][2] = user;
            cout << "tri" << (triNum - 1) << " " << 2 << " = " << user << endl;
            printVars(tri, triNum - 1);
        }
        else if (userLetter == "A") {
            cout << "Enter a value for variable 'A':";
            cin >> user;
            verifyResponse(user, 0, DBL_MAX);
            
            tri[triNum - 1][3] = user;
            cout << "tri" << (triNum - 1) << " " << 3 << " = " << user << endl;
            printVars(tri, triNum - 1);
        }
        else if (userLetter == "B") {
            cout << "Enter a value for variable 'c':";
            cin >> user;
            verifyResponse(user, 0, DBL_MAX);
            
            tri[triNum - 1][4] = user;
            cout << "tri" << (triNum - 1) << " " << 4 << " = " << user << endl;
            printVars(tri, triNum - 1);
        }
        else if (userLetter == "C") {
            cout << "Enter a value for variable 'C':";
            cin >> user;
            verifyResponse(user, 0, DBL_MAX);
            
            tri[triNum - 1][5] = user;
            cout << "C = " << user << endl;
            cout << "tri" << (triNum - 1) << " " << 5 << " = " << user << endl;
            printVars(tri, triNum - 1);
        }
        cout << endl;
    }
    if (userLetter == "0")
        cout << "Saving Measurements...\n\n";
    return 0;
}




/* Unused prototypes. Check bottom for definitions. */

void removeTriangle(vector< vector<double> > tri, int uInput);

bool confirm();

int main(int argc, char** argv) {
    
    /* VARIABLES */
    vector<vector<double> > triangles(5, vector<double> (7, 0));
    int userInput = -1,
            currTri;
            
    const string separator = "-------------------------------------------------------------------\n\n";
    
    //To be used...?
    const string vars[] = {"a", "b", "c", "A", "B", "C", "Area"};
    
    /* PROCESS*/
    //Fill the vector with zeroes for default data
    for (int i = 0; i < triangles.size(); i++) {
        for (int j = 0; j < triangles[0].size(); j++) {
            triangles[i][j] = 0;
        }
    }
    //Test print vector
    
    //Print program title and details
    cout << "Welcome to Triangle Solver!\n\n" <<
            "Solve the area, sides, and angles of any triangle. Each\n" <<
            "triangle requires a minimum of at least 3 measurements to\n" <<
            "solve.\n\n" <<
            separator;
            
    while (userInput != -3) {
        //Print Main Menu
        cout << "There are a total of " << triangles.size() << " triangle slots open. What would you " <<
                "like to do?\n\n" <<
                "0) Quit\n" <<
                "1) View triangle\n" <<
                "2) Clear triangle slot\n" <<
                "3) Add triangle slot\n\n" <<
                "I choose:\n";
        //User input
        cin >> userInput;
        verifyResponse(userInput, 0, 3);
        cout << "\n" << separator;
        
        //MAIN MENU PROCESSING
        switch (userInput) {
            case 0: //Quit
                cout << "Quitting...";
                userInput = -3;
                break;
            case 1: //View triangle
                //List each triangle slot
                cout << "Which triangle would you like to view?\n\n";
                printTriList(triangles);
                cout << endl;
                
                //User input
                cin >> currTri;
                verifyResponse(currTri, 0, (triangles.size() + 1));
                
                //Print results
                cout << "\n" << separator << "You chose triangle " << currTri << ".\n";
                userInput = 1;
                break;
            case 2: //Remove a triangle
                int temp; //Keeps the user's choice after warning message
                cout << "Which triangles would you like to clear data for?\n\n";
                printTriList(triangles);
                cout << endl;
                
                //User input
                cin >> userInput;
                temp = userInput;
                verifyResponse(userInput, 0, (triangles.size() + 1));
                
                cout << "Are you sure you want to delete triangle " << userInput << "? This action cannot be undone.\n\n" <<
                        "0 - NO\n" <<
                        "1 - YES\n\n";
                
                //User input
                cin >> userInput;
                verifyResponse(userInput, 0, 1);
                
                switch (userInput) {
                    case 0:
                        //NO
                        cout << "Keeping triangle " << temp << "...\n";
                        userInput = -2;
                        break;
                    case 1:
                        //YES
                        cout << "Deleting triangle " << temp << "...\n";
                        //Rewrite the entire vector without temp, then pop back the vector
                        for (int i = temp; i < triangles.size(); i++)
                            triangles[i - 1] = triangles[i];
                        triangles.pop_back();
                        
                        //Return userInput to -1 for default
                        userInput = -1;
                        cout << endl;
                        
                        //Test-print vector
                        printTriList(triangles);
                        cout << endl;
                        for (int i = 0; i < triangles.size(); i++)
                            printVars(triangles, i);
                        cout << "Triangles size = " << triangles.size() << endl;
                        cout << "\n" << separator;
                        userInput = -2;
                        break;
                }
                break;
            case 3: //Add a triangle slot
                triangles.resize(triangles.size() + 1, vector<double>(triangles[0].size() + 1, 0));
                
                printVars(triangles, triangles.size() - 1);
                cout << "\n" << separator;
                userInput = -2;
                break;
        }
        //END MAIN MENU PROCESSING
        
        while (userInput > -1) { //TRIANGLE VIEW MENU
            int dataStatus;
            printVars(triangles, currTri - 1);
            
            //Print menu
            cout << "Triangle " << currTri << " Menu\n" <<
                    "What would you like to do?\n\n" <<
                    "0 - Return to Main Menu\n" <<
                    "1 - View Solution Status\n" <<
                    "2 - Edit measurements\n\n";
            //User input
            cout << "I choose:\n";
            cin >> userInput;
            verifyResponse(userInput, 0, 2);
            
            cout << "\n\n" << separator << endl;
            
            //TRIANGLE VIEW MENU PROCESSING
            switch (userInput) {
                case 0: //Return to Main Menu
                    cout << "Area you sure you want to return to the Main Menu?\n\n" <<
                            "0 - NO\n" <<
                            "1 - YES\n";
                    
                    cin >> userInput;
                    verifyResponse(userInput, 0, 1);
                    
                    if (userInput == 1)
                        userInput = -1;
                    break;
                case 1: //Solution Status
                    
                    /* return int defs:
                     * 1 - Solved
                     * 2 - Not enough data
                     * 3 - Ready to solve
                     * 4 - Too many angles (AAA)
                     */
                    dataStatus = dataCompatability(triangles, currTri);
                    switch (dataStatus) {
                        case 1: //Solved
                            cout << "What would you like to do?\n" <<
                                    "1 - Return to Triangle " << currTri << " Menu\n";
                            cin >> userInput;
                            verifyResponse(userInput, 1, 1);
                            break;
                        case 2: //Not enough data
                            cout << "What would you like to do?\n" <<
                                    "1 - Return to Triangle " << currTri << " Menu\n";
                            cin >> userInput;
                            verifyResponse(userInput, 1, 1);
                            break;
                        case 3: //Ready to solve
                            cout << "Solve Triangle?\n" <<
                                    "0 - NO, return to Triangle " << currTri << " Menu\n" <<
                                    "1 - YES\n";
                            cin >> userInput;
                            verifyResponse(userInput, 0, 1);
                            if (userInput == 1)
                                findSolution(triangles, currTri);
                            break;
                        case 4: //Too many angles
                            cout << "What would you like to do?\n" <<
                                    "1 - Return to Triangle " << currTri << " Menu\n";
                            cin >> userInput;
                            verifyResponse(userInput, 1, 1);
                            break;
                    }
                    break;
                case 2: //Edit Measurements
                    cout << "Edit Measurements\n\n" <<
                            "Here, you can edit any of the sides or angles of the triangle (the area cannot be\n" <<
                            "edited--it will appear in the Solution Status section when the triangle is solved).\n\n" <<
                            "These are the requirements/notes to solving the triangle:\n\n" <<
                            "- Must include at least 3 measurements (cannot include more than 3)\n" <<
                            "- The 3 measurements may not include only angles\n" <<
                            "- The 3 measurements may include only sides\n" <<
                            "- Cannot edit Area, as previously mentioned\n\n";
                    printVars(triangles, (currTri - 1));
                    userInput = editMeasurements(triangles, currTri);
            }
            cout << "\n\n" << separator;
        }
    }
    return 0;
}
