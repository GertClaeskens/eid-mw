/* ****************************************************************************

 * eID Middleware Project.
 * Copyright (C) 2008-2009 FedICT.
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
#include <stdlib.h>
#include <string.h>

#include "FileUtil.h"
#include "PrintBasic.h"
#include "PrintStruct.h"

#include "TestRead.h"
#include "TestCert.h"
#include "TestPin.h"
#include "TestOther.h"

#include "TestBasic.h"
#include "TestRawFile.h"

static BEID_Bytes rawFile = {0};

void PrintTestRawFile1(FILE *f, int Ocsp, int Crl)
{
    BEID_Status tStatus = {0};
	
	rawFile.length		 = 10;
	rawFile.data		 = (BYTE *)malloc(sizeof(BYTE) * rawFile.length);
	memset(rawFile.data,0,rawFile.length);

	//BEID_GetRawFile
	PrintTestFunction(f,"BEID_GetRawFile");
	tStatus = BEID_GetRawFile(&rawFile);
	PrintStatus(f,"BEID_GetRawFile",&tStatus);
	if(BEID_E_INSUFFICIENT_BUFFER == tStatus.general)
	{
		PrintComment(f,"RAW FILE COULD NOT BE COMPARED BECAUSE OF CHALLENGE/RESPONSE AND FORMAT");
		//PrintBytes(f,"RAW FILE",&rawFile);

		free(rawFile.data);

		rawFile.length		 = BEID_MAX_RAW_ADDRESS_LEN 
								+BEID_MAX_RAW_ID_LEN
								+BEID_MAX_PICTURE_LEN
								+BEID_MAX_CERT_LEN
								+BEID_MAX_SIGNATURE_LEN*3
								+BEID_MAX_CARD_DATA_SIG_LEN
								+BEID_MAX_CHALLENGE_LEN
								+BEID_MAX_RESPONSE_LEN
								+1000;
		rawFile.data		 = (BYTE *)malloc(sizeof(BYTE) * rawFile.length);
		memset(rawFile.data,0,rawFile.length);

		tStatus = BEID_GetRawFile(&rawFile);
		PrintStatus(f,"BEID_GetRawFile",&tStatus);
	}

	if(BEID_OK != tStatus.general)
	{
		PrintWARNING(f,"Get Raw File failed");
	}

	PrintComment(f,"RAW FILE COULD NOT BE COMPARED BECAUSE OF CHALLENGE/RESPONSE AND FORMAT");
	//PrintBytes(f,"RAW FILE",&rawFile);
}

void PrintTestRawFile2(FILE *f, int Ocsp, int Crl)
{
    BEID_Status tStatus = {0};

	PrintHeader(f,"VIRTUAL WITH RAW FILE");
	//BEID_SetRawFile
	PrintTestFunction(f,"BEID_SetRawFile");
	tStatus = BEID_SetRawFile(&rawFile);
	PrintStatus(f,"BEID_SetRawFile",&tStatus);
	if(BEID_OK != tStatus.general)
	{
		PrintWARNING(f,"Set Raw File failed");
	}

	PrintTestRead(f, Ocsp, Crl);
	PrintTestCert(f, Ocsp, Crl);
	PrintTestPin(f, Ocsp, Crl);
	PrintTestOther(f, Ocsp, Crl);

	free(rawFile.data);
}

int test_RawFile(const char *folder, const char *reader, int bVerify, int Ocsp, int Crl)
{
	return test_Basic("rawfile", &PrintTestRawFile1, &PrintTestRawFile2, folder, reader, bVerify, Ocsp, Crl);	
}
