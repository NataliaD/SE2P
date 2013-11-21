/*
 * Thread.cpp
 *
 *  Created on: 02.10.2013
 *      Author: Jannik Schick (2063265)
                Philipp Kloth (2081738)
                Rutkay Kuepelikilinc (2081831)
                Natalia Duske (2063265)
 */

#include <cstdlib>
#include <iostream>
#include <unistd.h> //fuer sleep() und usleep
#include "HWaccess.h"
#include "ioaccess.h"
#include "HALSensorik.h"
#include <string>
#include "MachineState.h"

#include "Thread.h"
#define TEST_TIME 25

using namespace thread;
using namespace hal;
using namespace std;

int main(int argc, char *argv[]) {
 cout << "hey1" << endl;
#ifdef SIMULATION
	cout << "Simulation aktiv" << endl;
	cout << "Zum Aufbau der Verbindung muss Die Festo Simulation schon laufen." << endl;
	IOaccess_open(); // Baue die Verbindung zur Simulation auf
#endif

	// Zugriffsrechte fuer den Zugriff auf die HW holen
	if (-1 == ThreadCtl(_NTO_TCTL_IO, 0)) {
		perror("ThreadCtl access failed\n");
		return -1;
	}

	
	//Neues Objekt der Klasse Thread anlegen
	Thread thread;
MachineState* ma = MachineState::getInstance();
	cout << "hey2" << endl;
	HALSensorik* sens = HALSensorik::getInstance();
	Dispatcher* disp = Dispatcher::getInstance();
	//Thread starten (void execute() wird aufgerufen)
	sens->start(NULL);
	disp->start(NULL);
	thread.start(NULL);

	string quit;
	do{
		cin >> quit;
	}while(quit != "q");

	//Thread beenden (void shutdown() wird aufgerufen)
	sens->stop();
	thread.stop();
	sens->join();
	thread.join();

#ifdef SIMULATION
	IOaccess_close(); // Schliesse die Verbindung zur Simulation
#endif
	return EXIT_SUCCESS;
}
