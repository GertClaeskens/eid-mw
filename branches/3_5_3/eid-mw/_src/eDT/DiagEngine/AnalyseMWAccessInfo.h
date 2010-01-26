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
#ifndef _ANALYSEMWACCESSINFO_H_
#define _ANALYSEMWACCESSINFO_H_

#include <exception>
#include <sstream>

#include "analysis.h"
#include "middleware.h"
#include "AnalysisError.h"


//******************************************
// Middleware access verification
// 
// Pass:
//
// Fail:
//
//******************************************
class AnalyseMWAccessInfo : public Analysis
{
public:
	AnalyseMWAccessInfo()
	{
		m_testName = "middleware_access";
		m_friendlyName = "Middleware card access";
	}
	virtual ~AnalyseMWAccessInfo()
	{
	}

	virtual int run()
	{
		m_bPassed = false;
		setProgress(0);
		setStartTime();
		int retVal = DIAGLIB_OK;
		Report_TYPE reportType = REPORT_TYPE_RESULT;

		try
		{
			wchar_t		sepa		= L'~';
			reportPrintHeader2(reportType, L"Middleware card access", sepa);

			//------------------------------------------
			// Load the installed MW and read the card(s)
			// If the MW fails then stop
			//------------------------------------------
			Card_LIST cardList;
			retVal = getMWCardList(reportType, &cardList);

			if (DIAGLIB_OK!=retVal)
			{
				processParamsToStop();
				resultToReport(reportType,m_bPassed);
				return retVal;
			}

			{
				std::wstringstream text;
				text << L"[Info ] Nr cards inserted in cardreaders: " << cardList.size();
				resultToReport(reportType,text);
			}

			//------------------------------------------
			// card list can be generated, check if a card is inserted (size>0)
			//------------------------------------------
			if (0==cardList.size())
			{
				//------------------------------------------
				// get the list of readers we found using the middleware
				//------------------------------------------
				Reader_LIST readerList;
				retVal = mwGetReaderList(&readerList);
				if (DIAGLIB_OK!=retVal)
				{
					switch(retVal)
					{
					case DIAGLIB_ERR_BAD_CALL:
						std::wstring(L"[Error] Bad function call to mwGetReaderList()");
						break;
					case DIAGLIB_ERR_LIBRARY_NOT_FOUND:
						std::wstring(L"[Error] Could not load Middleware");
						break;
					case DIAGLIB_ERR_INTERNAL:
						std::wstring(L"[Error] Internal error calling mwGetReaderList()");
					    break;
					default:
						std::wstring(L"[Error] Unknown error: mwGetReaderList()");
					    break;
					}
				}
				else
				{
					std::wstringstream text;
					text << L"[Info] Nr of card readers detected by Middleware: " << readerList.size();
					resultToReport(reportType,text);
					for (size_t idx=0;idx<readerList.size();idx++)
					{
						Reader_INFO info;
						retVal = readerGetInfo(readerList.at(idx), &info);
						retVal = readerReportInfo(reportType, info);
					}
				}
				processParamsToStop();
				resultToReport(reportType,m_bPassed);
				return retVal;
			}

			//------------------------------------------
			// Loop over all the card readers that have a card inserted
			//------------------------------------------
			for (size_t cardIdx=0; cardIdx<cardList.size(); cardIdx++)
			{
				std::wstringstream text;
				text.str(L"");
				Card_INFO info;
				retVal = cardGetInfo(cardList.at(cardIdx), &info);
				switch(retVal)
				{
				case DIAGLIB_ERR_INTERNAL:
				//------------------------------------------------
				// Card_INFO* == NULL
				//------------------------------------------------
				case DIAGLIB_ERR_BAD_CALL:
				//------------------------------------------------
				// cardinfo can not be read from this list (== software error)
				//------------------------------------------------
				case DIAGLIB_ERR_NOT_AVAILABLE:
					text << L"[Error] Internal error retrieving info from card";
					break;
				//------------------------------------------------
				// user clicked 'NO" when asking to grant access to cards
				//------------------------------------------------
				case DIAGLIB_ERR_NOT_ALLOWED_BY_USER:
					text << L"[Warn ] Access to cards refused by user";
					break;
				//------------------------------------------------
				// eidlib could not be loaded
				//------------------------------------------------
				case DIAGLIB_ERR_LIBRARY_NOT_FOUND:
					text << L"[Error] Middleware library could not be loaded.";
					resultToReport(reportType,text);
					processParamsToStop();
					return retVal;
					break;
				//------------------------------------------------
				// no card in reader
				//------------------------------------------------
				case DIAGLIB_ERR_CARD_NOT_FOUND:
					text << L"[Error] Card could not be found.";
					break;
				//------------------------------------------------
				// card type not recognized
				//------------------------------------------------
				case DIAGLIB_ERR_CARD_BAD_TYPE:
					text << L"[Warn ] Card not recognized.";
					break;
				//------------------------------------------------
				// internal error
				//------------------------------------------------
				default:	// DIAGLIB_OK
					break;
				}
				resultToReport(reportType,text);
				retVal = cardReportInfo(reportType, info);
				if (retVal != DIAGLIB_OK)
				{
					setEndTime();
					resultToReport(reportType,m_bPassed);
					return retVal;
				}
			}
			
			//------------------------------------------
			// it seems to be working ok, return
			//------------------------------------------
			m_bPassed = true;
			processParamsToStop();
			resultToReport(reportType,m_bPassed);
			return retVal;
		}
		//------------------------------------------
		// exception from writing to the report
		//------------------------------------------
		catch (ExcReport& exc) 
		{
			processParamsToStop();
			retVal = exc.getErr();
		}
		resultToReport(reportType,m_bPassed);
		return retVal;
	}
private:
	int getMWCardList(Report_TYPE reportType, Card_LIST* cardList)
	{
		resultToReport(reportType,L"[Info ] Generating card list using installed Middleware");

		int retVal =  cardGetListFromMW(cardList);
		std::wstringstream text;

		if (retVal != DIAGLIB_OK)
		{
			text << L"[Error] Card list could not be retrieved: ";
			switch(retVal)
			{
			case DIAGLIB_ERR_BAD_CALL:
				text << L"Bad function call ";
				break;
			case DIAGLIB_ERR_LIBRARY_NOT_FOUND:
				text << L"Library not found ";
				break;
			case DIAGLIB_ERR_INTERNAL:
				text << L"Internal error ";
				break;
			default:
				text << L"Unknown error ";
				break;
			}
		}
		resultToReport(reportType,text);
		return retVal;
	}

};

#endif
