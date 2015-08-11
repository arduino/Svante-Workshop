#include "SVremote.h"
#include "SVremoteTools.h"
#include <Arduino.h>

SVrecv svrecv=SVrecv();
decode_results results; // container for received IR codes

void beginSVremote(int recvpin){
	svrecv.setRecvPin(recvpin);
	svrecv.enableIRIn(); // Start the receiver
}

bool SVreceived(){
	return svrecv.decode(&results);
}

void resumeSVremote(){
    svrecv.resume(); // resume receiver
}

unsigned long getSVresult(){
	return results.value;
}

