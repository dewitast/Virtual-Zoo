/**	@file	Goat.h
  */

#ifndef GOAT_H
#define GOAT_H

#include "Herbivore.h"
#include "LandAnimal.h"
#include "Mammal.h"

/** @class Goat
  * Kelas Goat merupakan kelas untuk real object Goat
  */
class Goat : public LandAnimal, public Herbivore, public Mammal {
public:
	/** @brief Constructor.
	  * Menciptakan objek Goat.
	  */
	Goat() : Animal(90, 4.5, false) { }

	/** @brief Constructor.
	  * Menciptakan objek Goat dengan berat w, jumlah makanan f, dan status jinak t
	  * @param w Berat Goat.
	  * @param f Jumlah makanan Goat.
	  * @param t Status jinak Goat.
	  */
	Goat(float w, float f, bool t) : Animal(w, f, t) { }

	/** @brief Destructor.
	  */
	virtual ~Goat() {}
	
	/** @brief interact.
	  * @return Mengembalikan string yang merepresentasikan suara Goat.
	  */
	string interact() {return ("Mbeeeee");}

	/** @brief Melakukan cloning untuk menciptakan objek Goat baru
	  * @return Mengembalikan pointer to Goat objek tersebut.
	  */
	virtual Goat* clone() const {return new Goat(*this);}

	/** @brief render
	  * @return Mengembalikan char yang merupakan representasi kode Goat.
	  */
	char render(){return 'G';}

};

#endif