#ifndef FINAL_STORE_H
#define FINAL_STORE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include "Search.h"
#include "Asset.h"

using std::ifstream;
using std::vector;
using std::cout;
using std::endl;

class Store {
public:

    Store();
    ~Store();
    void addAsset( std::shared_ptr<Asset> );
    void displayInventory() const;
    void displayAvailableInventory();
    void displayList( vector< std::shared_ptr< Asset > >& );

    //Generic Search
    template<typename TT>
    void search( TT& comparitor ) const {
        for ( auto asset : inventory ) {
            comparitor( asset );
        }
    };

    int rentItem( int tag );
    bool returnItem( int tag );

private:
    vector< std::shared_ptr<Asset> > inventory; //holds every asset that the store owns, available and checkout
    vector< std::shared_ptr<Asset> > available; //holds every asset that is available for renting
    vector< std::shared_ptr<Asset> > checkedout; //holds every asset that has been rented
};

std::ostream& operator<<( std::ostream& out, const Asset* asset );
std::ostream& operator<<( std::ostream& out, const std::shared_ptr<Asset> asset );

#endif //FINAL_STORE_H
