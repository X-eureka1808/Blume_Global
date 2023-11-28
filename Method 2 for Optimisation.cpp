//Warehouse 1
//Method 2
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    // Distance matrix
    int cities = 7;
    int distance[8][8] = {
        { 1000, 180, 130, 240, 210, 220, 170, 180},
        { 180, 1000, 20, 25, 30, 26, 35, 15},
        {130, 20, 1000, 15, 18, 20, 25, 24},
        {240, 25, 15, 1000, 20, 24, 23, 21},
        {210, 30, 18, 20, 1000, 25, 23, 20},
        {220, 26, 20, 24, 25, 1000, 15, 18},
        {170, 35, 25, 23, 23, 15, 1000, 20},
        {180, 15, 24, 21, 20, 18, 20, 1000}
    };

    // Create a matrix (distance2) with each row sorted in ascending order
    int distance2[8][7];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            distance2[i][j] = distance[i][j + 1];
        }
        cout << endl;
    }

    // Sort each row of distance2
    for (int i = 0; i < 8; ++i) {
        sort(begin(distance2[i]), end(distance2[i]));
    }

    // Initialize variables for route optimization
    int row = 0, index = 0, quantity_wt = 0, quantity_v = 0, dst = 0;
    int q_wt[cities] = {11201, 15249, 27301, 22126, 29946, 9467, 16585};
    int q_v[cities] = {667, 874, 1104, 1150, 1689, 861, 1115};
    int route[10] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
    int Q_wt = 61200, Q_v = 2389, r = 0, i = 0, d = 0;

    // Iterate through cities to create an optimized delivery route
    for (int p = 0; p < cities; p++) {
        for (int j = 1; j < cities + 1; j++) {
            if (distance[row][j] == distance2[row][d]) {
                if (j == index) continue;
                index = j;

                // Check if the city has already been visited
                for (int m = 0; m < 10; m++) {
                    if (route[m] == index) {
                        p--; d++; break;
                    }
                    if (m == 9) d = 0;
                }

                if (d != 0) break;

                // Update quantity and check weight/volume constraints
                quantity_wt = quantity_wt + q_wt[index - 1];
                quantity_v = quantity_v + q_v[index - 1];
                if (quantity_wt > Q_wt || quantity_v > Q_v) {
                    quantity_wt = 0;
                    quantity_v = 0;
                    quantity_wt = quantity_wt + q_wt[index - 1];
                    quantity_v = quantity_v + q_v[index - 1];
                    route[i] = -1;
                    i++;
                }

                break;
            }
        }

        if (d == 0) {
            route[i] = index;
            row = index;
            i++;
        }
    }

    // Display the optimized delivery route
    int count =1;
    cout<<"Route 1(Starts and ends at 0)=> ";
    for (int r = 0; r < 10; r++) {
        if(route[r]==-1) {
            count++;
            cout<<endl<<"Route "<<count<<"(Starts and ends at 0)=> ";
        }
        else cout << route[r] << " ";
    }
    cout << endl << endl << endl;

    // Calculate and display the total distance traveled
    dst = dst + distance[0][route[0]];
    for (int r = 1; r < 10; r++) {
        if (route[r] != -1 && route[r - 1] != -1) {
            dst = dst + distance[route[r - 1]][route[r]];
        }
        else if (route[r] == -1) {
            dst = dst + distance[0][route[r - 1]];
        }
        else {
            dst = dst + distance[0][route[r]];
        }
    }

    cout << "Distance traveled is " << dst << endl;

    return 0;
}

   
