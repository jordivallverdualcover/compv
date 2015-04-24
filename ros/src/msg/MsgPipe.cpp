/*
 * MsgPipe.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: danke
 */

#include "MsgPipe.h"

MsgPipe::MsgPipe() {
}

MsgPipe::~MsgPipe() {
}

void MsgPipe::bind(SerialPort *port) {
	mPort = port;
}

Message* MsgPipe::readMessage() {
	// Read a line
	string msgLine = mPort->ReadLine(0 /* no timeout */, EOL);

	string msgType = Message::getMsgType(msgLine);

	if (!msgType.compare("D")) {
		return DataEncoders::parse(msgLine);
	} else {
		// TODO ERROR
	}

	return 0;
}
