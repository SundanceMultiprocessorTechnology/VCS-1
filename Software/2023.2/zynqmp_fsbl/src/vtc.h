
#ifndef VTC_H_
#define VTC_H_

#include "xvtc.h"

extern XVtc Vtc;		/**< Instance of the VTC Device */
int vtc_init(short DeviceID);
void XVtc_dump();

#endif /* VTC_H_ */
