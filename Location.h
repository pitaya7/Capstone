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
    
// Creates new Location with the summed rows and columns of 
inline Location operator+(const Location& first, const Location& second) {
    return Location{first.row + second.row, first.column + second.column};
}

// adds scale to row and column of location
inline Location operator+(const Location& first, int scale) {
    return Location{(first.row + scale), (first.column + scale)};
}

// for use with offset locations
inline Location operator*(const Location& first, int scale) {
    return Location{(first.row * scale), (first.column * scale)};
}

// increments row and column of location by 1
inline Location operator++(const Location& first) {
    return Location{(first.row + 1), (first.column + 1)};
}

inline bool operator>=(const Location& first, const Location& second) {
    return (first.row >= second.row && first.column >= second.column);
}

inline bool operator>=(const Location& first, const int second) {
    return (first.row >= second && first.column >= second);
}


inline bool operator<(const Location& first, const int second) {
    return (first.row < second && first.column < second);
}

inline bool operator<(const Location& first, const Location& second) {
    if (first.row > second.row)
        return false;
    else if (first.column < second.column)
        return true;
    else {
        return false;
    }
}


#endif