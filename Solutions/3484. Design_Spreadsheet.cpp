class Spreadsheet {
public:
    unordered_map<string,int> cells;
    Spreadsheet(int rows) {

    }
    
    void setCell(string cell, int value) {
        cells[cell] =value;
    }
    
    void resetCell(string cell) {
        cells[cell] = 0;
    }
    
    int getValue(string formula) {
        string newFormat = formula.substr(1);
        auto signPos = newFormat.find("+");
        string X = newFormat.substr(0,signPos);
        string Y =newFormat.substr(signPos+1);

        int x;
        if(isdigit(X[0])){
            x=stoi(X);
        }
        else{
            if(cells.count(X)){
                x=cells[X];
            }
            else{
                x=0;
            }
        }

        int y;
            if(isdigit(Y[0])){
                y=stoi(Y);
            }
            else{
                if(cells.count(Y)){
                    y= cells[Y];
                }
                else{
                    y=0;
                }
            }
            return x+y;
        }

};


/**

1. What Data Structure Did We Choose and Why?

Chosen Data Structure:
    We used an unordered_map<string, int> to store the values of the spreadsheet cells.

Why unordered_map?
    Key-Value Mapping: Each cell (e.g., "A1", "B2") is a unique string key, and its value is an integer. unordered_map is ideal for such key-value pairs.

    Fast Access: unordered_map provides average O(1) time complexity for insert, delete, and lookup operations due to its underlying hash table implementation.
    Dynamic Size: The spreadsheet can have a large number of cells, but we only store non-zero values. This saves memory compared to using a 2D array or vector for the entire grid.

Why Not Other Data Structures?
    2D Array/Vector: A grid-like structure would waste memory because most cells are initialized to 0 and remain unused.
    Ordered Map (map): While map maintains sorted order, we don’t need that here. unordered_map is faster for our use case since we only care about direct access.


2. Why Is There No Code Logic in Spreadsheet(int rows)?

    The constructor Spreadsheet(int rows) initializes the spreadsheet with a fixed number of rows and 26 columns (A-Z). However, we don’t need to pre-populate the cells because we use the unordered_map to store only non-zero values.
Efficiency: By not initializing all cells to 0, we save memory. Cells are only added to the unordered_map when explicitly set using setCell


3. How Do setCell, resetCell, and getValue Work?
Let’s break them down one by one.

a) setCell(string cell, int value)
    Purpose: Sets the value of a specific cell in the spreadsheet.
How It Works:
    The cell parameter is a string (e.g., "A1").
    The value parameter is an integer to set for that cell.
    The cell and its value are stored in the unordered_map as a key-value pair.

Code Explanation:

    void setCell(string cell, int value) {
        cells[cell] = value; // Insert or update the key-value pair in the unordered_map
Time Complexity: O(1) on average for insertion in unordered_map.


b) resetCell(string cell)
    Purpose: Resets the value of a specific cell to 0.
How It Works:
    The cell parameter is the string key (e.g., "A1").
    The value for this key in the unordered_map is updated to 0.

Code Explanation:

void resetCell(string cell) {
    cells[cell] = 0; // Set the cell's value to 0
}
Time Complexity: O(1) on average for updating an existing key in unordered_map.



c) getValue(string formula)
    Purpose: Evaluates a formula of the form =X+Y, where X and Y are either cell references or integers, and returns the computed sum.

How It Works:
    Extracts the formula (e.g., =A1+5) by removing the = sign.
    Splits the formula into X and Y at the + sign.
    Checks whether X and Y are integers or cell references:
    If they are integers, convert them using stoi.
    If they are cell references, look up their values in unordered_map (default to 0 if not found).
    Computes and returns the sum of X and Y.

Code Explanation:

int getValue(string formula) {
    string newFormat = formula.substr(1); // Remove '='
    auto signPos = newFormat.find("+"); // Find the '+' sign
    string X = newFormat.substr(0, signPos); // Extract X
    string Y = newFormat.substr(signPos + 1); // Extract Y

    int x;
    if (isdigit(X[0])) {
        x = stoi(X); // Convert X to integer if it's a number
    } else {
        x = cells.count(X) ? cells[X] : 0; // Get value from map or default to 0
    }

    int y;
    if (isdigit(Y[0])) {
        y = stoi(Y); // Convert Y to integer if it's a number
    } else {
        y = cells.count(Y) ? cells[Y] : 0; // Get value from map or default to 0
    }

    return x + y; // Return the sum
}
Time Complexity: O(1) on average for each lookup in unordered_map.



 */