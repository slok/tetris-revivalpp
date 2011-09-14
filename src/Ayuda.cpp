#include "wx_pch.h"
#include "Ayuda.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(Ayuda)
	#include <wx/intl.h>
	#include <wx/string.h>
	//*)
#endif
//(*InternalHeaders(Ayuda)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
//*)

//(*IdInit(Ayuda)
const long Ayuda::ID_STATICBITMAP1 = wxNewId();
const long Ayuda::ID_CHOICE1 = wxNewId();
const long Ayuda::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Ayuda,wxDialog)
	//(*EventTable(Ayuda)
	//*)
END_EVENT_TABLE()

Ayuda::Ayuda(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Ayuda)
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, "Ayuda", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("data/imagenes/ayuda.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
	BoxSizer2->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->Append(_("Teclas"));
	Choice1->Append(_("Puntuacion"));
	Choice1->Append(_("Niveles"));
	wxFont Choice1Font(20,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	Choice1->SetFont(Choice1Font);
	BoxSizer2->Add(Choice1, 1, wxALL|wxEXPAND|wxSHAPED|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel1->SetSizer(BoxSizer2);
	BoxSizer2->Fit(Panel1);
	BoxSizer2->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&Ayuda::OnChoice1Select);
	//*)
}

Ayuda::~Ayuda()
{
	//(*Destroy(Ayuda)
	//*)
}

void Ayuda::OnChoice1Select(wxCommandEvent& event)
{
    wxString opcion="";
    opcion = Choice1->GetStringSelection();

        if (opcion == "Teclas")
        {
            wxString msgTeclas =    "-Flecha arriba: rotar pieza\n\
-Flecha izquierda: mover pieza izquierda\n\
-Flecha derecha: mover pieza derecha\n\
-Flecha abajo: bajar pieza mas rapido\n\n\
-Tecla espacio: baja pieza hasta abajo\n\
-Tecla escape: pausa el juego\n\
-Tecla 'P': pausa la musica\n\
-Tecla 'O': para reanudar la canción\n";
            wxMessageBox(msgTeclas, _("Teclas"));
        }
            else if (opcion == "Puntuacion" )
            {
                wxString msgPunt = "La puntuacion suma por cada linea que se hace, cada linea dependiendo del nivel hara\
mas puntos o menos, ejemplo: 1er Nivel: 10, 2do nivel:20, 3er nivel: 40 y asi sucesivamente";
                wxMessageBox(msgPunt, _("Puntuacion"));
            }
                else if (opcion == "Niveles")
                {
                    wxString msgNivel = "Los nivels aumentan cada 5 filas, y cada 5 niveles el fondo cambia, el juego\
dispone de 10 fondos por lo que tiene 50 niveles, si llegas al nivel 50 (que lo dudamos xD).... SORPRESA";
                    wxMessageBox(msgNivel, _("Niveles"));
                }

}
