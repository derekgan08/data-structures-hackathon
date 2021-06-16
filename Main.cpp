#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Event.h"
#include "Inventory.h"
#include "LinkedList.h"
#include "Player.h"
#include "Area.h"

using namespace std;

//Markdown
void mapUI(); //Map
void winUI();//Win UI
void loseUI(); //Lose UI
void gameNameUI(); //Display game name UI

	
bool fileExists(const string& filename) {
	ifstream file(filename);
	return file.is_open();  // Returns true if file exists and can be opened
}

int main() {
	
	//INITIALISATION
	ifstream infileDescription;
	infileDescription.open("Description.txt");
	string temp_line;
	//EventList
	LinkedList<Event> eventList;
	/* PLANEWRECK1 EVENT*/
	Event event0;
	event0.event_ID = 0;
	getline(infileDescription, temp_line);
	event0.description = temp_line; 
	
	Event event1;
	event1.event_ID = 1;
	getline(infileDescription, temp_line);
	event1.description = temp_line; 
	
	Event event2;
	event2.event_ID = 2;
	getline(infileDescription, temp_line);
	event2.description = temp_line; 
	
	eventList.appendNode(event0);
	eventList.appendNode(event1);
	eventList.appendNode(event2);

	/* PLANEWRECK2 EVENT*/
	Event event3;
	event3.event_ID = 3;
	getline(infileDescription, temp_line);
	event3.description = temp_line; 

	Event event4;
	event4.event_ID = 4;
	getline(infileDescription, temp_line);
	event4.description = temp_line; 

	Event event5;
	event5.event_ID = 5;
	getline(infileDescription, temp_line);
	event5.description = temp_line; 

	eventList.appendNode(event3);
	eventList.appendNode(event4);
	eventList.appendNode(event5);

	/* RIVER EVENT*/
	Event event6;
	event6.event_ID = 6;
	getline(infileDescription, temp_line);
	event6.description = temp_line; 

	Event event7;
	event7.event_ID = 7;
	getline(infileDescription, temp_line);
	event7.description = temp_line; 
	
	Event event8;
	event8.event_ID = 8;
	getline(infileDescription, temp_line);
	event8.description = temp_line; 
	
	eventList.appendNode(event6);
	eventList.appendNode(event7);
	eventList.appendNode(event8);

	/* FOREST EVENT*/
	Event event9;
	event9.event_ID = 9;
	getline(infileDescription, temp_line);
	event9.description = temp_line; 

	Event event10;
	event10.event_ID = 10;
	getline(infileDescription, temp_line);
	event10.description = temp_line; 
	
	Event event11;
	event11.event_ID = 11;
	getline(infileDescription, temp_line);
	event11.description = temp_line; 
	
	eventList.appendNode(event9);
	eventList.appendNode(event10);
	eventList.appendNode(event11);

	/* VILLAGE EVENT*/
	Event event12;
	event12.event_ID = 12;
	getline(infileDescription, temp_line);
	event12.description = temp_line; 

	Event event13;
	event13.event_ID = 13;
	getline(infileDescription, temp_line);
	event13.description = temp_line; 
	
	Event event14;
	event14.event_ID = 14;
	getline(infileDescription, temp_line);
	event14.description = temp_line; 
	
	eventList.appendNode(event12);
	eventList.appendNode(event13);
	eventList.appendNode(event14);
	

	//InventoryList
	LinkedList<Inventory> inventoryList;
	/* PLANEWRECK1 ITEM*/
	Inventory item2;
	item2.item_ID=2;
	item2.item_message = "\nYou got the Teddy Bear!\n";
	item2.item_name = "Teddy";
	/* PLANEWRECK2 ITEM*/
	Inventory item5;
	item5.item_ID=5;
	item5.item_message = "\nYou got an axe!\n";
	item5.item_name = "Axe";
	/* FOREST ITEM */
	Inventory item11;
	item11.item_ID=11;
	item11.item_message = "\nPlanks could be used to build a boat!\n";
	item11.item_name = "Planks";


	//Object Initialization
	Player player;
	EmptyGround ground;
	PlaneWreck1 wreck1;
	PlaneWreck2 wreck2;
	River river;
	Forest forest;
	Village village;

	//Set area_ID for each area
	ground.setarea_ID(0);
	wreck1.setarea_ID(1);
	wreck2.setarea_ID(2);
	river.setarea_ID(3);
	forest.setarea_ID(4);
	village.setarea_ID(5);

	//Random seed generator
	unsigned int seed = time(NULL);
	srand(seed);
	
	gameNameUI();
		
	//Dashboard to choose new game, load game or quit.
    // Check if all the necessary files exist
    bool filesExist = fileExists("HP.txt") && fileExists("Area.txt") && fileExists("Inventory.txt");

    if (filesExist) {
        // If the files exist, display both "New Game" and "Load Game" options
        cout << "1. New Game" << endl;
        cout << "2. Load Game" << endl;
    } else {
        // If the files do not exist, only show "New Game"
        cout << "1. New Game" << endl;
    }
	cout << "Enter any key to Quit Game" << endl;
	int winCode; //Special code for not entering loseUI();
	int area;
	int dashboard;
	cin >> dashboard;

	switch(dashboard) {
		case 2: {
			//load previous game
			ifstream infileHP, infileArea_ID, infileItem_ID;
			infileHP.open("HP.txt");
			int temp_HP=0;
			infileHP >> temp_HP;
			player.setLoadHP(temp_HP);
			infileHP.close();
			
			infileArea_ID.open("Area.txt");			
			infileArea_ID >> area;
			infileArea_ID.close();
			
			infileItem_ID.open("Inventory.txt");
			while(!infileItem_ID.eof()){
				int temp_Item_ID;
				infileItem_ID >> temp_Item_ID;
				switch(temp_Item_ID){
					case 2:{
						if(!inventoryList.itemExist(temp_Item_ID))
						inventoryList.appendNode(item2);
						break;
					}
					case 5:{
						if(!inventoryList.itemExist(temp_Item_ID))
						inventoryList.appendNode(item5);
						break;
					}
					case 11:{
						if(!inventoryList.itemExist(temp_Item_ID))
						inventoryList.appendNode(item11);
						break;
					}
				}
				eventList.deleteEvent(temp_Item_ID);
			}
			infileItem_ID.close();			
		}
	}

	return 0;
}