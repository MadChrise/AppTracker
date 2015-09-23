#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "TApp.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

TApp::TApp()
{
	this->m_bNew = true;
}
//---------------------------------------------------------------------------

TApp::TApp(int nID, int nAppTypeID, String strAppname, String strProcessname)
	: m_nID(nID),
	m_nAppTypeID(nAppTypeID),
	m_strAppname(strAppname),
	m_strProcessname(strProcessname)
{

}
//---------------------------------------------------------------------------

TApp::TApp(const TApp &app)
	: m_nID(app.m_nID),
	m_nAppTypeID(app.m_nAppTypeID),
	m_strAppname(app.m_strAppname),
	m_strProcessname(app.m_strProcessname)
{

}
//---------------------------------------------------------------------------

TApp::~TApp()
{
}
//---------------------------------------------------------------------------
