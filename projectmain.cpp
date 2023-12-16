// projectmain.cpp
// Ezekiel McCormack
// 2023-12-1

// the main for my cs301 project


#include <vector>
using std::vector;
#include <string>
using std::string; 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "recipe.hpp"

// initialize explore so it can be used in selection
void explore(Recipe &item, int page);

void selection(vector<Recipe> & recipeBook) { //handle recipe inputs
    string input;
    while (cin >> input) {
        for (Recipe item : recipeBook) { // check if user input is a recipe option
            if (input == item._foodName) {
                explore (item, 0);
                cout << "End of program" << endl;
                exit(0);
            }
            else {
                // do nothing
            }
        }
        if (input == "E" || input == "e") { // exit program
            break;
        }
        // if user input is invalid, wait for another input
    }
}

void explore(Recipe &item, int page) {  // navegate the recipe
    for (int i = 10; i > 0; i--) { // "clear" the screen
        cout << endl;
    }
    cout << "Use N for next, use P for previous, use E for exit" << endl; //how to navigate instructions
    cout << endl;
    cout << "Step " << page << endl;
    cout << item._proceedure[page] << endl;
    string input;
    while (cin >> input) {
        if (input == "N" || input == "n") {
            if (item._size > page + 1) {  //
                explore (item, page + 1); //recursive explore call
                break; // exit when explore exits
            }
            else {
                //do nothing and wait for more input
            }
        }
        else if (input == "P" || input == "p") {
            if (0 < page) { // 
                explore (item, page - 1); //recursive explore call
                break; // exit when explore exits
            }
            else {
                //do nothing and wait for more input
            }
        }
        else if (input == "E" || input == "e") {
            break; //exit
        }
        else {
            // invalid input, do nothing and wait for valid input
        }
    }
}

// initialize all the recipes
vector<Recipe> recipeBook;
Recipe toast("toast", {"Gather ingredients and cookware: \n 2 slices of bread \n 1 stick of butter \n toaster \n knife", 
    "Place bread in toaster and select a toast level from 3 to 5.", 
    "After toast \"pops\" apply thin layer of butter with knife.", 
    "Consume within 15 minutes."});
Recipe turkeySandwich("turkeysandwich", {"Gather ingredients and cookware: \n turkey slices \n bread or roll \n cheeze slice \n mustard \n toaster oven \n bread knife",
    "Slice yourself 2 peices of bread, or cut a roll in half",
    "take a desirable amount of turkey meat and place on bottom half of sandwich",
    "add 1 - 2 slices of cheese", "(optional) cook in toaster oven for 2 minutes if you prefer toasted", 
    "apply a small amount of mustard for flavor", "enjoy sandwich or place in sealed container for future consumption"});
Recipe pancake("pancake", {"Gather ingredients and cookware: \n pancake mix \n water \n bowl \n grittle \n spatula \n mixer",
    "preheat grittle to 375 deg F", "place 1 cup of pancake mix in bowl with 3/4 cup of water", 
    "mix soulution thouroghly", "pour out pancake mix on grittle so that it makes five evenly sized pancakes",
    "flip pancakes over when they are golden brown", "when second side is golden brown, remove from grittle",
    "enjoy with desired sides or toppings"});
Recipe pizzabagel("pizzabagel", {"Gather ingredients and cookware: \n bagel \n marinara sauce \n mozzarella cheeze \n pepperoni \n toaster oven \n bread knife",
    "Cut bagel in half with knife", "apply thin layer of marinara sauce to both halves of bagel", 
    "sprinkle on cheeze, then place 4 pepperoni on each bagel", 
    "cook bagels in toaster oven for 3-5 min or until cheeze is evenly melted", 
    "take out bagels and allow to cool for 2 min", " consume"});
    

int main() {
    // add recipes to vector
    recipeBook.push_back(toast);
    recipeBook.push_back(turkeySandwich);
    recipeBook.push_back(pancake);
    recipeBook.push_back(pizzabagel);
    // start menu
    cout << "Recipes are listed below:" << endl;
    // print recipe options
    for(Recipe item : recipeBook) {
        cout << item._foodName << endl;
    }

    cout << "Please type the name of the food you want the recipe for or E for exit:" << endl;
    // select recipe and navagate recipe
    selection(recipeBook);
    return 0;
}

