#include <bits/stdc++.h>
using namespace std;

/**
 * PATTERN ONE: Square-shaped #
 *      # # # 
 *      # # #
 *      # # #
 */
void patternOne(int rows) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cout << "# "; 
        }
        cout << endl;
    }
}


/**
 * PATTERN TWO: Triangle-shaped #
 *      #  
 *      # # 
 *      # # #
 */
void patternTwo(int rows) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "# "; 
        }
        cout << endl;
    }
}

/**
 * PATTERN THREE: Triangle-shaped numbers
 *      1  
 *      1 2 
 *      1 2 3
 */
void patternThree(int rows) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << j + 1 << " "; 
        }
        cout << endl;
    }
}

/**
 * PATTERN FOUR: Triangle-shaped numbers
 *      1  
 *      2 2 
 *      3 3 3
 */
void patternFour(int rows) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << i + 1 << " "; 
        }
        cout << endl;
    }
}

/**
 * PATTERN FIVE: Triangle-shaped #
 *      # # #  
 *      # # 
 *      #
 */
void patternFive(int rows) {
    for(int i = 0; i < rows; i++) {
        for (int j = rows - i; j > 0 ; j--) {
            cout << "# "; 
        }
        cout << endl;
    }
}

/**
 * PATTERN SIX: Triangle-shaped numbers
 *      1 2 3  
 *      1 2 
 *      1
 */
void patternSix(int rows) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i ; j++) {
            cout << j + 1 << " "; 
        }
        cout << endl;
    }
}


/**
 * PATTERN SEVEN: Upside pyramid
 *        #  
 *      # # #
 *    # # # # #
 */
void patternSeven(int rows) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < 2*(rows)-1; j++) {
            if (j < rows - i - 1) {
                cout << " ";
            } else if (j >= rows - i - 1 && j < rows - i + 2*i) {
                cout << "#"; 
            } else {
                break;
            }
        }
        cout << endl;
    }
}

/**
 * PATTERN EIGHT: Downside pyramid
 *      # # # # #     
 *        # # #  
 *          # 
 */
void patternEight(int rows) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < 2*(rows)-1; j++) {
            if (j < i) {
                cout << " ";
            } else if (j >= i && j < 2*(rows)-1 - i ) {
                cout << "#"; 
            } else {
                break;
            }
        }
        cout << endl;
    }
}

/**
 * PATTERN NINE: Upside pyramid
 *        #  
 *      # # #
 *    # # # # #
 *    # # # # #     
 *      # # #  
 *        # 
 */
void patternNine(int rows) {
    patternSeven(rows);
    patternEight(rows);
}

/**
 * PATTERN TEN: Sideway pyramid
 *    #  
 *    # # 
 *    # # # 
 *    # #      
 *    #  
 */
void patternTen(int rows) {
    if (rows % 2 == 0) {
        return;
    }
    for (int i = 0; i < rows/2; i++) {
        for(int j = 0; j < i + 1; j++) {
            cout << "# ";
        }
        cout << endl;
    }
    int mid = 1 + (rows/2);
    for (int i = 0; i < mid; i++) {
        cout << "# ";
    }
    cout << endl;

    for (int i = 0; i < rows/2; i++) {
        for(int j = 0; j < (rows/2) - i; j++) {
            cout << "# ";
        }
        cout << endl;
    }
}

/**
 * PATTERN ELEVEN: Binary
 *    1  
 *    0 1 
 *    1 0 1 
 *    0 1 0 1     
 */
void patternEleven(int rows) {
    for (int i = 0 ; i < rows; i++) {
        int start = (i+1)%2;
        for (int j = 0; j < i + 1; j++) {
            cout << start;
            start ^= 1;
        }
        cout << endl;
    }
}

void printPattern(int patternNumber) {
    int rows;
    cin >> rows;
    switch (patternNumber) {
        case 1: 
            patternOne(rows);
            break;
        case 2: 
            patternTwo(rows);
            break;
        case 3: 
            patternThree(rows);
            break;
        case 4: 
            patternFour(rows);
            break;
        case 5: 
            patternFive(rows);
            break;
        case 6: 
            patternSix(rows);
            break;
        case 7: 
            patternSeven(rows);
            break;
        case 8: 
            patternEight(rows);
            break;
        case 9: 
            patternNine(rows);
            break;
        case 10: 
            patternTen(rows);
            break;
        case 11: 
            patternEleven(rows);
            break;
    }
}

int main() {
    cout << "Enter number of tests: ";
    int tests;
    cin >> tests;
    int patternNumber;
    cout << "Enter number between 1 and 22" << endl;
    cin >> patternNumber;
    while(tests--) {
        printPattern(patternNumber);
    }
    return 0;
}