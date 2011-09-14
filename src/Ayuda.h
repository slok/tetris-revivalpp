#ifndef AYUDA_H
#define AYUDA_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(Ayuda)
	#include <wx/sizer.h>
	#include <wx/panel.h>
	#include <wx/choice.h>
	#include <wx/statbmp.h>
	#include <wx/dialog.h>
	//*)
#endif
//(*Headers(Ayuda)
//*)

class Ayuda: public wxDialog
{
	public:

		Ayuda(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Ayuda();

		//(*Declarations(Ayuda)
		wxStaticBitmap* StaticBitmap1;
		wxPanel* Panel1;
		wxChoice* Choice1;
		//*)

	protected:

		//(*Identifiers(Ayuda)
		static const long ID_STATICBITMAP1;
		static const long ID_CHOICE1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(Ayuda)
		void OnChoice1Select(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
