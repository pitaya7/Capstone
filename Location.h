/*
 * Defines Location structure to store pairs of (row, column) ints
 
**/

#ifndef LOCATION_H
#define LOCATION_H

#include <ostream>


struct Location 
{
    int row;
    int column;

    // Checks if locations have the same row and column 
    bool operator==(const Location& other) const {
        return row == other.row && column == other.column;
    }
    
    /* Creates new Location with the summed rows and columns of 
     *      this and another location. Used when moving pieces                      */
    Location operator+(const Location& other) const {
        return Location{row + other.row, column + other.column};
    }
    
    // Output location (for debug)
    friend std::ostream& operator<<(std::ostream& os, const Location& location) {
        os << "(" << location.row << ", " << location.column << ")";
        return os;
    }
};




#endif