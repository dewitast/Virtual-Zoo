/**	@file	Driver.h
  */

#ifndef DRIVER_H
#define DRIVER_H

#include "Zoo.h"

/** @class Driver.
  * Kelas Driver merupakan kelas sebagai pilihan menu aplikasi.
  */
class Driver {
	public :
		/** @brief Constructor.
		  * Menciptakan Cage kosong tanpa animal.
		  */
		Driver();

		/** @brief DisplayZoo.
		  * Menampilkan zoo ke layar.
		  */
		void DisplayZoo();

		/** @brief GetExperience.
		  * Mencetak ke layar eksperimen yang didapat pengunjung.
		  */
		void GetExperience();


		/** @brief TourZoo.
		  * Melakukan tur zoo.
		  */
		void TourZoo();

		/** @brief FoodCalc.
		  * Melakukan perhitungan makanan yang harus disiapkan.
		  * @return Mengembalikan jumlah makanan yang harus disiapkan.
		  */
		float FoodCalc();

		/** @brief Destructor.
	 	 */
		virtual ~Driver() {}
		
	private :
		Zoo Z;
		bool **visited; //matrix untuk menyatakan cell apa yang sudah dikunjungi.
		Point P; // current cell
};

#endif