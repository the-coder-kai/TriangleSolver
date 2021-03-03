/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>

using namespace std;

/* UNUSED FUNTION DEFINITIONS
bool confirm() {
    int answer;
    cout << "Are you sure?\n" <<
            "0 - NO\n" <<
            "1 - YES\n";
    cin >> answer;
    
    verifyResponse(answer, 0, 1);
    
    if (answer == 0)
        return false;
    else
        return true;
} */
/* Function: confirm
 *
 * Input:
 * - none
 * 
 * Process:
 * 1. Ask the user if they want to continue with their action
 * 
 * Output:
 * - bool (True for No and False for Yes)
 */

/*
void removeTriangle(vector< vector<double> > tri, int uInput) {
    for (int i = uInput - 1; i < tri.size() - 1; i++) {
        for (int j = 0; j < tri[0].size(); j++) {
            tri[i][j] = tri[i + 1][j];
            cout << "checkmate. Element [" << i << "][" << j << "] = " << tri[i][j] << " received from " <<
                    "element [" << (i + 1) << "][" << j << "] = " << tri[i + 1][j] << endl;
        }
        cout << "\n\n";
    }
    tri.pop_back();
    printTriList(tri);
    for (int i = 0; i < tri.size(); i++)
        printVars(tri, i);
} */