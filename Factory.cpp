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
            newBook->readAssetFromFile( infile );
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
            newVideo->readAssetFromFile( infile );
            store.addAsset( newVideo );
        }
    } else {
        throw;
    }

    infile.close();
}