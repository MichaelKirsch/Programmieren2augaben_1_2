#include <iostream>
#include "src/Animal.h"
#include <memory>
#include <vector>
#include "src/Dragon.h"
#include "src/Dog.h"

//hier die erklärung warum using namespace std keine gute idee ist:
//https://www.geeksforgeeks.org/using-namespace-std-considered-bad-practice/
int main() {

    auto lokalesAnimal = Animal("Lokales Animal (main scope)",1); //auto keyword is just taking the return value of the function that is assigned
    auto heapAnimal = std::make_unique<Animal>("Heap Animal (main scope)",2); //make unique can be used instead of new
    {
        auto lokalerDrache = Dragon("Holger der lokale Drache",1,4);
        auto heapDog = std::make_unique<Dog>("Franz der lokale head Hund", 1, dogtypes::maddog, 3);
        heapDog->bark();
        lokalerDrache.feuerspeien();
        //they are in a local scope. unique pointer will call delete when the scope is left
    }



    std::vector<RenderAble> allRenderableObjects;
    allRenderableObjects.resize(10); //always resize your vector to save space and copytime, as the
    //vector will have to be copied everytime it grows. but when you resize before, enough space will be reserved
    for(int x =0;x< 10;x++)
    {
        int random = rand()%4;
        switch (random)
        {
            //watch out: here we have slicing. When you create a Dog in a vector of Renderable, it will cut off the dog
            //specific methods. When you want to have multiple dogs you need a vector of dogs and you can update all animals
            //by having a big vector with pointers of renderable things. that way you dont have slicing
            case 0:
                allRenderableObjects.emplace_back(Dog("DOG"+std::to_string(x),x,dogtypes::underdog,x));
                //there will be some destroyed objects visible in the log. These are only the temporary obejcts that get created
                //when you construct in place
                break;
            default:
                allRenderableObjects.emplace_back(Dragon("DRAGON"+std::to_string(x),x,x));
                break;
        }
    }


    for(auto rend:allRenderableObjects)
    {
        rend.update();
        rend.render();
    }

    return 0;
}
