#include "sensors.h"

void sensors::setVector(int number, vector<int> data){
	switch (number)
	{
	case 1:
		sensor1 = data;
		break;
	case 2:
		sensor2 = data;
		break;
	case 3:
		sensor3 = data;
		break;
	case 4:
		sensor4 = data;
		break;
	case 5:
		sensor5 = data;
		break;
	case 6:
		sensor6 = data;
		break;
	case 7:
		sensor7 = data;
		break;
	case 8:
		sensor8 = data;
		break;
	default:
		cout << "El valor introducido es incorrecto" << endl;
		break;
	}
}

void sensors::append(int sensor, int dato) {
	switch (sensor)
	{
	case 1:
		sensor1.push_back(dato);
		break;
	case 2:
		sensor2.push_back(dato);
		break;
	case 3:
		sensor3.push_back(dato);
		break;
	case 4:
		sensor4.push_back(dato);
		break;
	case 5:
		sensor5.push_back(dato);
		break;
	case 6:
		sensor6.push_back(dato);
		break;
	case 7:
		sensor7.push_back(dato);
		break;
	case 8:
		sensor8.push_back(dato);
		break;
	}
}

void sensors::clearVector() {
	sensor1.clear();
	sensor2.clear();
	sensor3.clear();
	sensor4.clear();
	sensor5.clear();
	sensor6.clear();
	sensor7.clear();
	sensor8.clear();
}

void sensors::printVector(int sensor) {
	switch (sensor)
	{
	case 1:
		for (int val = 0; val < sensor1.size(); val++) {
			cout << sensor1[val] << ',';
		}
		break;
	case 2:
		for (int val = 0; val < sensor2.size(); val++) {
			cout << sensor2[val] << ',';
		}
		break;
	case 3:
		for (int val = 0; val < sensor3.size(); val++) {
			cout << sensor3[val] << ',';
		}
		break;
	case 4:
		for (int val = 0; val < sensor4.size(); val++) {
			cout << sensor4[val] << ',';
		}
		break;
	case 5:
		for (int val = 0; val < sensor5.size(); val++) {
			cout << sensor5[val] << ',';
		}
		break;
	case 6:
		for (int val = 0; val < sensor6.size(); val++) {
			cout << sensor6[val] << ',';
		}
		break;
	case 7:
		for (int val = 0; val < sensor7.size(); val++) {
			cout << sensor7[val] << ',';
		}
		break;
	case 8:
		for (int val = 0; val < sensor8.size(); val++) {
			cout << sensor8[val] << ',';
		}
		break;
	}
	
}

vector<int> sensors::getVector(int sensor) {
	switch (sensor)
	{
	case 1:
		return sensor1;
	case 2:
		return sensor2;
	case 3:
		return sensor3;
	case 4:
		return sensor4;
	case 5:
		return sensor5;
	case 6:
		return sensor6;
	case 7:
		return sensor7;
	case 8:
		return sensor8;
	}
}

void sensors::setClass(string cad) {
	clase = cad;
}

string sensors::getClass() {
	return clase;
}