/***************************************************************
 * Name:      Tetris_Revival___v0_1Main.h
 * Purpose:   Defines Application Frame
 * Author:    Lazarox, greyFox, sLoK ()
 * Created:   2008-05-17
 * Copyright: Lazarox, greyFox, sLoK ()
 * License:
 **************************************************************/

#ifndef TETRIS_REVIVAL___V0_1MAIN_H
#define TETRIS_REVIVAL___V0_1MAIN_H

//(*Headers(Tetris_Revival___v0_1Frame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)
#include "main.h"

class Tetris_Revival___v0_1Frame: public wxFrame
{
    public:

        Tetris_Revival___v0_1Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Tetris_Revival___v0_1Frame();

    private:

        //(*Handlers(Tetris_Revival___v0_1Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(Tetris_Revival___v0_1Frame)
        static const long ID_STATICBITMAP1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Tetris_Revival___v0_1Frame)
        wxButton* Button1;
        wxStaticBitmap* StaticBitmap1;
        wxPanel* Panel1;
        wxButton* Button2;
        wxButton* Button3;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TETRIS_REVIVAL___V0_1MAIN_H
