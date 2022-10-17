#include <iostream>
#include <string>
#include <fstream> //include to open and close files

/****************
*Topics:
*Writing a design
*Reading from a file
*Writing to a file
*Makefiles
*************/

using namespace std;

struct item{
    string name;
    int amount_item;
};

item* add_items(int num_items, ofstream& outf){
    //create inventory
    item* inventory = new item[num_items];  

    cout << "You currently have an empty inventory, before you go out to explore a cave what do you bring?" << endl;

    //loop through and ask for the item's info, then store in file
    for(int index = 0; index < num_items; index++){
        cout << "item " << index << endl; 

        cout << "Name of item: ";
        cin >> inventory[index].name;
        outf << inventory[index].name << " ";

        cout << "Amount of that item: ";
        cin >> inventory[index].amount_item;
        outf << inventory[index].amount_item << endl;

        cout << "---------------------";
    }

    outf.close();

    return inventory;
}

int main(){
    int num_items = 0;

    /*write (cout) to the file*/
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

    item* inventory = add_items(num_items, outf);

    /*Read from file - reference*/
    /****************
    ifstream inf("inventory.txt");

    if(!(inf.is_open())){
        cout << "The file did not open, the program will now quit" << endl;
        return 1;
    }
    *****************/

    //free heap memory
    delete [] inventory;

    return 0;
}
