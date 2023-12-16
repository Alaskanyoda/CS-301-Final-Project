// recipe.hpp
// Ezekiel McCormack
// 2023-12-1

// recipe struct


#ifndef FILE_RECIPE_HPP_INCLUDED
#define FILE_RECIPE_HPP_INCLUDED

#include <vector>
using std::vector;
#include <string>
using std::string; 



struct Recipe {
    // struct data members
    string _foodName; // name of food
    vector<string> _proceedure; // vector to contain steps in the recipe
    int _size; // easier access to # of steps in recipe
    // constructors
    Recipe() {
        _foodName = "blank";
        _proceedure = {"step 1", "step 2", "step 3"};
        _size = _proceedure.size();
    }
    Recipe(string foodname, vector<string> proceedure) {
        _foodName = foodname;
        _proceedure = proceedure;
        _size = _proceedure.size();
    }
};

#endif //#ifndef FILE_RECIPE_HPP_INCLUDED