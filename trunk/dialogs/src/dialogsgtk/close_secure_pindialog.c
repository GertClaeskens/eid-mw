/* ****************************************************************************
 * eID Middleware Project.
 * Copyright (C) 2008-2010 FedICT.
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version
 * 3.0 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, see
 * http://www.gnu.org/licenses/.
**************************************************************************** */

#include "single_dialog.h"

#define BEID_SECURE_PIN_DIALOG	"beid-secure-askpin"

int main(int argc, char* argv[])
{
	SingleDialog sdialog;								// the single_dialog meta-info

	sdialog_init(&sdialog,BEID_SECURE_PIN_DIALOG);		// set up for single dialog
	sdialog_terminate_active(&sdialog);					// remove any active dialog

	exit(0);
}
