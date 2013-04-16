#ifndef _LOGOPTIONS_H_
#define _LOGOPTIONS_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include <wx/dynarray.h> 

WX_DEFINE_ARRAY_INT(int, ArrayOfNavGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfWeatherGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfMotorGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfCrewGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfWakeGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfEquipGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfOverviewGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfServiceGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfRepairsGridColWidth);
WX_DEFINE_ARRAY_INT(int, ArrayOfBuyPartsGridColWidth);

class Options
{
public:
	Options(void);
	~Options(void);

	bool checkStateOfEvents();
	void stopAllEvents();
	void setTimeFormat(int i);
	void setOptionsTimeFormat();
	void setDateFormat();

	// Global Options
	bool		firstTime;
	int			dlgWidth;
	int			dlgHeight;
	bool		popup;
	bool		hourFormat;
	bool		statusbarGlobal;
	bool		layoutShow;
	bool		statusbarWatch;
	int			engines;
	bool		toggleEngine1;
	bool		toggleEngine2;
	wxArrayString abrSails;
	wxArrayString sailsName;
	bool		bSailIsChecked[14];
	wxDateTime	dtEngine1On;
	wxDateTime	dtEngine2On;

	wxString    layoutPrefix;
	bool		filterLayout;
	bool		showAllLayouts;
	bool		noGPS;
	bool		colouredMaintenance;
	bool		guardChange;
	wxString	guardChangeText;
	bool		waypointArrived;
	wxString	waypointText;
	bool		courseChange;
	wxString	courseChangeDegrees;
	double		dCourseChangeDegrees;
	wxString	courseTextAfterMinutes;
	wxString    courseChangeText;
	bool		everySM;
	wxString	everySMAmount;
	double		dEverySM;
	wxString    everySMText;

	bool		traditional;
	bool		modern;
	bool		showToolTips;
	// Timer 
	bool		timer;
	int         timerType;
	wxString	thour;
	wxString	tmin;
	wxString	tsec;
	wxString	ttext;
	long		timerSec;
	
	// Grid Navigation
	wxString	Deg;
	wxString	Min;
	wxString	Sec;

	wxString	distance;
	wxString	speed;

	wxString	meter;
	wxString	feet;
	wxString	fathom;

	// Grid Weather
	wxString	baro;
	wxString    temperature;
	wxString	windkts;
	wxString	windmeter;
	wxString	windkmh;

	// Grid MotorSails
	wxString	vol;
	wxString	motorh;
	wxString    engine;
	wxString	shaft;
	wxString	rpm;

	//Maintenance
	wxString	days;
	wxString	weeks;
	wxString	month;

	//Paths 
	wxString    htmlEditor;
	wxString   	odtEditor;
	wxString    mailClient;
	wxString   	dataManager;

	wxString    htmlEditorReset;
	wxString    odtEditorReset;
	wxString    mailClientReset;
	wxString    dataManagerReset;

	//Capacity
	wxString	fuelTank;
	wxString	waterTank;
	wxString	watermaker;
	wxString	bank1;
	wxString    bank2;
	wxString    ampere;
	wxString    ampereh;

	// KML
	int			kmlRoute;
	int			kmlTrack;
	wxString	kmlLineWidth;
	int			kmlLineTransparancy;
	int			kmlRouteColor;
	int			kmlTrackColor;
	wxArrayString kmlColor;
	wxArrayString kmlTrans;

	//NMEA
	bool		bRPMIsChecked;
	wxString	sentence;
	wxString	engine1;
	wxString	engine2;
	bool		engine1Running;
	bool		engine2Running;
	bool		bRPMCheck;
	bool		NMEAUseERRPM;
	bool		NMEAUseWIMDA;

	//wxChoice
	int		showDepth;
	int		showWaveSwell;
	int		showWindSpeed;
	int		showWindDir;
	int		showWindHeading;
	int		showHeading;
	
	bool 		navHTML;
	bool		crewHTML;
	bool		boatHTML;
	bool		overviewHTML;
	bool		serviceHTML;
	bool		repairsHTML;
	bool		buypartsHTML;
	int         overviewAll;

	int		navGridLayoutChoice;
	int		crewGridLayoutChoice;
	int		boatGridLayoutChoice;
	int		overviewGridLayoutChoice;
	int		serviceGridLayoutChoice;
	int		repairsGridLayoutChoice;
	int		buypartsGridLayoutChoice;
	
	int		navGridLayoutChoiceODT;
	int		crewGridLayoutChoiceODT;
	int		boatGridLayoutChoiceODT;
	int		overviewGridLayoutChoiceODT;
	int		serviceGridLayoutChoiceODT;
	int		repairsGridLayoutChoiceODT;
	int		buypartsGridLayoutChoiceODT;	

	bool	local;
	bool	UTC;
	bool	gpsAuto;
	int		tzIndicator;
	int		tzHour;

	int 	  timeformat;
	bool	  noseconds;
	int       dateformat;
	wxString  dateseparatorlocale;
	wxString  dateseparatorindiv;
	wxString  sdateformat;
	wxString  stimeformat;
	wxString  stimeformatw;
	int		  date1;
	int       date2;
	int       date3;

	ArrayOfNavGridColWidth		NavColWidth;
	ArrayOfWeatherGridColWidth	WeatherColWidth;
	ArrayOfMotorGridColWidth	MotorColWidth;
	ArrayOfCrewGridColWidth		CrewColWidth;
	ArrayOfWakeGridColWidth		WakeColWidth;
	ArrayOfEquipGridColWidth	EquipColWidth;
	ArrayOfOverviewGridColWidth OverviewColWidth;
	ArrayOfOverviewGridColWidth ServiceColWidth;
	ArrayOfOverviewGridColWidth RepairsColWidth;
	ArrayOfOverviewGridColWidth BuyPartsColWidth;

	int stateEvents;
};
#endif