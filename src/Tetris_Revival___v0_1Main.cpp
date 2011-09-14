/***************************************************************
 * Name:      Tetris_Revival___v0_1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Lazarox, greyFox, sLoK ()
 * Created:   2008-05-17
 * Copyright: Lazarox, greyFox, sLoK ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Tetris_Revival___v0_1Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Tetris_Revival___v0_1Frame)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

#include "Ayuda.h"

//(*IdInit(Tetris_Revival___v0_1Frame)
const long Tetris_Revival___v0_1Frame::ID_STATICBITMAP1 = wxNewId();
const long Tetris_Revival___v0_1Frame::ID_BUTTON1 = wxNewId();
const long Tetris_Revival___v0_1Frame::ID_BUTTON2 = wxNewId();
const long Tetris_Revival___v0_1Frame::ID_BUTTON3 = wxNewId();
const long Tetris_Revival___v0_1Frame::ID_PANEL1 = wxNewId();
const long Tetris_Revival___v0_1Frame::idMenuQuit = wxNewId();
const long Tetris_Revival___v0_1Frame::idMenuAbout = wxNewId();
const long Tetris_Revival___v0_1Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Tetris_Revival___v0_1Frame,wxFrame)
    //(*EventTable(Tetris_Revival___v0_1Frame)
    //*)
END_EVENT_TABLE()

Tetris_Revival___v0_1Frame::Tetris_Revival___v0_1Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Tetris_Revival___v0_1Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, id, "Tetris Revival++ V0.1", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(270,271), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("data/imagenes/splash.png"))), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    BoxSizer2->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Jugar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(Button1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Ayuda"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer3->Add(Button2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Ni de coña"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer3->Add(Button3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxSHAPED|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Salir\tAlt-F4"), _("Salir de esta cosa"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Archivo"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Acerca De...\tF1"), _("Acerca de estos mangarranes..."), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Ayuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Tetris_Revival___v0_1Frame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Tetris_Revival___v0_1Frame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Tetris_Revival___v0_1Frame::OnButton3Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Tetris_Revival___v0_1Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Tetris_Revival___v0_1Frame::OnAbout);
    //*)
}

Tetris_Revival___v0_1Frame::~Tetris_Revival___v0_1Frame()
{
    //(*Destroy(Tetris_Revival___v0_1Frame)
    //*)
}

void Tetris_Revival___v0_1Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Tetris_Revival___v0_1Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Clon del tetris multiplataforma\n - Jon Lazaro Aduna\n - Gaizka Rubio Landaluze\n - Xabier Larrakoetxea Gallego";
    wxMessageBox(msg, _("Acerca de..."));
}

void Tetris_Revival___v0_1Frame::OnButton1Click(wxCommandEvent& event)
{
    iniciarTetris();
}

void Tetris_Revival___v0_1Frame::OnButton2Click(wxCommandEvent& event)
{
    Ayuda* frm = new Ayuda(this);
    frm->Show();
}

void Tetris_Revival___v0_1Frame::OnButton3Click(wxCommandEvent& event)
{
    exit(0);
}
