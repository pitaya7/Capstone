/*
 * Defines Location structure to store pairs of (row, column) ints
 * Also defines operator used to compare and manipulate Locations
**/

#ifndef LOCATION_H
#define LOCATION_H


struct Location 
{
    int row;
    int column;

};
    // Checks if locations have the same row and column 
inline bool operator==(const Location& first, const Location& second) {
    return first.row == second.row && first.column == second.column;
}
    
/* Creates new Location with the summed rows and columns of 
 *      two locations. Used when moving pieces                      */
inline Location operator+(const Location& first, const Location& second) {
    return Location{first.row + second.row, first.column + second.column};
}

// returns a location 
inline Location operator*(const Location& first, int scale) {
    return Location{(first.row + scale), (first.column + scale)};
}





#endif