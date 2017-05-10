#include "Store.h"
#include "Video.h"
#include "Book.h"

Store::Store() {

}

Store::~Store() {
    for ( auto i = inventory.size(); i >= 0; --i ) {
        Asset* tempPtr = inventory[i];
        inventory.pop_back();
        delete tempPtr;
    }
}

void Store::addAsset( Asset* asset ) {

    std::cout << asset->getTitle() << endl;

    inventory.push_back( asset );
    if ( asset->isAvailable() ) {
        available.push_back( asset );
    } else {
        checkedout.push_back( asset );
    }
}

int Store::rentItem(int tag) {
    int count = -1;
    int rent_tag = -1;

    //search for the item in the availables list
    for ( auto i = 0; i < available.size(); ++i ) {
        if ( std::to_string( tag ) == available[i]->getAssetTag() ) {
            //if we get in here, the item is available for renting
            count = i;
            rent_tag = stoi( available[i]->getAssetTag() );
            break;
        }
    }

    //if the item is available to rent
    if ( count != -1 ) {
        //copy the pointer in the availables list to a new pointer
        //the delete the item from the availabe list and make it unavailable for renting
        Asset* assetPtr = *(available.begin() + count);
        assetPtr->setAvailability(false);
        available.erase( available.begin() + count );

        //add the item to the checkout list
        checkedout.push_back( assetPtr );
    }

    return rent_tag;
}

bool Store::returnItem( int tag ) {
    bool is_ours = false;
    int count = 0;

    //first, make sure that the item being returned has the same asset tag
    //as an item in our checkout list
    string str_tag = std::to_string( tag );
    for ( auto i = 0; i < checkedout.size(); ++i ) {
        if ( str_tag == checkedout[i]->getAssetTag() ) {
            //if we get in here, the item is one of ours
            is_ours = true;
            count = i;
        }
    }

    //since the item is ours, create a copy of the pointer and add it back to the available list
    //then remove it from the checkedout list and make it available again for renting
    if ( is_ours ) {
        Asset* assetPtr = *(checkedout.begin() + count);
        assetPtr->setAvailability( true );
        available.push_back( assetPtr );
        checkedout.erase( checkedout.begin()+count );
    }

    return is_ours;
}

void Store::displayAvailableInventory() {
    //before displaying the available assets, sort it
    //based on asset tags
    std::sort( available.begin(), available.end() );
    displayList( available );
}

void Store::displayList( vector<Asset*>& list ) {
    //print out the headers
    cout << std::left;
    cout << std::setw( 10 ) << "Item#";
    cout << std::setw( 25 ) << "Title";
    cout << std::setw( 25 ) << "Author";
    cout << std::setw( 25 ) << "Genre";
    cout << std::setw( 25 ) << "Length(Pages/runtime)";
    cout << std::setw( 25 ) << "Age Rating";
    cout << std::setw( 25 ) << "Publish/Release Date";
    cout << std::setw( 25 ) << "Availability";
    cout << endl;

    //im lazy
    for ( int i = 0; i < 25 * 8; ++i ) {
        cout << "-";
    }
    cout << endl;

    if ( list.size() == 0 ) {
        //print that there are no assets available
        cout << "No Entries" << endl;
    } else {
        //print each of the assets available
        for (auto i = 0; i < list.size(); ++i) {
            cout << list[i] << endl;
        }
    }
}

void Store::displayInventory() const {
    //print out the headers
    cout << "Inventory: " << endl;
    cout << std::left;
    cout << std::setw( 10 ) << "Item#";
    cout << std::setw( 25 ) << "Title";
    cout << std::setw( 25 ) << "Author";
    cout << std::setw( 25 ) << "Genre";
    cout << std::setw( 10 ) << "Type";
    cout << std::setw( 25 ) << "Length(Pages/runtime)";
    cout << std::setw( 25 ) << "Age Rating";
    cout << std::setw( 25 ) << "Publish/Release Date";
    cout << std::setw( 25 ) << "Availablility";
    cout << endl;

    //im lazy
    for ( int i = 0; i < 25 * 8; ++i ) {
        cout << "-";
    }
    cout << endl;

    for ( auto i = 0; i < inventory.size(); ++i ) {
        //print out each asset in the inventory
        cout << inventory[i] << endl;
    }
}

std::ostream& operator<<( std::ostream& out, const Asset* asset ) {

    //see what the asset casts to
    //http://stackoverflow.com/questions/3605679/cast-const-class-using-dynamic-cast
    //this linked help with casting a const pointer
    const Video* videoPtr = nullptr;
    const Book* bookPtr = nullptr;

    videoPtr = dynamic_cast< const Video* >( asset );
    bookPtr = dynamic_cast< const Book* >( asset );

    //start printing out the asset information
    out << std::setw( 10 ) << asset->getAssetTag();
    out << std::setw( 25 ) << asset->getTitle();
    out << std::setw( 25 ) << asset->getCreator();
    out << std::setw( 25 ) << asset->getGenre();

    //based on the dynamic_cast, print out the type of asset we are dealing with
    if ( bookPtr != nullptr ) {
        out << std::setw(10) << "Book";
    } else {
        out << std::setw(10) << "Video";
    }

    out << std::setw( 25 ) << asset->getCount();

    //print out the age rating, and the video rating if we are dealing with a video
    if ( asset->getAgeRating() == Asset::CHILDREN ) {
        out << std::setw( 25 ) << "Children" + ( videoPtr != nullptr ? " - " + videoPtr->getVideoRating() : "" );
    } else if ( asset->getAgeRating() == Asset::TEENS ) {
        out << std::setw(25) << "Teens" + ( videoPtr != nullptr ? " - " + videoPtr->getVideoRating() : "" );
    } else if ( asset->getAgeRating() == Asset::ADULTS ) {
        out << std::setw(25) << "Adults" + ( videoPtr != nullptr ? " - " + videoPtr->getVideoRating() : "" );
    }

    out << std::setw( 25 ) << asset->getReleaseDate();

    if ( asset->isAvailable() ) {
        out << std::setw( 25 ) << "Available";
    } else {
        out << std::setw( 25 ) << "Checked Out";
    }

    return out;
}