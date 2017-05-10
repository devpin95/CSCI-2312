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
    virtual void readAssetFromFile( std::ifstream& infile ) {
        string age;
        string avail;
        string trash;

        getline(infile, title);
        getline(infile, creator);
        getline(infile, genre);
        getline(infile, count);
        getline(infile, age);
        getline(infile, release_date);
        getline(infile, avail);
        getline(infile, trash);

        if ( age == "Adult" ) {
            this->setAgeRating( Asset::ADULTS );
        } else if ( age == "Teens" ) {
            this->setAgeRating( Asset::TEENS );
        } else if ( age == "Children" ) {
            this->setAgeRating( Asset::CHILDREN );
        }

        if ( avail == "1" ) {
            this->availability = true;
        } else {
            this->availability = false;
        }

    };
};


#endif //FINAL_BOOK_H
