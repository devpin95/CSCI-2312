//
// Created by devpin on 4/27/2017.
//

#ifndef FINAL_VIDEO_H
#define FINAL_VIDEO_H

#include "Asset.h"
#include <fstream>

class Video: public Asset {
public:

    //video specific age ratings
    enum video_age_rating {
        PG = 0,
        PG_13,
        R
    };

    Video( void ) : Asset() { /*EMPTY BODY*/ };
    Video( const string& t ) : Asset( t ) { /*EMPTY BODY*/ };

//    virtual void readAssetFromFile( std::ifstream& infile ) {
//        //manually read a video asset from a file
//
//        string age;
//        string movie_rating;
//        string avail;
//        string trash;
//
//        getline(infile, title);
//        getline(infile, creator);
//        getline(infile, genre);
//        getline(infile, count);
//        getline(infile, movie_rating);
//        getline(infile, age);
//        getline(infile, release_date);
//        getline(infile, avail);
//        getline(infile, trash);
//
//        if (age == "Adults") {
//            Asset::setAgeRating(Asset::ADULTS);
//        } else if (age == "Teens") {
//            Asset::setAgeRating(Asset::TEENS);
//        } else if (age == "Children") {
//            Asset::setAgeRating(Asset::CHILDREN);
//        }
//
//        if ( movie_rating == "PG" ) {
//            this->setAgeRating( Video::PG );
//        } else if ( movie_rating == "PG-13" ) {
//            this->setAgeRating( Video::PG_13 );
//        } else if ( movie_rating == "R" ) {
//            this->setAgeRating( Video::R );
//        }
//
//        if (avail == "1") {
//            this->availability = true;
//        } else {
//            this->availability = false;
//        }
//    };
    virtual void setAgeRating( const video_age_rating& r ) { video_rating = r; };
    string getVideoRating() const {
        if ( video_rating == 0 ) {
            return "PG";
        } else if ( video_rating == 1 ) {
            return "PG-13";
        } else {
            return "R";
        }
    };
    virtual string getCount( void ) const { return count + " minutes"; }

private:
    video_age_rating video_rating;
};


#endif //FINAL_VIDEO_H
