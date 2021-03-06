/*
 * Adresses.h
 *
 *  Created on: 02.10.2013
 *      Author: Jannik Schick (2063265)
 *              Philipp Kloth (2081738)
 *              Rutkay Kuepelikilinc (2081831)
 *              Natalia Duske (2063265)
 */

#ifndef ADDRESSES_H_
#define ADDRESSES_H_

#define DIO_BASE 0x300          // Base address
#define DIO_OFFS_A 0x00         // Port A offset
#define DIO_OFFS_B 0x01         // Port B offset
#define DIO_OFFS_C 0x02         // Port C offset
#define DIO_OFFS_CTRL 0x03      // Control register offset
// BIT_X is set to one
#define BIT_0 0x01
#define BIT_1 0x02
#define BIT_2 0x04
#define BIT_3 0x08
#define BIT_4 0x10
#define BIT_5 0x20
#define BIT_6 0x40
#define BIT_7 0x80

#define ON true
#define OFF false

#endif /* ADDRESSES_H_ */
