#include "Factory.h"

void Factory::readBooks( Store& store, const string& filename ) throw(FileException) {
    //open the filename passed in
    ifstream infile;
    infile.open( filename );

    if ( infile ) {
        while ( !infile.eof() ) {
            //step through the file and read each book
            //then add it to the store
            Book* newBook = new Book();
            //newBook->readAssetFromFile( infile );

            string title;
            string creator;
            string genre;
            string release_date;
            string count;
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
                newBook->setAgeRating( Asset::ADULTS );
            } else if ( age == "Teens" ) {
                newBook->setAgeRating( Asset::TEENS );
            } else if ( age == "Children" ) {
                newBook->setAgeRating( Asset::CHILDREN );
            }

            if ( avail == "1" ) {
                newBook->setAvailability(true);
            } else {
                newBook->setAvailability(false);
            }

            newBook->setTitle( title );
            newBook->setAuthor( creator );
            newBook->setGenre( genre );
            newBook->setCount( count );
            newBook->setReleaseDate( release_date );

            store.addAsset( newBook );
        }
    } else {
        throw;
    }

    infile.close();
}

void Factory::readVideos( Store& store, const string& filename ) throw(FileException) {
    //open the filename passed in
    ifstream infile;
    infile.open( filename );

    if ( infile ) {
        while ( !infile.eof() ) {
            //step through the file and read each video
            //then add it to the store
            Video* newVideo = new Video();
            //newVideo->readAssetFromFile( infile );

            string title;
            string creator;
            string genre;
            string count;
            string release_date;
            string age;
            string movie_rating;
            string avail;
            string trash;

            getline(infile, title);
            getline(infile, creator);
            getline(infile, genre);
            getline(infile, count);
            getline(infile, movie_rating);
            getline(infile, age);
            getline(infile, release_date);
            getline(infile, avail);
            getline(infile, trash);

            if (age == "Adults") {
                newVideo->Asset::setAgeRating(Asset::ADULTS);
            } else if (age == "Teens") {
                newVideo->Asset::setAgeRating(Asset::TEENS);
            } else if (age == "Children") {
                newVideo->Asset::setAgeRating(Asset::CHILDREN);
            }

            if ( movie_rating == "PG" ) {
                newVideo->setAgeRating( Video::PG );
            } else if ( movie_rating == "PG-13" ) {
                newVideo->setAgeRating( Video::PG_13 );
            } else if ( movie_rating == "R" ) {
                newVideo->setAgeRating( Video::R );
            }

            if (avail == "1") {
                newVideo->setAvailability(true);
            } else {
                newVideo->setAvailability(false);
            }

            newVideo->setTitle( title );
            newVideo->setAuthor( creator );
            newVideo->setGenre( genre );
            newVideo->setCount( count );
            newVideo->setReleaseDate( release_date );

            store.addAsset( newVideo );
        }
    } else {
        throw;
    }

    infile.close();
}