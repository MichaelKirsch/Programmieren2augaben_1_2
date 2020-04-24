#include <iostream>
#include <memory>
#include <vector>

#include "src/basics.h"
#include "src/Animal.h"
#include "src/Dragon.h"
#include "src/Dog.h"

//ich verwende hier kein using namespace std wegen name pollution
int main() {
    //basics entspricht der aufgabe aus der vorlesung
    {
        //das auto keyword nimmt immer automatisch den objekttyp der rückgabe an. Hier: basics
        auto lokalesBasic = basics("hallo", 10); //lokales objekt auf dem stack
        auto heapBasics = new basics("peter",30); //opjekt wird auf dem heap erstellt.
        //aufgrund des begrenzten stack platzes ist es ratsam objekte auf dem heap auszulagern
        //dies kann man mit new oder mit einem smart pointer erreichen. ein erstellen auf dem heap
        //gibt immer einen pointer zurück

        //abrufen der methoden
        lokalesBasic.init(1);
        lokalesBasic.update();
        //abrufen der methoden über den pointer
        heapBasics->update();
        heapBasics->init(1);

        //zerstören der objekte, lokales muss nicht zerstört werden da es zerstört wird
        //wenn man ein objekt mit einem unique_ptr erstellt dann wird dieses auch zerstört wenn es den scope
        //verlässt
        //wenn der scope endet

        delete heapBasics; //löschen des objekts aus dem heap über den pointer
    }


    //aufgabe 2 mit animal und den erbenden hunden und drachen

    //das auto keyword nimmt automatisch den wert der Rückgabe an. In diesem Fall Animal
    auto lokalesAnimal = Animal("Nicht spezialisiertes Tier Stack",1);

    //erstellen auf dem heap mithilfe eines std::unique_ptr<Animal>
    auto heapAnimal = std::make_unique<Animal>("Nicht spezialisiertes Tier Heap", 2);

    {
        auto lokalerDrache = Dragon("Holger der lokale Drache", 1, 4);
        //lokales erstellen
        auto heapDog = std::make_unique<Dog>("Franz der lokale head Hund", 1, dogtypes::maddog, 3);
        //wieder erstellen auf dem heap
        heapDog->bark();
        lokalerDrache.feuerspeien();
       // beide objekte werden automatisch zerstört wenn sie den scope verlassen
    }

    std::vector<RenderAble*> pointersOfRenderable; //erstellen eines containers mit RenderAble*

    for (int x = 0; x < 10; x++) {
        //füllen des vectors mit 20 pointern zu heap objekten vom Typ Drache und Hund
        pointersOfRenderable.emplace_back(new Dragon("Drache "+ std::to_string(x),x,x));
        pointersOfRenderable.emplace_back(new Dog("Hund " + std::to_string(x), x, dogtypes::underdog, x));
    }

    for(auto& point:pointersOfRenderable)
    {
        //aufrufen der methoden die alle durch die Erbung von Renderable haben
        point->update();
        point->update();
        auto cast = dynamic_cast<Dog*>(point); //dynamischer cast zurück auf den hund
        if(cast!=NULL) // schauen ob der cast okay war
        {
            cast->bark(); // member methode von Hund aufrufen
        }
        auto drache = dynamic_cast<Dragon*>(point);
        if(drache!=NULL)
        {
            drache->feuerspeien(); //wieder aufruf der membermethode
        }
    }

    for(auto& member:pointersOfRenderable)
        delete member; //alle objekte löschen

    return 0;
    //oben erzeugte objekte gehen jetzt out of scope und werden zerstört
}
