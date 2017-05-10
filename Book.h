//
// Created by devpin on 4/27/2017.
//

#ifndef FINAL_BOOK_H
#define FINAL_BOOK_H

#include <fstream>
#include "Asset.h"

class Book: public Asset {
public:
    Book() : Asset() { /*EMPTY BODY*/ };
    Book( const string& t ) : Asset( t ) { /*EMPTY BODY*/ };
    //void setPageCount( const int& count ) { page_count = count; };
    virtual string getCount( void ) const { return count + " pages"; }
};


#endif //FINAL_BOOK_H
