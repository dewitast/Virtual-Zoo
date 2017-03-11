//File : Dugong.h

#ifndef DUGONG_H
#define DUGONG_H

#include "Mammal.h"
#include "Herbivore.h"
#include "WaterAnimal.h"

/** @class Dugong.
  * Kelas Dugong merupakan kelas untuk real object Dugong.
  */
class Dugong : public WaterAnimal, public Herbivore, public Mammal{
public:
	/** @brief Constructor.
	  * Menciptakan objek Dugong.
	  */
	Dugong() : Animal(500, 25, true) {}

	/** @brief Constructor.
	  * Menciptakan objek Dugong dengan berat w, jumlah makanan f, dan status jinak t.
	  * @param w Berat Dugong.
	  * @param k Jumlah makanan Dugong.
	  * @param t Status jinak Dugong.
	  */
	Dugong(float w, float f, bool t) : Animal(w, f, t) {}

	/** @brief Interact.
	  * Menampilkan suara Dugong ke layar.
	  */
	string interact() {return ("Splashh!");}

	
	/** @brief Melakukan cloning untuk menciptakan objek baru
		@return Mengeluarkan pointer to Dugong objek tersebut
	  */
	virtual Dugong* clone() const {return new Dugong(*this);}
};

#endif