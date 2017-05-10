#include <iostream>
#include "Store.h"
#include "Factory.h"

using namespace std;

void search( Store& );
void rent( Store&, vector<int>& );
void returnItem( Store&, vector<int>& );

int main() {

    Store store;
    Factory reader;
    vector<int> my_items;

    try {
        reader.readBooks(store, "books.txt");
        reader.readVideos(store, "videos.txt");
    } catch (FileException e) {
        cout << "Could not load file" << endl;
    }

    int selection;
    bool conti = true;

    do {
        cout << "Rental Store----------------------------------" << endl;
        cout << "1. See all items" << endl;
        cout << "2. See all available items" << endl;
        cout << "3. Search" << endl;
        cout << "4. Return Item" << endl;
        cout << "5. Rent Item" << endl;
        cout << "6. Exit" << endl;
        cout << ">" << endl;

        cin >> selection;

        switch ( selection ) {
            case 1:
                store.displayInventory();
                break;
            case 2:
                store.displayAvailableInventory();
                break;
            case 3:
                search( store );
                break;
            case 4:
                returnItem( store, my_items );
                break;
            case 5:
                rent(store, my_items);
                break;
            case 6:
                conti = false;
                break;
            default:
                break;
        }

    } while ( conti );


//    Book* newBook = new Book( "Hatchet" );
//    newBook->setCount( "189" );
//    newBook->setAuthor( "Devin Piner IV" );
//    newBook->setAgeRating( Asset::TEENS );
//    newBook->setGenre( "Adventure" );
//
//    Video* newVideo = new Video( "Psych" );
//    newBook->setCount( "152" );
//    newBook->setAuthor( "Wiessman" );
//    newBook->setAgeRating( Asset::ADULTS );
//    newBook->setGenre( "Comedy" );

//    store.returnItem( newBook );
//    store.returnItem( newVideo );

    return 0;
}

void rent( Store& store, vector<int>& items ) {
    int selection;
    int rental_item;

    do {
        cout << "Item number: ";
        cin >> selection;

        rental_item = store.rentItem(selection);

        if (rental_item == -1) {
            cout << "This item is not available" << endl;
        }
    } while ( rental_item == -1 );

    items.push_back( rental_item );
}

void returnItem( Store& store, vector<int>& my_items ) {
    int selection;
    bool is_valid = false;
    int index = -1;

    if ( my_items.size() == 0 ) {
        cout << "No items to return" << endl;
        return;
    }

    do {
        cout << "My Items: ";

        for (int i = 0; i < my_items.size(); ++i) {
            cout << " [" << my_items[i] << "] ";
        }

        cout << endl;

        cout << "Return #:";
        cin >> selection;

        for (int i = 0; i < my_items.size(); ++i) {
            if ( selection == my_items[i] ){
                index = i;
                is_valid = true;
                break;
            }
        }

    } while (!is_valid);

    my_items.erase( my_items.begin() + index );
    store.returnItem( selection );
}

void search( Store& store ) {
    Search searcher;
    int selection;

    cout << "Search By:" << endl;
    cout << "1. Title" << endl;
    cout << "2. Author" << endl;
    cout << "3. Genre" << endl;
    cin >> selection;

    cin.ignore(256, '\n');
    cin >> skipws;

    string target;
    switch (selection) {
        case 1: {
            cout << "Title: ";
            getline(cin, target);
            vector<Asset *> titles = searcher.searchByTitle(store, target);
            store.displayList(titles);
        }
            break;
        case 2: {
            cout << "Author: ";
            getline(cin, target);
            vector<Asset *> authors = searcher.searchByAuthor(store, target);
            store.displayList(authors);
        }
            break;
        case 3: {
            cout << "Genre: ";
            getline(cin, target);
            vector<Asset *> genres = searcher.searchByGenre(store, target);
            store.displayList( genres );
        }
    }
}



