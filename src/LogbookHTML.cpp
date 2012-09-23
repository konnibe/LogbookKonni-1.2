//#pragma once
#include "LogbookHTML.h"
#include "LogbookDialog.h"
#include "Logbook.h"
#include "logbook_pi.h"
#include "MessageBoxOSX.h"
#include "Options.h"

#ifndef WX_PRECOMP
      #include <wx/wx.h>
#endif

#include <wx/mimetype.h>
#include <wx/textfile.h>
#include <wx/tokenzr.h>
#include <wx/grid.h>
#include <wx/wfstream.h> 
#include <wx/txtstrm.h> 
#include <wx/zipstrm.h> 

#include <memory>
#include <map>
using namespace std;

LogbookHTML::LogbookHTML(Logbook *l, LogbookDialog *d, wxString data, wxString layout)
{
	parent = d;
	logbook = l;
	data_locn = data;
	layout_locn = layout;
}

LogbookHTML::~LogbookHTML(void)
{

}

void LogbookHTML::setPlaceholders()
{
	gridc gridcols = { 0,Logbook::ROUTE};
	placeholders[_T("ROUTE")]=gridcols;
	placeholders[_T("LROUTE")]=gridcols;
	gridc gridcols1 = { 0,Logbook::RDATE};
	placeholders[_T("DATE")]=gridcols1;
	placeholders[_T("LDATE")]=gridcols1;
	gridc gridcols2 = { 0,Logbook::RTIME};
	placeholders[_T("TIME")]=gridcols2;
	placeholders[_T("LTIME")]=gridcols2;
	gridc gridcols3 = { 0,Logbook::SIGN};
	placeholders[_T("SIGN")]=gridcols3;
	placeholders[_T("LSIGN")]=gridcols3;
	gridc gridcols4 = { 0,Logbook::WAKE};
	placeholders[_T("WAKE")]=gridcols4;
	placeholders[_T("LWAKE")]=gridcols4;
	gridc gridcols5 = { 0,Logbook::DISTANCE};
	placeholders[_T("DISTANCE")]=gridcols5;
	placeholders[_T("LDISTANCE")]=gridcols5;
	gridc gridcols6 = { 0,Logbook::DTOTAL};
	placeholders[_T("DTOTAL")]=gridcols6;
	placeholders[_T("LDTOTAL")]=gridcols6;
	gridc gridcols7 = { 0,Logbook::POSITION};
	placeholders[_T("POSITION")]=gridcols7;
	placeholders[_T("LPOSITION")]=gridcols7;
	gridc gridcols8 = { 0,Logbook::COG};
	placeholders[_T("COG")]=gridcols8;
	placeholders[_T("LCOG")]=gridcols8;
	gridc gridcols9 = { 0,Logbook::RTIME};
	placeholders[_T("COW")]=gridcols9;
	placeholders[_T("LCOW")]=gridcols9;
	gridc gridcols10 = { 0,Logbook::COW};
	placeholders[_T("SOG")]=gridcols10;
	placeholders[_T("LSOG")]=gridcols10;
	gridc gridcols11 = { 0,Logbook::SOW};
	placeholders[_T("SOW")]=gridcols11;
	placeholders[_T("LSOW")]=gridcols11;
	gridc gridcols12 = { 0,Logbook::DEPTH};
	placeholders[_T("DEPTH")]=gridcols12;
	placeholders[_T("LDEPTH")]=gridcols12;
	gridc gridcols13 = { 0,Logbook::REMARKS};
	placeholders[_T("REMARKS")]=gridcols13;
	placeholders[_T("LREMARKS")]=gridcols13;
	
	gridc gridcols14 = { 1,Logbook::BARO-logbook->weatherCol};
	placeholders[_T("BARO")]=gridcols14;
	placeholders[_T("LBARO")]=gridcols14;
	gridc gridcols15 = { 1,Logbook::HYDRO-logbook->weatherCol };
	placeholders[_T("HYDRO")]=gridcols15;
	placeholders[_T("LHYDRO")]=gridcols15;
	gridc gridcols16 = { 1,Logbook::TEMPAIR-logbook->weatherCol};
	placeholders[_T("AIRTE")]=gridcols16;
	placeholders[_T("LAIRTE")]=gridcols16;
	gridc gridcols17 = { 1,Logbook::TEMPWATER-logbook->weatherCol};
	placeholders[_T("WTE")]=gridcols17;
	placeholders[_T("LWTE")]=gridcols17;
	gridc gridcols18 = { 1,Logbook::WIND-logbook->weatherCol};
	placeholders[_T("WIND")]=gridcols18;
	placeholders[_T("LWIND")]=gridcols18;
	gridc gridcols19 = { 1,Logbook::WSPD-logbook->weatherCol};
	placeholders[_T("WSPD")]=gridcols19;
	placeholders[_T("LWSPD")]=gridcols19;
	gridc gridcols20 = { 1,Logbook::CURRENT-logbook->weatherCol};
	placeholders[_T("CUR")]=gridcols20;
	placeholders[_T("LCUR")]=gridcols20;
	gridc gridcols21 = { 1,Logbook::CSPD-logbook->weatherCol};
	placeholders[_T("CSPD")]=gridcols21;
	placeholders[_T("LCSPD")]=gridcols21;
	gridc gridcols22 = { 1,Logbook::WAVE-logbook->weatherCol };
	placeholders[_T("WAVE")]=gridcols22;
	placeholders[_T("LWAVE")]=gridcols22;
	gridc gridcols23 = { 1,Logbook::SWELL-logbook->weatherCol };
	placeholders[_T("SWELL")]=gridcols23;
	placeholders[_T("LSWELL")]=gridcols23;
	gridc gridcols24 = { 1,Logbook::WEATHER-logbook->weatherCol };
	placeholders[_T("WEATHER")]=gridcols24;
	placeholders[_T("LWEATHER")]=gridcols24;
	gridc gridcols25 = { 1,Logbook::CLOUDS-logbook->weatherCol };
	placeholders[_T("CLOUDS")]=gridcols25;
	placeholders[_T("LCLOUDS")]=gridcols25;
	gridc gridcols26 = { 1,Logbook::VISIBILITY-logbook->weatherCol };
	placeholders[_T("VISIBILITY")]=gridcols26;
	placeholders[_T("LVISIBILITY")]=gridcols26;

	gridc gridcols27 = { 2,Logbook::MOTOR-logbook->sailsCol};
	placeholders[_T("MOTOR")]=gridcols27;
	placeholders[_T("LMOTOR")]=gridcols27;
	gridc gridcols28 = { 2,Logbook::MOTORT-logbook->sailsCol };
	placeholders[_T("MOTORT")]=gridcols28;
	placeholders[_T("LMOTORT")]=gridcols28;
	gridc gridcols29 = { 2,Logbook::MOTOR1-logbook->sailsCol};
	placeholders[_T("MOTOR1")]=gridcols29;
	placeholders[_T("LMOTOR1")]=gridcols29;
	gridc gridcols30 = { 2,Logbook::MOTOR1T-logbook->sailsCol};
	placeholders[_T("MOTOR1T")]=gridcols30;
	placeholders[_T("LMOTOR1T")]=gridcols30;
	gridc gridcols31 = { 2,Logbook::FUEL-logbook->sailsCol};
	placeholders[_T("FUEL")]=gridcols31;
	placeholders[_T("LFUEL")]=gridcols31;
	gridc gridcols32 = { 2,Logbook::FUELT-logbook->sailsCol};
	placeholders[_T("FUELT")]=gridcols32;
	placeholders[_T("LFUELT")]=gridcols32;
	gridc gridcols33 = { 2,Logbook::GENE-logbook->sailsCol};
	placeholders[_T("GENE")]=gridcols33;
	placeholders[_T("LGENE")]=gridcols33;
	gridc gridcols34 = { 2,Logbook::GENET-logbook->sailsCol};
	placeholders[_T("GENET")]=gridcols34;
	placeholders[_T("LGENET")]=gridcols34;
	gridc gridcols35 = { 2,Logbook::BANK1-logbook->sailsCol };
	placeholders[_T("BANK1")]=gridcols35;
	placeholders[_T("LBANK1")]=gridcols35;
	gridc gridcols36 = { 2,Logbook::BANK1T-logbook->sailsCol };
	placeholders[_T("BANK1T")]=gridcols36;
	placeholders[_T("LBANK1T")]=gridcols36;
	gridc gridcols37 = { 2,Logbook::BANK2-logbook->sailsCol };
	placeholders[_T("BANK2")]=gridcols37;
	placeholders[_T("LBANK2")]=gridcols37;
	gridc gridcols38 = { 2,Logbook::BANK2T-logbook->sailsCol };
	placeholders[_T("BANK2T")]=gridcols38;
	placeholders[_T("LBANK2T")]=gridcols38;
	gridc gridcols39 = { 2,Logbook::SAILS-logbook->sailsCol };
	placeholders[_T("SAILS")]=gridcols39;
	placeholders[_T("LSAILS")]=gridcols39;
	gridc gridcols40 = { 2,Logbook::REEF-logbook->sailsCol };
	placeholders[_T("REEF")]=gridcols40;
	placeholders[_T("LREEF")]=gridcols40;
	gridc gridcols41 = { 2,Logbook::WATERM-logbook->sailsCol };
	placeholders[_T("WATERM")]=gridcols41;
	placeholders[_T("LWATERM")]=gridcols41;
	gridc gridcols42 = { 2,Logbook::WATERMT-logbook->sailsCol };
	placeholders[_T("WATERMT")]=gridcols42;
	placeholders[_T("LWATERMT")]=gridcols42;
	gridc gridcols43 = { 2,Logbook::WATERMO-logbook->sailsCol };
	placeholders[_T("WATERMO")]=gridcols43;
	placeholders[_T("LWATERMO")]=gridcols43;
	gridc gridcols44 = { 2,Logbook::WATER-logbook->sailsCol };
	placeholders[_T("WATER")]=gridcols44;
	placeholders[_T("LWATER")]=gridcols44;
	gridc gridcols45 = { 2,Logbook::WATERT-logbook->sailsCol };
	placeholders[_T("WATERT")]=gridcols45;
	placeholders[_T("LWATERT")]=gridcols45;
	gridc gridcols46 = { 2,Logbook::MREMARKS-logbook->sailsCol };
	placeholders[_T("MREMARKS")]=gridcols46;
	placeholders[_T("LMREMARKS")]=gridcols46;

	placeholdersboat[_T("LLOGBOOK")]     = parent->m_logbook->GetPageText(0);
	placeholdersboat[_T("LFROM")]        = _("from");
	placeholdersboat[_T("LTO")]          = _("to");
	placeholdersboat[_T("SDATE")]        = parent->m_gridGlobal->GetCellValue(0,1);
	placeholdersboat[_T("EDATE")]        = parent->m_gridGlobal->GetCellValue(parent->m_gridGlobal->GetNumberRows()-1,1);
	placeholdersboat[_T("TYPE")]         = parent->boatType->GetValue();
	placeholdersboat[_T("BOATNAME")]     = parent->boatName->GetValue();
	placeholdersboat[_T("HOMEPORT")]     = parent->homeport->GetValue();
	placeholdersboat[_T("CALLSIGN")]     = parent->callsign->GetValue();
	placeholdersboat[_T("REGISTRATION")] = parent->registration->GetValue();
//	placeholdersboat[_T("LOCATION")]     = layout_locn + layout + _T(".html");
}

void LogbookHTML::viewHTML(wxString path, wxString layout, bool mode)
{
	if(layout.Contains(_T("Help")))
	{
		path = layout_locn+layout+_T(".html");
		parent->startBrowser(path);
		return;
	}
	setSelection();

	wxString file = toHTML(path, layout, mode);
	if(file != wxT(""))
		parent->startBrowser(file);
}

void LogbookHTML::setSelection()
{
	int row = parent->selGridRow;
	int z = 0 , r = 1, topRow, bottomRow, first, last;

	first = last = 0;
	
	if(parent->logGrids[0]->GetRows() == 0) return;

	if(parent->logGrids[parent->m_notebook8->GetSelection()]->IsSelection())
	{
		wxGridCellCoordsArray top = 
			parent->logGrids[parent->m_notebook8->GetSelection()]->GetSelectionBlockTopLeft();
		wxGridCellCoordsArray bottom = 
			parent->logGrids[parent->m_notebook8->GetSelection()]->GetSelectionBlockBottomRight();
		if(top.Count() != 0)
		{
			topRow = top[0].GetRow();
			bottomRow = bottom[0].GetRow();
			r = bottomRow-topRow+1;
		}
	}

	z = parent->m_gridGlobal->GetNumberRows();
	if(r == z)
	{
		parent->m_gridGlobal->SelectAll();
		parent->m_gridWeather->SelectAll();
		parent->m_gridMotorSails->SelectAll();
	}
	else
	{
		parent->m_gridGlobal->ClearSelection();	
		parent->m_gridWeather->ClearSelection();	
		parent->m_gridMotorSails->ClearSelection();	
	}

	wxString selRoute = parent->m_gridGlobal->GetCellValue(row,0);
	
	while(row > -1 && parent->m_gridGlobal->GetCellValue(row,0) == selRoute)
		first = row--;
	row = parent->selGridRow;
	while(row < parent->m_gridGlobal->GetNumberRows() && parent->m_gridGlobal->GetCellValue(row,0) == selRoute)
		last = row++;

	for(row = first; row <= last; row++)
	{
		parent->m_gridGlobal->SelectRow(row,true);
		parent->m_gridWeather->SelectRow(row,true);
		parent->m_gridMotorSails->SelectRow(row,true);
	}
}

wxString LogbookHTML::toHTML(wxString path, wxString layout, bool mode)
{
	wxArrayInt arrayRows;
	int count = 0, selCount = 0;
	bool selection = false;
	route = wxEmptyString;

	selCount = parent->m_gridGlobal->GetSelectedRows().Count() ;

	if(selCount > 0)
	{
		selection = true;
		arrayRows = parent->m_gridGlobal->GetSelectedRows();
	}

	if(layout == _T(""))
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,_("Sorry, no Layout installed"),_T("Information"),wxID_OK);
#else
		wxMessageBox(_("Sorry, no Layout installed"),_("Information"),wxOK);
#endif
		return _T("");
	}

	wxString html = readLayoutFile(layout);

	wxString topHTML;
	wxString bottomHTML;
	wxString headerHTML;
	wxString middleHTML;

	wxString seperatorTop = _T("<!--Repeat -->");
	wxString seperatorBottom = _T("<!--Repeat End -->");
	wxString seperatorHeaderTop = _T("<!--Header -->");
	wxString seperatorHeaderBottom = _T("<!--Header end -->");

	int indexTop = html.Find(seperatorTop);
	if(!checkLayoutError(indexTop,seperatorTop,layout)) return _T("");
	indexTop += seperatorTop.Len();
	int indexBottom = html.Find(seperatorBottom);
	if(!checkLayoutError(indexBottom,seperatorBottom,layout)) return _T("");
	indexBottom += seperatorBottom.Len();
	int indexHeaderTop = html.Find(seperatorHeaderTop);
	if(!checkLayoutError(indexHeaderTop,seperatorHeaderTop,layout)) return _T("");
	indexHeaderTop += seperatorHeaderTop.Len();
	int indexHeaderBottom = html.Find(seperatorHeaderBottom);
	if(!checkLayoutError(indexHeaderBottom,seperatorHeaderBottom,layout)) return _T("");
	indexHeaderBottom += seperatorHeaderBottom.Len();

	topHTML = html.substr(0,indexHeaderTop);
	bottomHTML = html.substr(indexBottom,html.Len()-1);
	middleHTML = html.substr(indexTop,indexBottom-indexTop);
	headerHTML = html.substr(indexHeaderTop,indexHeaderBottom-indexHeaderTop);

	wxString filename = this->fileName;

	if(mode == false)
	{
		filename.Replace(wxT("txt"),wxT("html"));
	}
	else
		filename = path;

	if(::wxFileExists(filename))
		::wxRemoveFile(filename);
	
	wxFileOutputStream output( filename );
	wxTextOutputStream htmlFile(output);

	wxString newMiddleHTML;

	topHTML.Replace(wxT("#LLOGBOOK#"),parent->m_logbook->GetPageText(0));
	topHTML.Replace(wxT("#LFROM#"),_("from"));
	topHTML.Replace(wxT("#LTO#"),_("to"));
	topHTML.Replace(wxT("#SDATE#"),parent->m_gridGlobal->GetCellValue(0,1));
	topHTML.Replace(wxT("#EDATE#"),parent->m_gridGlobal->GetCellValue(
		parent->m_gridGlobal->GetNumberRows()-1,1));
	topHTML.Replace(wxT("#TYPE#"),parent->boatType->GetValue());
	topHTML.Replace(wxT("#BOATNAME#"),parent->boatName->GetValue());
	topHTML.Replace(wxT("#HOMEPORT#"),parent->homeport->GetValue());
	topHTML.Replace(wxT("#CALLSIGN#"),parent->callsign->GetValue());
	topHTML.Replace(wxT("#REGISTRATION#"),parent->registration->GetValue());
	topHTML.Replace(wxT("#LOCATION#"),layout_locn + layout + _T(".html"));
	htmlFile << topHTML;

	int rowsMax = parent->m_gridGlobal->GetNumberRows();
	for(int row = 0; row < rowsMax; row++)
	{
		count++;
		if(selection && arrayRows[0]+1 > count) continue;
		if(selection && arrayRows[selCount-1]+1 < count) break;

		newMiddleHTML = middleHTML;
		
		unsigned int first = 0, ofirst = 0;
		for(int grid = 0; grid < 3; grid++)
		{
			wxGrid* g = parent->logGrids[grid];
			for(int col = 0; col < g->GetNumberCols(); col++)
			{
				if(grid == 0 && col == 0)
				{
					replacePlaceholder(newMiddleHTML,headerHTML,grid,row,0,0,htmlFile);
					continue;
				}
				first = newMiddleHTML.find_first_of('#')-1;
				if(first != ofirst)
				{
					htmlFile << newMiddleHTML.SubString(0,first);
					newMiddleHTML.Remove(0,first+1);
					ofirst = first;
				}
				newMiddleHTML = replacePlaceholder(newMiddleHTML,headerHTML,grid,row,col,0,htmlFile);
			}
		}
		htmlFile << newMiddleHTML;
	}
	htmlFile << bottomHTML;

	if(count <= 0)
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,_("Sorry, Logbook has no lines"),_T("Information"),wxID_OK);
#else
		wxMessageBox(_("Sorry, Logbook has no lines"),_("Information"),wxOK);
#endif
		return _T("");
	}

	output.Close();

	return filename;
}
/*
wxString LogbookHTML::toHTML(wxString path, wxString layout, bool mode)
{
	wxArrayInt arrayRows;
	int count = 0, selCount = 0;
	bool selection = false;

	selCount = parent->m_gridGlobal->GetSelectedRows().Count() ;

	if(selCount > 0)
	{
		selection = true;
		arrayRows = parent->m_gridGlobal->GetSelectedRows();
	}

	if(layout == _T(""))
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,_("Sorry, no Layout installed"),_T("Information"),wxID_OK);
#else
		wxMessageBox(_("Sorry, no Layout installed"),_("Information"),wxOK);
#endif
		return _T("");
	}

	wxString html = readLayoutFile(layout);

	wxString seperatorTop = _T("<!--Repeat -->");
	wxString seperatorBottom = _T("<!--Repeat End -->");
	wxString seperatorHeaderTop = _T("<!--Header -->");
	wxString seperatorHeaderBottom = _T("<!--Header end -->");


	wxString filename = this->fileName;

	if(mode == false)
	{
		filename.Replace(wxT("txt"),wxT("html"));
	}
	else
		filename = path;

	if(::wxFileExists(filename))
		::wxRemoveFile(filename);
	
	wxFileOutputStream output( filename );
	wxTextOutputStream d(output);
	unsigned int i = 0;
	wxString str;
	wxString header;
	while(i < html.Length())
	{
		if(html[i] != '#')
		{
			if(html[i] == '<')
			{
				if(html[i+1] == '!')
				{
					while(html[i] != '>')
						header << html[i++];
					header << html[i++];
					if(header.Contains(seperatorTop))
					{
						header = wxEmptyString;
						while(!header.Contains(_T("<!")))
								header << html[i++];
						
						header.Replace(_T("<!"),_T(""));
						while(html[i] != '>')
							i++;
						i++;int kk =0;
						for(int row = 0; row < parent->logGrids[0]->GetNumberRows(); row++)
						{
							unsigned int n = 0;
							while(n < header.Len())
							{
								while(header[n] != '#' && n < header.Len())
									d << header[n++];
							//	wxMessageBox(wxString(header[n])+wxString(header[n+1])+wxString(header[n+2])+wxString(header[n+3]));
								kk++;
								if(n >= header.Len())  break;
								n = setTableValues(mode,n++,row,header,d);
							}
						}
						//d << header;

					//	wxMessageBox(header);
					}
					else
					{
						d << header;
						header = wxEmptyString;
					}
				}
				else
				{
					//i = t;
					d << html[i++];
				}
			}
			else
				d << html[i++];
		}
		else
		{
			i = setTableValues(mode,i,0,html,d);
		}
	}
	output.Close();
	return filename;*/
/*	wxTextOutputStream htmlFile(output);

	wxString newMiddleHTML;


	htmlFile << topHTML;

	int rowsMax = parent->m_gridGlobal->GetNumberRows();
	for(int row = 0; row < rowsMax; row++)
	{
		count++;
		if(selection && arrayRows[0]+1 > count) continue;
		if(selection && arrayRows[selCount-1]+1 < count) break;

		newMiddleHTML = middleHTML;
		for(int grid = 0; grid < 3; grid++)
		{
			wxGrid* g = parent->logGrids[grid];
			for(int col = 0; col < g->GetNumberCols(); col++)
				newMiddleHTML = replacePlaceholder(newMiddleHTML,headerHTML,grid,row,col,0);
		}
		htmlFile << newMiddleHTML;
	}
	htmlFile << bottomHTML;

	if(count <= 0)
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,_("Sorry, Logbook has no lines"),_T("Information"),wxID_OK);
#else
		wxMessageBox(_("Sorry, Logbook has no lines"),_("Information"),wxOK);
#endif
		return _T("");
	}

	output.Close();

	return filename;
	*/
//}
/*
int LogbookHTML::setTableValues(bool mode, int index, int row, wxString html, wxTextOutputStream &d)
{
	wxString str;
	unsigned int i = index;
			int n = 0, t = i;
			i++;
			while(i < html.Len() && (html[i] != '#' && n < 20))
			{
				str << html[i++];
				n++;
			}
			if(n >= 20)
			{
				str = wxEmptyString;
				d << html[t];
			    i = t+1;
				n = 0;
			}
			else
			{
				its = placeholders.find(str);
				if(its == placeholders.end())
				{
					it = placeholdersboat.find(str);
					if(it != placeholdersboat.end())
						str.Replace(str,Export::replaceNewLine(mode,(*it).second,false));
					else if(str == _T("NO."))
						str.Replace(str,wxString::Format(_T("%i"),row));
				}
				else if(its != placeholders.end())
				{
					if(str[0] != 'L')
						str.Replace(str,Export::replaceNewLine(mode,parent->logGrids[(*its).second.grid]->GetCellValue(row,(*its).second.col),false));
					else
						str.Replace(str,Export::replaceNewLine(mode,parent->logGrids[(*its).second.grid]->GetColLabelValue((*its).second.col),true));
				}
				wxString str1(str, wxConvUTF8);
				d << str1;
				str = wxEmptyString;
				i++;
			}
	return i;
}
*/
wxString LogbookHTML::replacePlaceholder(wxString html,wxString htmlHeader,int grid, int row, int col, bool mode, wxTextOutputStream &htmlFile)
{

		wxString s;
		wxGrid* g = parent->logGrids[grid];

//		if(row == 0 && col == 0 && grid == 0)  
//			route = _T(""); 

			switch(grid)
			{
			case 0:
					switch(col)
					{
						case ROUTE:	if(route != Export::replaceNewLine(mode,g->GetCellValue(row,col),false))
									{
										htmlHeader.Replace(wxT("#ROUTE#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false));
										//html.Prepend(htmlHeader);
										htmlHeader.Replace(wxT("#LROUTE#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
										htmlFile << htmlHeader;
									}
										route = Export::replaceNewLine(mode,g->GetCellValue(row,col),false);

								break;
						case RDATE:		html.Replace(wxT("#DATE#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LDATE#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
										html.Replace(wxT("#NO.#"),wxString::Format(_T("%i"),row+1));
								break;
						case RTIME:		html.Replace(wxT("#TIME#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LTIME#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case SIGN:		html.Replace(wxT("#SIGN#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LSIGN#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WAKE:		html.Replace(wxT("#WAKE#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWAKE#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case DISTANCE:	html.Replace(wxT("#DISTANCE#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LDISTANCE#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case DTOTAL:	html.Replace(wxT("#DTOTAL#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LDTOTAL#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case POSITION:	html.Replace(wxT("#POSITION#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LPOSITION#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case COG:		html.Replace(wxT("#COG#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LCOG#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case COW:		html.Replace(wxT("#COW#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LCOW#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case SOG:		html.Replace(wxT("#SOG#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LSOG#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case SOW:		html.Replace(wxT("#SOW#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LSOW#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case DEPTH:		html.Replace(wxT("#DEPTH#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LDEPTH#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case REMARKS:	html.Replace(wxT("#REMARKS#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LREMARKS#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
					}
					break;
			case 1:
					switch(col)
					{
						case BARO:		html.Replace(wxT("#BARO#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LBARO#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case HYDRO:		html.Replace(wxT("#HYDRO#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LHYDRO#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case AIRTE:		html.Replace(wxT("#AIRTE#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LAIRTE#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WATERTE:	html.Replace(wxT("#WTE#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWTE#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WIND:		html.Replace(wxT("#WIND#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWIND#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WSPD:		html.Replace(wxT("#WSPD#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWSPD#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case CURRENT:	html.Replace(wxT("#CUR#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LCUR#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case CSPD:		html.Replace(wxT("#CSPD#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LCSPD#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WAVE:		html.Replace(wxT("#WAVE#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWAVE#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);	
								break;
						case SWELL:		html.Replace(wxT("#SWELL#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LSWELL#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WEATHER:	html.Replace(wxT("#WEATHER#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWEATHER#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case CLOUDS:	html.Replace(wxT("#CLOUDS#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false));
										html.Replace(wxT("#LCLOUDS#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true));
										{
										wxString cl = Export::replaceNewLine(mode,g->GetCellValue(row,col),false).Lower();
										if(cl.IsEmpty())
											cl = _T("nocloud");
										if(cl.Contains(_T(" ")))
											cl = cl.SubString(0,cl.find_first_of(' ')-1);
										if(html.Contains(wxT("#PCLOUDS%23")))
										{
											wxString s = parent->data;
											s.Replace(_T("\\"),_T("/"));
											html.Replace(wxT("Clouds/#PCLOUDS%23"),s+_T("Clouds/")+cl,false);
										}
										else
											html.Replace(wxT("#PCLOUDS#"),cl,false);
										}
								break;
						case VISIBILITY:html.Replace(wxT("#VISIBILITY#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LVISIBILITY#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
					}
					break;
			case 2:
					switch(col)
					{
						case MOTOR:		html.Replace(wxT("#MOTOR#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LMOTOR#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case MOTORT:	html.Replace(wxT("#MOTORT#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LMOTORT#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case MOTOR1:	html.Replace(wxT("#MOTOR1#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LMOTOR1#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case MOTOR1T:	html.Replace(wxT("#MOTOR1T#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LMOTOR1T#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case FUEL:		html.Replace(wxT("#FUEL#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LFUEL#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case FUELT:		html.Replace(wxT("#FUELT#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LFUELT#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case GENE:		html.Replace(wxT("#GENE#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LGENE#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case GENET: 	html.Replace(wxT("#GENET#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LGENET#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case BANK1:		html.Replace(wxT("#BANK1#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LBANK1#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case BANK1T: 	html.Replace(wxT("#BANK1T#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LBANK1T#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case BANK2:		html.Replace(wxT("#BANK2#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LBANK2#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case BANK2T: 	html.Replace(wxT("#BANK2T#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LBANK2T#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case SAILS:		html.Replace(wxT("#SAILS#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LSAILS#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case REEF:		html.Replace(wxT("#REEF#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LREEF#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WATERM:	html.Replace(wxT("#WATERM#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWATERM#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WATERMT:	html.Replace(wxT("#WATERMT#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWATERMT#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WATERMO:	html.Replace(wxT("#WATERMO#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWATERMO#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WATER:		html.Replace(wxT("#WATER#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWATER#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case WATERT:	html.Replace(wxT("#WATERT#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LWATERT#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
						case MREMARKS:	html.Replace(wxT("#MREMARKS#"),Export::replaceNewLine(mode,g->GetCellValue(row,col),false),false);
										html.Replace(wxT("#LMREMARKS#"),Export::replaceNewLine(mode,g->GetColLabelValue(col),true),false);
								break;
					}
					break;
			}

	if(mode == 0)
		return html;
	else 
	{
		wxString str(html, wxConvUTF8);
		return str;
	}
}

bool LogbookHTML::checkLayoutError(int result, wxString html, wxString layout)
{
	if(result == wxNOT_FOUND)
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,html+_("\nnot found in layoutfile ")+layout+_("!\n\nDid you forget to add this line in your layout ?"),_("Information"),wxID_OK);
        return false;
#else
		wxMessageBox(html+_("\nnot found in layoutfile ")+layout+_("!\n\nDid you forget to add this line in your layout ?"),_("Information"));
		return false;
#endif
	}
	return true;
}

void LogbookHTML::setFileName(wxString s, wxString l)
{
	fileName = s;
	layout_locn = l;
}

wxString LogbookHTML::readLayoutFile(wxString layout)
{
	wxString html;

	wxString filename = layout_locn + layout + _T(".html");
	wxTextFile *layoutfile = new wxTextFile(filename);

	if(wxFileExists(filename))
	{
		layoutfile->Open();

		for(unsigned row = 0; row < layoutfile->GetLineCount(); row++)
		{
			html += layoutfile->GetLine(row)+wxT("\n");
		}
	}
	layoutfile->Close();
	return html;
}

wxString LogbookHTML::readLayoutFileODT(wxString layout)
{
	wxString odt = _T("");

	wxString filename = layout_locn + layout + _T(".odt");

	if(wxFileExists(filename))
	{
		static const wxString fn = _T("content.xml");
		wxZipInputStream zip(filename,fn);
		wxTextInputStream txt(zip);
		while(!zip.Eof())
			odt += txt.ReadLine();
	}
	return odt;
}

void LogbookHTML::viewODT(wxString path, wxString layout, bool mode)
{
	setSelection();

	wxString file = toODT(path, layout, mode);
	if(file != wxT(""))
		parent->startApplication(file,_T(".odt"));
}

wxString LogbookHTML::toODT(wxString path,wxString layout, bool mode)
{
	wxArrayInt arrayRows;
	int count = 0, selCount = 0;
	bool selection = false;
	route = wxEmptyString;

	selCount = parent->m_gridGlobal->GetSelectedRows().Count() ;

	if(selCount > 0)
	{
		selection = true;
		arrayRows = parent->m_gridGlobal->GetSelectedRows();
	}

	if(layout == _T(""))
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,_("Sorry, no Layout installed"),_T("Information"),wxID_OK);
#else
		wxMessageBox(_("Sorry, no Layout installed"),_("Information"),wxOK);
#endif
		return _T("");
	}

	wxString odt = readLayoutFileODT(layout);
	if(!odt.Contains(_T("[[")) && !odt.Contains(_T("{{")))
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,_("Have You forgotten to enclose the Header with [[ and ]]\n or Data with {{ and }} ?"),_T("Information"),wxID_OK);
#else
		wxMessageBox(_("Have You forgotten to enclose the Header with [[ and ]]\n or Data with {{ and }} ?"));
#endif
		return _T("");
	}

	wxString topODT;
	wxString bottomODT;
	wxString headerODT;
	wxString middleODT;

	wxString seperatorTop = _T("{{");
	wxString seperatorBottom = _T("}}");
	wxString seperatorHeaderTop = _T("[[");
	wxString seperatorHeaderBottom = _T("]]");
	wxString textbegin = _T("<text:p");
	wxString textend = _T("</text:p");

	odt.Replace(wxT("#LLOGBOOK#"),parent->m_logbook->GetPageText(0));
	odt.Replace(wxT("#LFROM#"),_("from"));
	odt.Replace(wxT("#LTO#"),_("to"));
	odt.Replace(wxT("#SDATE#"),parent->m_gridGlobal->GetCellValue(0,1));
	odt.Replace(wxT("#EDATE#"),parent->m_gridGlobal->GetCellValue(
		parent->m_gridGlobal->GetNumberRows()-1,1));
	odt.Replace(wxT("#TYPE#"),parent->boatType->GetValue());
	odt.Replace(wxT("#BOATNAME#"),parent->boatName->GetValue());
	odt.Replace(wxT("#HOMEPORT#"),parent->homeport->GetValue());
	odt.Replace(wxT("#CALLSIGN#"),parent->callsign->GetValue());
	odt.Replace(wxT("#REGISTRATION#"),parent->registration->GetValue());


	int indexTopODT = odt.Find(seperatorHeaderTop);
	int top = indexTopODT;
	topODT = odt.substr(0,indexTopODT);
	indexTopODT = topODT.find_last_of('<');
	topODT = topODT.substr(0,indexTopODT);
	odt = odt.substr(top);

	int headerStart = odt.find_first_of('>')+1;
	odt = odt.substr(headerStart);

	int indexBottomODT = odt.Find(seperatorHeaderBottom);
	headerODT = odt.substr(0,indexBottomODT);
	odt = odt.substr(indexBottomODT);
	int headerEnd = odt.find_first_of('>')+1;
	odt = odt.substr(headerEnd);
	indexBottomODT = headerODT.find_first_of('<');
	headerODT = headerODT.substr(indexBottomODT);
	headerODT = headerODT.substr(0,headerODT.find_last_of('<'));

	indexBottomODT = odt.Find(seperatorTop);
	middleODT = odt.substr(indexBottomODT);
	odt = odt.substr(indexBottomODT);

	int middleStart = middleODT.find_first_of('>')+1;
	middleODT = middleODT.substr(middleStart);
	odt = odt.substr(odt.find_first_of('>')+1);

	indexBottomODT = odt.Find(seperatorBottom);
	middleODT = odt.substr(0,indexBottomODT);
	odt = odt.substr(indexBottomODT);

	int middleEnd = odt.find_first_of('>')+1;
	odt = odt.substr(middleEnd);
	middleODT = middleODT.substr(0,middleODT.find_last_of('<'));

	wxString filename = this->fileName;

	if(mode == false)
	{
		filename.Replace(wxT("txt"),wxT("odt"));
	}
	else
		filename = path;

	if(::wxFileExists(filename))
		::wxRemoveFile(filename);
	
    auto_ptr<wxFFileInputStream> in(new wxFFileInputStream(layout_locn + layout + _T(".odt")));
    wxTempFileOutputStream out(filename);

    wxZipInputStream inzip(*in);
    wxZipOutputStream outzip(out);
	wxTextOutputStream odtFile(outzip);
    auto_ptr<wxZipEntry> entry;

    outzip.CopyArchiveMetaData(inzip);

    while (entry.reset(inzip.GetNextEntry()), entry.get() != NULL)
        if (!entry->GetName().Matches(_T("content.xml")))
            if (!outzip.CopyEntry(entry.release(), inzip))
                break;

    in.reset();

	outzip.PutNextEntry(_T("content.xml"));

	odtFile << topODT;

	wxString newMiddleODT;
	int rowsMax = parent->m_gridGlobal->GetNumberRows();
	for(int row = 0; row < rowsMax; row++)
	{
		count++;
		if(selection && arrayRows[0]+1 > count) continue;
		if(selection && arrayRows[selCount-1]+1 < count) break;

		newMiddleODT = middleODT;
		for(int grid = 0; grid < 3; grid++)
		{
			wxGrid* g = parent->logGrids[grid];
			for(int col = 0; col < g->GetNumberCols(); col++)
				newMiddleODT = replacePlaceholder(newMiddleODT,headerODT,grid,row,col,1,odtFile);
		}
		odtFile << newMiddleODT;
	}

	odtFile << odt;

    inzip.Eof() && outzip.Close() && out.Commit();
	return filename;
	
}

void LogbookHTML::toCSV(wxString path)
{
	wxString line;
	wxString s, temp;

	logbook->update();

	wxFileInputStream input( this->fileName );
	wxTextInputStream* stream = new wxTextInputStream (input);

	if(input.GetSize() == 0)
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,_("Sorry, Your Logbook has no lines"),_T("Information"),wxID_OK);
#else
		wxMessageBox(_("Sorry, Your Logbook has no lines"),_("Information"),wxOK);
#endif
		return;
	}

	if(::wxFileExists(path))
		::wxRemoveFile(path);
	
	wxFileOutputStream output( path );
	wxTextOutputStream csvFile(output);

	for(int n = 0; n < parent->numPages; n++)
	{
		for(int i = 0; i < parent->logGrids[n]->GetNumberCols(); i++)
			csvFile << parent->logGrids[n]->GetColLabelValue(i)+_T(",");
	}
	csvFile << _T("\n");

	stream->ReadLine(); // for #1.2#
	while(wxString line = stream->ReadLine())
	{
		if(input.Eof()) break;

		wxStringTokenizer tkz(line, _T("\t"));

		int col = 0;
		while ( tkz.HasMoreTokens() )
		{ 
			temp = tkz.GetNextToken();
			temp.RemoveLast();
			if(col == Logbook::RDATE)
			{   
				temp += _T("/")+tkz.GetNextToken().RemoveLast();
				temp += _T("/")+tkz.GetNextToken().RemoveLast();
				temp = Logbook::makeDateFromFile(temp,parent->logbookPlugIn->opt->sdateformat);
			}

			if(col == Logbook::RTIME)
			{
				int hour = wxAtoi(temp);
				int min  = wxAtoi(tkz.GetNextToken());
				int sec  = wxAtoi(tkz.GetNextToken());
				wxDateTime dt;
				dt.Set(hour,min,sec);
				temp = dt.Format(parent->logbookPlugIn->opt->stimeformat);
			}

			temp.Replace(_T("\""),_T("\"\""));
			temp.Replace(_T("\\n"),_T("\n"));
			temp.Prepend(_T("\""));
			temp.Append(_T("\","));
			s += temp;
			col++;
		}
		s.RemoveLast();
		csvFile << s+_T("\n");
		s = _T("");
	}
	output.Close();
}

void LogbookHTML::toXML(wxString path)
{
	wxString s = _T("");
	wxString line;
	wxString temp;
	int count = 0;

	logbook->update();

	wxFileInputStream input( this->fileName );
	wxTextInputStream* stream = new wxTextInputStream (input);
	if(input.GetSize() == 0)
	{
#ifdef __WXOSX__
        MessageBoxOSX(NULL,_("Sorry, Your Logbook has no lines"),_T("Information"),wxID_OK);
#else
		wxMessageBox(_("Sorry, Your Logbook has no lines"),_("Information"),wxOK);
#endif
		return;
	}

	wxFileOutputStream output( path );
	wxTextOutputStream xmlFile(output);

	if(::wxFileExists(path))
		::wxRemoveFile(path);

	xmlFile << parent->xmlHead;

	s = wxString::Format(_T("<Row>"));
	for(int n = 0; n < parent->numPages; n++)
	{
		for(int i = 0; i < parent->logGrids[n]->GetNumberCols(); i++)
		{
			s += _T("<Cell>\n");
			s += _T("<Data ss:Type=\"String\">#DATA#</Data>\n");
			s.Replace(_T("#DATA#"),parent->logGrids[n]->GetColLabelValue(i));
			s += _T("</Cell>");
		}
	}
	s += _T("</Row>>");
	xmlFile << s;

	stream->ReadLine(); // for #1.2#
	while(wxString line = stream->ReadLine())
	{
		if(input.Eof()) break;
		wxStringTokenizer tkz(line, _T("\t"));
		s = wxString::Format(_T("<Row ss:Height=\"%u\">"),parent->m_gridGlobal->GetRowHeight(count++));

		int col = 0;
		while ( tkz.HasMoreTokens() )
		{ 
			s += _T("<Cell>\n");
			s += _T("<Data ss:Type=\"String\">#DATA#</Data>\n");
			temp = tkz.GetNextToken();

			if(col == Logbook::RDATE)
			{   
				temp = temp.RemoveLast();
				temp += _T("/")+tkz.GetNextToken().RemoveLast();
				temp += _T("/")+tkz.GetNextToken().RemoveLast();
				temp = Logbook::makeDateFromFile(temp,parent->logbookPlugIn->opt->sdateformat);
			}

			if(col == Logbook::RTIME)
			{
				int hour = wxAtoi(temp);
				int min  = wxAtoi(tkz.GetNextToken());
				int sec  = wxAtoi(tkz.GetNextToken());
				wxDateTime dt;
				dt.Set(hour,min,sec);
				temp = dt.Format(parent->logbookPlugIn->opt->stimeformat);
			}

			temp.Replace(_T("&"),_T("&amp;"));
			temp.Replace(_T("\\n"),_T("&#xA;"));
			temp.Replace(_T("\""),_T("&quot;"));
			temp.Replace(_T("<"),_T("&lt;"));
			temp.Replace(_T(">"),_T("&gt;"));
			temp.Replace(_T("'"),_T("&apos;"));
			s.Replace(_T("#DATA#"),temp);
			s += _T("</Cell>");
			col++;
		}
		s += _T("</Row>>");
		xmlFile << s;
	}

	xmlFile << parent->xmlEnd;
	output.Close();

}


void LogbookHTML::toODS(wxString path)
{
	wxString s = _T("");
	wxString line;
	wxString temp;

	wxFileInputStream input( this->fileName );
	wxTextInputStream* stream = new wxTextInputStream (input);

	logbook->update();

	wxFFileOutputStream out(path);
	wxZipOutputStream zip(out);
	wxTextOutputStream txt(zip);
	wxString sep(wxFileName::GetPathSeparator());

	zip.PutNextEntry(wxT("content.xml"));
	txt << parent->content;

	long emptyCol = 0;

	txt << _T("<table:table-row table:style-name=\"ro2\">");

	for(int n = 0; n < parent->numPages; n++)
	{
		for(int i = 0; i < parent->logGrids[n]->GetNumberCols(); i++)
		{
			txt << _T("<table:table-cell office:value-type=\"string\">");
			txt << _T("<text:p>");
			txt << parent->logGrids[n]->GetColLabelValue(i);
			txt << _T("</text:p>");
			txt << _T("</table:table-cell>");
		}
	}
	txt << _T("</table:table-row>");

	while(wxString line = stream->ReadLine())
	{
		if(input.Eof()) break;
		txt << _T("<table:table-row table:style-name=\"ro2\">");
		wxStringTokenizer tkz(line, _T("\t"));

		while ( tkz.HasMoreTokens() )
		{ 
			wxString s = parent->restoreDangerChar(tkz.GetNextToken());
			s.RemoveLast();

			if(s == _T(""))
			{
				txt <<  _T("<table:table-cell />");
				emptyCol++;
				continue;
			}

			txt << _T("<table:table-cell office:value-type=\"string\">");

			wxStringTokenizer str(s, _T("\t"));
			while(str.HasMoreTokens())
			{
				wxString e = str.GetNextToken();
				e.Replace(_T("&"),_T("&amp;"));
				e.Replace(_T("\""),_T("&quot;"));
				e.Replace(_T("<"),_T("&lt;"));
				e.Replace(_T(">"),_T("&gt;"));
				e.Replace(_T("'"),_T("&apos;"));
				txt << _T("<text:p>");
				txt << e;
				txt << _T("</text:p>");
			}
			txt << _T("</table:table-cell>");
		}
		txt << _T("</table:table-row>");

	}
	txt << parent->contentEnd;

	zip.PutNextEntry(wxT("mimetype"));
	txt << wxT("application/vnd.oasis.opendocument.spreadsheet");

	zip.PutNextEntry(wxT("styles.xml"));
	txt << parent->styles;

	zip.PutNextEntry(wxT("meta.xml"));
	txt << parent->meta;

	zip.PutNextEntry(wxT("META-INF") + sep + wxT("manifest.xml"));
	txt << parent->manifest;

	zip.PutNextEntry(wxT("Thumbnails") + sep);

	zip.PutNextEntry(wxT("Configurations2") + sep + wxT("floater"));
	zip.PutNextEntry(wxT("Configurations2") + sep + wxT("menubar"));
	zip.PutNextEntry(wxT("Configurations2") + sep + wxT("popupmenu"));
	zip.PutNextEntry(wxT("Configurations2") + sep + wxT("progressbar"));
	zip.PutNextEntry(wxT("Configurations2") + sep + wxT("statusbar"));
	zip.PutNextEntry(wxT("Configurations2") + sep + wxT("toolbar"));
	zip.PutNextEntry(wxT("Configurations2") + sep + wxT("images") + sep + wxT("Bitmaps"));


	zip.Close();
	out.Close();
}

void LogbookHTML::backup(wxString path)
{
	wxCopyFile(data_locn+parent->backupFile,path);
}
