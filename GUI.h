///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/graphics.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Frame
///////////////////////////////////////////////////////////////////////////////
class Frame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* panel;
		wxStaticText* text;
		wxButton* check;
		wxButton* random;
		
		// Virtual event handlers, overide them in your derived class
		virtual void panelOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void panelOnMouseEvents( wxMouseEvent& event ) { event.Skip(); }
		virtual void panelOnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void checkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void randomOnButtonClick( wxCommandEvent& event ) { event.Skip(); }

	public:
		Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Tangram"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 850,650 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~Frame();
	
};

#endif //__GUI_H__
