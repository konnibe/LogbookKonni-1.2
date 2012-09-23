#pragma once
#include <wx/string.h>
#include <wx/filename.h>

class LogbookDialog;
class Logbook;
#include <map>
using namespace std;
class LogbookHTML
{
public:
	LogbookHTML(Logbook* l, LogbookDialog* d, wxString data, wxString layout);
	~LogbookHTML(void);

	void viewHTML(wxString path,wxString layout, bool mode);
	void viewODT(wxString path, wxString layout, bool mode);
	wxString toHTML(wxString path,wxString layout, bool mode);
	wxString toODT(wxString path,wxString layout, bool mode);
	void toCSV(wxString path);
	void toXML(wxString path);
	void toODS(wxString path);
	void backup(wxString path);
	void setFileName(wxString s, wxString l);
	void setPlaceholders();

private:
	enum fieldsGlobal{ ROUTE,RDATE,RTIME,SIGN,WAKE,DISTANCE,DTOTAL,POSITION,COG,COW,SOG,SOW,DEPTH,REMARKS};
	enum fieldsWeather{ BARO,HYDRO, AIRTE,WATERTE,WIND,WSPD,CURRENT,CSPD,WAVE,SWELL,WEATHER,CLOUDS,VISIBILITY};
	enum fieldsMotor{ MOTOR,MOTORT,MOTOR1,MOTOR1T,FUEL,FUELT,SAILS,REEF,GENE,GENET,BANK1,BANK1T,BANK2,BANK2T,WATERM,WATERMT,WATERMO,WATER,WATERT,MREMARKS};	

	struct gridc 
	{ 
		int grid; 
		int col;
	};

	map<wxString,gridc> placeholders;
	map<wxString,wxString> placeholdersboat;
	map<wxString,gridc>::iterator its;
	map<wxString,wxString>::iterator it;

	wxString readLayoutFile(wxString layout);
	wxString readLayoutFileODT(wxString layout);
	void setSelection();
	bool checkLayoutError(int result, wxString html, wxString layout);
	wxString replacePlaceholder(wxString html, wxString htmlHeader, int grid, int row, int col, bool mode,wxTextOutputStream &htmlFile);
	wxString replaceNewLine(wxString s, bool mode, bool label);
	int setTableValues(bool mode, int index, int row, wxString html, wxTextOutputStream &d); 

	LogbookDialog *parent;
	Logbook		  *logbook;
	wxString data_locn;
	wxString layout_locn;
	wxString fileName;

	wxString route;
};
