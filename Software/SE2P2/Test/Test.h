/*
 * Test.h
 *
 *  Created on: 17.10.2013
 *      Author: Rutkay
 */

#ifndef TEST_H_
#define TEST_H_

#include "HAL.h"
#include "Serial.h"

class Test {
public:
	Test();
	virtual ~Test();


	virtual void componentTest(HAL* hal);
	virtual void serialTest(Serial* serial);
};

#endif /* TEST_H_ */
