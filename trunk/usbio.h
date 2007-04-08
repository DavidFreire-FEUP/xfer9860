/***************************************************************************
 *   Copyright (C) 2007							   *
 *		Andreas Bertheussen <andreasmarcel@gmail.com>		   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef USBIO_H
#define USBIO_H

#include <usb.h>

#define USB_WRITE_TIMEOUT 300
#define USB_READ_TIMEOUT 1000

int ReadUSB(struct usb_dev_handle *usb_handle, char* buffer, int length);
int WriteUSB(struct usb_dev_handle *usb_handle, char* buffer, int length);

#endif