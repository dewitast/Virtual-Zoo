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

	/** @brief Destructor.
	  */
	virtual ~Dolphin() {}

	/** @brief Interact.
	  * Menampilkan suara Dolphin pada layar.
	  */
	string interact() {return ("A a a a a");}

	/** @brief Melakukan cloning untuk menciptakan objek baru
		@return Mengeluarkan pointer to dolphin objek tersebut
	  */
	virtual Dolphin* clone() const {return new Dolphin(*this);}

	/** @brief render.
	  * Menentukan render dari dolphin.
	  * @return Mengembalikan char yang merupakan representasi objek ketika dicetak.
	  */
	char render(){return 'N';}
};

#endif