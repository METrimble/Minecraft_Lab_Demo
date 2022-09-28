#include <iostream>
#include <string>
#include <fstream> //include to open and close files

/****************
*Topics:
*Writing a design
*Reading from a file
*Bubble sort / any other sorting
*Writing to a file
*Makefiles
*Tar files and Warning
*************/

using namespace std;

void add_items(int num_items, ofstream& outf){
    int amount_item;
    string name_item;

    cout << "You currently have an empty inventory, before you go out to explore a cave what do you bring?" << endl;

    for(int index = 0; index < num_items; index++){
        cout << "Name of item: ";
        cin >> name_item;
        outf << name_item << " ";

        cout << "Amount of that item: ";
        cin >> amount_item;
        outf << amount_item << endl;

        cout << endl;
    }

    outf.close();
}

void print_inventory(int num_items, ifstream& inf){
    string line; //to hold the line that will be printed out

    cout << "Here is your current invetory: " << endl;
    while(getline(inf, line)){
        cout << line << endl;
    }

    inf.close();
}

int main(){
    int num_items = 0;

    /*write to the file*/
    ofstream outf("inventory.txt");

    //if the file is not open
    if(!(outf.is_open())){  
        cout << "The file did not open, the program will now quit." << endl;
        return 1;
    }

    //ask the user how many items they want in their inventory
    cout << "How many items do you want to hold in your inventory?: ";
    cin >> num_items;
    outf << num_items << endl;

    add_items(num_items, outf);

    /*Read from file*/
    ifstream inf("inventory.txt");

    if(!(inf.is_open())){
        cout << "The file did not open, the program will now quit" << endl;
        return 1;
    }

    print_inventory(num_items, inf);

    return 0;
}