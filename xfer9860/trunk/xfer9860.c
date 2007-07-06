/*******************************************************************************
	xfer9860 - a Casio fx-9860G (SD) communication utility
	Copyright (C) 2007
		Andreas Bertheussen <andreasmarcel@gmail.com>

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
	MA  02110-1301, USA.
*******************************************************************************/

#include <stdio.h>
#include <unistd.h>

#include "uploadfile.h"
#include "getinfo.h"

const char* _version_ = "SVN";

void displayHelp();
void displayAbout();

int main(int argc, char *argv[]) {
	int opt;

	/* parameters */
	char *sourceFileName;
	int throttleSetting = 0;

	/* operations */
	int uploadFileFlag = 0;
	int getInfoFlag = 0;

	printf("--- xfer9860 %s  Copyright (C) 2007 Andreas Bertheussen and Manuel Naranjo.\n", _version_);

	while ((opt = getopt(argc, argv, "t:u:iha")) != -1) {
		switch(opt) {
			case 't':
				throttleSetting = atoi(optarg);
				break;
			case 'h': break;
			case 'u':
				sourceFileName = optarg;
				uploadFileFlag = 1;
				break;
			case 'i':
				getInfo(throttleSetting);
				return 0;
			case 'a':
				displayAbout();
				return 0;
			default:
				return 0;
		}
	}

	if (uploadFileFlag) {
		if (optind >= argc)
			printf("You must specify a destination file name.\n");
		else
			uploadFile(sourceFileName, argv[optind], throttleSetting);
		return 0;
	}

	displayHelp();
	return 0;
}

void displayHelp() {
	printf(	"--- a Casio fx-9860G (SD) communication utility.\n"
		"Usage: xfer9860 <action> destname [-t throttle]\n"
		"Calculator actions:\n"
		" -u srcname\tUpload file `srcname' from PC to `destname' on device.\n"
		//" -d srcname\tDownload file `srcname' from device to `destname' on PC.\n" // NOT IMPLEMENTED YET
		" -i\t\tShows information about the connected calculator.\n"
		"\nParameters:\n"
		" -t value\tThrottle setting. The value specifies the delay in ms between\n"
	      	"\t\tpackets. Default is 0. Try increasing this in case of problems.\n"
		"\nOther:\n"
		" -h\t\tDisplay this help message.\n"
	      	" -a\t\tDisplay info about xfer9860 and its licensing.\n");
	printf("\n");
}

void displayAbout() {
	printf(	"--- a Casio fx-9860G (SD) communication utility.\n"
		"This program is free software; you can redistribute it and/or\n"
		"modify it under the terms of the GNU General Public License\n"
		"as published by the Free Software Foundation; either version 2\n"
		"of the License, or (at your option) any later version.\n\n"
		"This program is distributed in the hope that it will be useful,\n"
		"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
		"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
		"GNU General Public License for more details.\n\n"
		"You should have received a copy of the GNU General Public License\n"
		"along with this program. If not, see <http://www.gnu.org/licenses/>.\n");
}
