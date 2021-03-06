/**	@file  dolphin.h
  */

#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "../carnivore/carnivore.h"
#include "../water_animal/water_animal.h"
#include "../mammal/mammal.h"

/** @class Dolphin
  * Kelas Dolphin merupakan kelas untuk real object Dolphin
  */
class Dolphin : public WaterAnimal, public Carnivore, public Mammal {
public :
  /** @brief Constructor.
    * Menciptakan objek Dolphin.
    */
  Dolphin() : Animal(75,3.75,true) {}
  /** @brief Constructor dengan parameter.
    * Menciptakan objek Dolphin dengan berat w, jumlah makanan f, dan status jinak t.
    * @param w Berat Dolphin.
    * @param f Jumlah makanan Dolphin.
    * @param t Status jinak Dolphin.
    */
  Dolphin(float w, float f, bool t) : Animal(w,f,t) {}
  /** @brief Destructor.
    */
  virtual ~Dolphin() {}
  /** @brief Interaksi yang dilakukan Dolphin.
	  * @return Mengembalikan string yang merepresentasikan suara Dolpin.
	  */
	string Interact() {
    return ("A a a a a");
  }
	/** @brief Melakukan cloning untuk menciptakan objek Dolphin baru.
	  * @return Mengembalikan pointer to Dolphin objek tersebut.
	  */
	virtual Dolphin* Clone() const {
    return new Dolphin(*this);
  }
	/** @brief Render dari Dolphin.
	  * @return Mengembalikan char yang merupakan representasi kode Dolphin.
	  */
	char Render() {
    return 'N';
  }
};

#endif