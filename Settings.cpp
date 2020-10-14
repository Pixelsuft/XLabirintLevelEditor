//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "main.h"
#include "Settings.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSets *Sets;
//---------------------------------------------------------------------------
__fastcall TSets::TSets(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSets::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;        
}
//---------------------------------------------------------------------------
void __fastcall TSets::HelpClick(TObject *Sender)
{
        Application->MessageBox("Управление\n     WASD - размер фигуры\n     Стрел0чки - положение\n Shift (или shit) - ускорение передвижения\n     Ctrl - замедлить передвижение","Коля лох!", MB_ICONINFORMATION);        
}
//---------------------------------------------------------------------------

void __fastcall TSets::UpdateClick(TObject *Sender)
{
        MainForm->Update->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TSets::UpdParamsClick(TObject *Sender)
{
        MainForm->UpdateSets->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TSets::VisibledClick(TObject *Sender)
{
        MainForm->Vis->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TSets::SaveClick(TObject *Sender)
{
        Data->Lines->Strings[2]="Speed";
        Data->Lines->Strings[3]=Speed->Text;
        Data->Lines->Strings[4]="Red";
        Data->Lines->Strings[5]=MainForm->Red->Left;
        Data->Lines->Strings[6]=MainForm->Red->Top;
        Data->Lines->Strings[7]=MainForm->Red->Width;
        Data->Lines->Strings[8]=MainForm->Red->Height;
        Data->Lines->Strings[9]="Green";
        Data->Lines->Strings[10]=MainForm->Green->Left;
        Data->Lines->Strings[11]=MainForm->Green->Top;
        Data->Lines->Strings[12]=MainForm->Green->Width;
        Data->Lines->Strings[13]=MainForm->Green->Height;
        Data->Lines->Strings[14]="Win";
        Data->Lines->Strings[15]=MainForm->Win->Left;
        Data->Lines->Strings[16]=MainForm->Win->Top;
        Data->Lines->Strings[17]=MainForm->Win->Width;
        Data->Lines->Strings[18]=MainForm->Win->Height;
        MainForm->Saver->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TSets::LoadClick(TObject *Sender)
{
        if(OpenSave->Execute())
        {
                Data->Lines->LoadFromFile(OpenSave->FileName);
                Speed->Text=StrToInt(Data->Lines->Strings[3]);
                MainForm->Red->Left=StrToInt(Data->Lines->Strings[5]);
                MainForm->Red->Top=StrToInt(Data->Lines->Strings[6]);
                MainForm->Red->Width=StrToInt(Data->Lines->Strings[7]);
                MainForm->Red->Height=StrToInt(Data->Lines->Strings[8]);
                MainForm->Green->Left=StrToInt(Data->Lines->Strings[10]);
                MainForm->Green->Top=StrToInt(Data->Lines->Strings[11]);
                MainForm->Green->Width=StrToInt(Data->Lines->Strings[12]);
                MainForm->Green->Height=StrToInt(Data->Lines->Strings[13]);
                MainForm->Win->Left=StrToInt(Data->Lines->Strings[15]);
                MainForm->Win->Top=StrToInt(Data->Lines->Strings[16]);
                MainForm->Win->Width=StrToInt(Data->Lines->Strings[17]);
                MainForm->Win->Height=StrToInt(Data->Lines->Strings[18]);
                MainForm->Loader->Enabled=true;
        }
}
//---------------------------------------------------------------------------

