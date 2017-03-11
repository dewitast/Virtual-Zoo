//file : Dolphin.h

#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "Carnivore.h"
#include "WaterAnimal.h"
#include "Mammal.h"

/** @class Dolphin
  * kelas Dolphin merupakan kelas untuk real object Dolphin
  */

class Dolphin : public WaterAnimal, public Carnivore, public Mammal {
public:
	/** @brief Constructor.
	  * Menciptakan objek Dolphin.
	  */
	Dolphin() : Animal(75, 3.75, false) { }

	/** @brief Constructor.
	  * Menciptakan objek Dolphin dengan berat w, jumlah makanan f, dan status jinak t.
	  * @param w Berat Dolphin.
	  * @param f Jumlah makanan Dolphin.
	  * @param t Status jinak Dolphin.
	  */
	Dolphin(float w, float f, bool t) : Animal(w, f, t) { }

	string interact() {return ("A a a a a");}
};

#endif